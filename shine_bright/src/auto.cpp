#include "auto.h"
#include <QDebug>


namespace logic {


Auto::Auto(int geschwindigkeit, int posX, int posY) : QObject(nullptr), posX(posX), posY(posY) {
    if(geschwindigkeit >= 0) this->geschwindigkeit = geschwindigkeit;
    alte_posX = posX;
    alte_posY = posY;
    qDebug() << "Auto wurde erstellt." << endl;
}


int Auto::get_posY() const {
    return posY;
}


int Auto::get_posX() const {
    return posX;
}


int Auto::get_old_posX() const {
    return alte_posX;
}


int Auto::get_old_posY() const {
    return alte_posY;
}


void Auto::set_pos(int posX, int posY) {
    this->alte_posX = this->posX;
    this->alte_posY = this->posY;
    this->posX = posX;
    this->posY = posY;
    qDebug() << "AutoPos(x:y) > " << this->posX << ":" << this->posY << endl;
    update();
}


int Auto::get_geschwindigkeit() const {
    return this->geschwindigkeit;
}


void Auto::set_geschwindigkeit(int geschwindigkeit) {
    if(geschwindigkeit >= 0) this->geschwindigkeit = geschwindigkeit;
}


void Auto::move_right() {
    set_pos(this->posX + this->geschwindigkeit, this->posY);
}


void Auto::move_left() {
    set_pos(this->posX - this->geschwindigkeit, this->posY);
}


void Auto::move_up() {
    set_pos(this->posX, this->posY - this->geschwindigkeit);
}


void Auto::move_down() {
    set_pos(this->posX, this->posY + this->geschwindigkeit);
}


void Auto::update() {
    emit positionChanged(this->posX, this->posY);
}


} // Ende Logik
