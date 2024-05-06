#include "auto.h"
#include "laterne.h"
#include "sensor.h"
#include "physik.h"
#include <QDebug>
#include <cmath>


using namespace std;
using namespace logic;


namespace physics {


Fahren::Fahren() : QObject(nullptr) {
    qDebug() << "Physik wurde erstellt." << endl;
}


void Fahren::keyPressEvent_(int signal) {

    qDebug() << "----------------------------" << endl;

    switch(signal) {

        case Links_:
            this->physik_auto->move_left();
            check_abstand_zu_laternen();
            break;

        case Rechts_:
            this->physik_auto->move_right();
            check_abstand_zu_laternen();
            break;

        case Oben_:
            this->physik_auto->move_up();
            check_abstand_zu_laternen();
            break;

        case Unten_:
            this->physik_auto->move_down();
            check_abstand_zu_laternen();
            break;

        default:
            qDebug() << "Keine Pfeiltaste" << endl;
            break;

    }

}


double Fahren::berechne_abstand(Laterne *laterne) {
    int dx = physik_auto->get_posX() - laterne->get_sensor()->get_posX();
    int dy = physik_auto->get_posY() - laterne->get_sensor()->get_posY();
    return sqrt(pow(double(dx), 2) + pow(double(dy), 2));
}


void Fahren::check_abstand_zu_laternen() {
    for(unsigned long i = 0; i < physik_laternen.size(); i++) {
        /* Da zwischen den Sensoren in der GUI ein Abstand von 60 px ist und die "Reichweite"
           der Sensoren sich nicht überschneiden sollen, darf der Radius nicht größer als 30 px
           sein.                                                                                */
        if(berechne_abstand(physik_laternen[i]) < 30) {
            physik_laternen[i]->get_sensor()->auto_wurde_erkannt();
            break;
         }
    }
}


} // Ende Physik
