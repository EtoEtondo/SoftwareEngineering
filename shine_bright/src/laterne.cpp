#include "laterne.h"
#include <QDebug>



Laterne::Laterne(unsigned int id) : QObject(nullptr) {
    this->id = id;
    licht_an = false;
    qDebug() << "Laterne #" <<id<< " wurde erstellt." << endl;
}


Laternennetz* Laterne::get_laternennetz() {
    return laternennetz;
}


void Laterne::set_laternennetz(Laternennetz* laternennetz) {
    this->laternennetz = laternennetz;
}


Sensor* Laterne::get_sensor() {
    return sensor;
}


void Laterne::set_sensor(Sensor* sensor) {
    this->sensor = sensor;
}


unsigned int Laterne::get_id() const {
    return id;
}


bool Laterne::licht_ist_an() const {
    return licht_an;
}


bool Laterne::licht_ist_aus() const {
    return !licht_an;
}


void Laterne::licht_einschalten() {
    qDebug() << "Laterne #" <<id+1<< ": AN == Pos(x:y) > " <<sensor->get_posX()<< ":" <<sensor->get_posY();
    licht_an = true;
    emit laterne_geht_an(this->id);
}


void Laterne::licht_ausschalten() {
    qDebug() << "Laterne #" <<id+1<< ": AUS == Pos(x:y) > " <<sensor->get_posX()<< ":" <<sensor->get_posY();
    licht_an = false;
    emit laterne_geht_aus(this->id);
}


void Laterne::laternennetz_informieren() {
    laternennetz->laternensteuerung_informieren();
}

