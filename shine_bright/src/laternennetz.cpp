#include "laternennetz.h"
#include <QDebug>


void Laternennetz::strassentyp_zuweisung() {

    Laternennetz *n = naechste;
    Laternennetz *v = vorherige;
    Laternennetz *r = rechte;
    Laternennetz *l = linke;

    /* Es wird geguckt ob der jetzige "Knoten" im Laternennetz eines der Enden ist. */
    if( (n != nullptr && v == nullptr && r == nullptr && l == nullptr) ||
        (n == nullptr && v != nullptr && r == nullptr && l == nullptr)    )
        strassenende = true;
    else strassenende = false;

    /* Es wird geguckt ob der jetzige "Knoten" im Laternennetz Teil einer Kreuzung ist. */
    if(n != nullptr && v != nullptr && r != nullptr && l != nullptr)
        kreuzung = true;
    else kreuzung = false;

}


Laternennetz::Laternennetz(LaternensteuerungBase *laternensteuerung) {


    aktuelle = nullptr;
    this->laternensteuerung = laternensteuerung;

    naechste = nullptr;
    vorherige = nullptr;
    rechte = nullptr;
    linke = nullptr;

    kreuzung = false;
    strassenende = false;

    qDebug() << "Laternennetz wurde erstellt." << endl;

}


Laterne* Laternennetz::get_aktuelle_laterne() {
    return aktuelle;
}


Laternennetz* Laternennetz::get_naechste_laternennetz() {
    return naechste;
}


Laternennetz* Laternennetz::get_vorherige_laternennetz() {
    return vorherige;
}


Laternennetz* Laternennetz::get_rechte_laternennetz() {
    return rechte;
}


Laternennetz* Laternennetz::get_linke_laternennetz() {
    return linke;
}


void Laternennetz::set_aktuelle_laterne(Laterne *laterne) {
    aktuelle = laterne;
}


void Laternennetz::set_naechste_laternennetz(Laternennetz* laterne) {
    naechste = laterne;
    strassentyp_zuweisung();
}


void Laternennetz::set_vorherige_laternennetz(Laternennetz* laterne) {
    vorherige = laterne;
    strassentyp_zuweisung();
}


void Laternennetz::set_rechte_laternennetz(Laternennetz* laterne) {
    rechte = laterne;
    strassentyp_zuweisung();
}


void Laternennetz::set_linke_laternennetz(Laternennetz* laterne) {
    linke = laterne;
    strassentyp_zuweisung();
}


void Laternennetz::laterne_ausschalten() {
    aktuelle->licht_ausschalten();
}


void Laternennetz::laterne_einschalten() {
    aktuelle->licht_einschalten();
}


bool Laternennetz::ist_kreuzung() {
    return kreuzung;
}


bool Laternennetz::ist_strassenende() {
    return strassenende;
}


void Laternennetz::laternensteuerung_informieren() {
    laternensteuerung->update(this);
}
