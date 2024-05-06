#include "testsystemtest.h"
#include <QtTest/QtTest>
#include <QObject>


using namespace std;
using namespace logic;
using namespace physics;


void TestSystemtest::erstelle_geraden_strassenabschnitt(int anfang_nr, int ende_nr) {
    for(int i = anfang_nr-1; i < ende_nr-1; i++) {
        laternennetz[i]->set_naechste_laternennetz(laternennetz[i+1]);
        laternennetz[i+1]->set_vorherige_laternennetz(laternennetz[i]);
    }
}


void TestSystemtest::init() {

    car = new Auto(30, 0, 0);
    drive = new Fahren();
    helper = new MockHelper();
    laternentraversierer = new Laternentraversierer();
    laternensteuerung = new Laternensteuerung(laternentraversierer);

    int posX_sensor = 30;
    int posY_sensor = 10;

    for(unsigned int i = 0; i < 7; i++){
        laternen.push_back(new Laterne(i));
        sensoren.push_back(new Sensor());
        laternen[i]->set_sensor(sensoren[i]);
        sensoren[i]->set_laterne(laternen[i]);
        sensoren[i]->set_pos(posX_sensor, posY_sensor);
        posX_sensor += 60;
        laternennetz.push_back(new Laternennetz(laternensteuerung));
        laternennetz[i]->set_aktuelle_laterne(laternen[i]);
        laternen[i]->set_laternennetz(laternennetz[i]);
    }

    erstelle_geraden_strassenabschnitt(1, 7);

    drive->physik_auto = car;
    drive->physik_laternen = laternen;

    QObject::connect(helper, &MockHelper::fahr_rechts, drive, &physics::Fahren::keyPressEvent_);

}


void TestSystemtest::cleanup() {
    delete helper;
    helper = nullptr;
    delete drive;
    drive = nullptr;
    delete car;
    car = nullptr;
    delete laternensteuerung;
    laternensteuerung = nullptr;
    delete laternentraversierer;
    laternentraversierer = nullptr;
    laternen.clear();
    sensoren.clear();
}


void TestSystemtest::test() {
    int signal = Rechts_;
    for(int i = 0; i < 7; i++) emit helper->fahr_rechts(signal);
    QVERIFY(laternen[0]->licht_ist_aus());
    QVERIFY(laternen[1]->licht_ist_an());
    QVERIFY(laternen[2]->licht_ist_an());
    QVERIFY(laternen[3]->licht_ist_an()); // Auto befindet sich hier
    QVERIFY(laternen[4]->licht_ist_an());
    QVERIFY(laternen[5]->licht_ist_an());
    QVERIFY(laternen[6]->licht_ist_aus());
}
