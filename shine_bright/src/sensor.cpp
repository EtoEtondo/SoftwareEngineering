#include "sensor.h"
#include <QDebug>


Sensor::Sensor() {
    posX = 0;
    posY = 0;
    auto_erkannt = false;
    qDebug() << "Sensor wurde erstellt." << endl;
}


Laterne* Sensor::get_laterne() {
    return static_cast<Laterne*>(laterne);
}


void Sensor::set_laterne(LaterneBase* laterne) {
    this->laterne = laterne;
}


bool Sensor::get_auto_erkannt() const {
    return auto_erkannt;
}


void Sensor::set_auto_erkannt(bool auto_erkannt) {
    this->auto_erkannt = auto_erkannt;
}


int Sensor::get_posY() const {
    return posY;
}


int Sensor::get_posX() const {
    return posX;
}


void Sensor::set_pos(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}


void Sensor::auto_wurde_erkannt() {
    set_auto_erkannt(true);
    laterne->laternennetz_informieren();
}

