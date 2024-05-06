#include "mainwindow.h"
#include "auto.h"
#include "laterne.h"
#include "laternennetz.h"
#include "laternensteuerung.h"
#include "laternentraversierer.h"
#include "notdienst.h"
#include "physik.h"
#include "sensor.h"
#include "helper_json.h"
#include <QApplication>
#include <QSettings>
#include <QCommandLineParser>
#include <QtDebug>
#include <QDir>
#include <QMediaPlayer>
#include <iostream>


#define DEFAULT_CONFIG_FILENAME "default.cfg"
#define DEFAULT_APP_NAME "SE 2 Demo"
#define DEFAULT_APP_VERSION "0.1"

using namespace std;


vector<Sensor*> sensoren;
vector<Laterne*> laternen;
vector<Laternennetz*> laternennetz;
Laternentraversierer *laternentraversierer = new Laternentraversierer();
Laternensteuerung *laternensteuerung = new Laternensteuerung(laternentraversierer);

void laternensystem_init(MainWindow *window);


int main(int argc, char *argv[]) {

    // defaults
    QCoreApplication::setApplicationName(DEFAULT_APP_NAME);
    QCoreApplication::setApplicationVersion(DEFAULT_APP_VERSION);
    QCoreApplication::setOrganizationName(DEFAULT_ORGANISATION);
    QCoreApplication::setOrganizationDomain(DEFAULT_DOMAIN);


    // Parse command line options
    QApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription("Project for the SE2 course");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(app);

    // Init System & GUI
    MainWindow window;
    laternensystem_init(&window);

    // Init Logic
    logic::Auto car(10, 80, 220);
    QObject::connect(&car, &logic::Auto::positionChanged, &window, &MainWindow::moveCar);


    // Init Physics
    physics::Fahren drive;
    drive.physik_auto = &car;
    drive.physik_laternen = laternen;
    QObject::connect(&window, &MainWindow::mw_keypressevent, &drive, &physics::Fahren::keyPressEvent_);
    window.setFocusPolicy(Qt::TabFocus);
    window.setFocus();


    // Go!
    window.show();
    return app.exec();

}


// Hilfsfunktion

void erstelle_geraden_strassenabschnitt(int anfang_nr, int ende_nr) {
    for(int i = anfang_nr-1; i < ende_nr-1; i++) {
        laternennetz[i]->set_naechste_laternennetz(laternennetz[i+1]);
        laternennetz[i+1]->set_vorherige_laternennetz(laternennetz[i]);
    }
}


void erstelle_kreuzung(int haupt_nr, int rechte_nr, int linke_nr) {
    laternennetz[haupt_nr-1]->set_rechte_laternennetz(laternennetz[rechte_nr-1]);
    laternennetz[haupt_nr-1]->set_linke_laternennetz(laternennetz[linke_nr-1]);
    laternennetz[haupt_nr]->set_rechte_laternennetz(laternennetz[rechte_nr-1]);
    laternennetz[haupt_nr]->set_linke_laternennetz(laternennetz[linke_nr-1]);
}


void laternensystem_bauen() {
    erstelle_geraden_strassenabschnitt( 1, 11);
    erstelle_geraden_strassenabschnitt(12, 17);
    erstelle_geraden_strassenabschnitt(18, 23);
    erstelle_kreuzung( 3, 15, 14);
    erstelle_kreuzung(14,  3,  4);
    erstelle_kreuzung( 8, 21, 20);
    erstelle_kreuzung(20,  8,  9);
}


void laternensystem_init(MainWindow *window) {

    // Lesen der JSON-Datei
    QJsonObject json_object = read_json(":/laternenliste.json");
    qDebug() << json_object << endl;
    QStringList keys = json_object.keys();

    for(unsigned int i = 0; i < static_cast<unsigned int>(keys.size()); i++) {

        QJsonValue JsonLaterne = get_json_keys(json_object, i);
        int posX = JsonLaterne["PosX"].toInt();
        int posY = JsonLaterne["PosY"].toInt();

        //setzen der Laternenbilder in die GUI
        window->set_widget(posX, posY, i);
        QCoreApplication::processEvents();

        laternen.push_back(new Laterne(i));
        sensoren.push_back(new Sensor());
        laternen[i]->set_sensor(sensoren[i]);
        sensoren[i]->set_laterne(laternen[i]);
        sensoren[i]->set_pos(posX, posY);
        laternennetz.push_back(new Laternennetz(laternensteuerung));
        laternennetz[i]->set_aktuelle_laterne(laternen[i]);
        laternen[i]->set_laternennetz(laternennetz[i]);

        QObject::connect(laternen[i], &Laterne::laterne_geht_an, window, &MainWindow::changeyellow);
        QObject::connect(laternen[i], &Laterne::laterne_geht_aus, window, &MainWindow::changeblack);
    }

    laternensystem_bauen();

}
