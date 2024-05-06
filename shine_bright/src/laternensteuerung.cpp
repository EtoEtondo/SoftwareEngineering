#include "laternensteuerung.h"
#include <QtDebug>



Laternensteuerung::Laternensteuerung(Laternentraversierer *laternentraversierer) {
    this->laternentraversierer = laternentraversierer;
    letzte_laternennetz = nullptr;
    qDebug() << "Laternensteuerung wurde erstellt." << endl;
}


void Laternensteuerung::schalte_naechsten_laternen_ein() {

    laternentraversierer->laternen_einschalten(laternentraversierer->get_laternennetz());

}


void Laternensteuerung::schalte_vorherige_laternen_aus() {

    laternentraversierer->laternen_ausschalten(laternentraversierer->get_laternennetz());

}


void Laternensteuerung::auto_fahrtrichtung_erkennung() {

    Laternennetz *laternennetz = laternentraversierer->get_laternennetz();

    if(laternentraversierer->ist_rueckwaerts()) laternentraversierer->richtung_wechseln();

    qDebug() << "RICHTUNG";

    // Erstes Mal Auto erkannt
    if(laternennetz->ist_strassenende() && letzte_laternennetz == nullptr) {
        if(laternennetz->get_naechste_laternennetz() != nullptr) {
            qDebug() << "vorwaerts" << endl;
            return;
        }
        else {
            laternentraversierer->richtung_wechseln();
            qDebug() << "rueckwaerts" << endl;
            return;
        }
    }

    // Auto kommt am Ende der Strasse an
    if(laternennetz->ist_strassenende() && letzte_laternennetz != nullptr) {
        if(laternennetz->get_naechste_laternennetz() == nullptr) {
            qDebug() << "vorwaerts" << endl;
            return;
        }
        else {
            laternentraversierer->richtung_wechseln();
            qDebug() << "rueckwaerts" << endl;
            return;
        }
    }

    // Gerade Strasse
    if(!(laternennetz->ist_kreuzung()) && !(laternennetz->ist_strassenende())) {
        if(laternennetz->get_vorherige_laternennetz() == letzte_laternennetz) {
            qDebug() << "vorwaerts" << endl;
            return;
        }
        else {
            laternentraversierer->richtung_wechseln();
            qDebug() << "rueckwaerts" << endl;
            return;
        }
    }

    // Kreuzung
    if(laternennetz->ist_kreuzung()) {
        if(!(laternennetz->get_naechste_laternennetz()->ist_kreuzung()) &&
           laternennetz->get_naechste_laternennetz() != letzte_laternennetz ) {
            qDebug() << "vorwaerts" << endl;
            return;
        }
        else if(laternennetz->get_naechste_laternennetz()->ist_kreuzung() &&
           laternennetz->get_vorherige_laternennetz() == letzte_laternennetz ) {
            qDebug() << "vorwaerts" << endl;
            return;
        }
        else {
            laternentraversierer->richtung_wechseln();
            qDebug() << "rueckwaerts" << endl;
            return;
        }
    }

}


void Laternensteuerung::update(Laternennetz *laternennetz) {

    // falls das Auto vom gleichen Sensor hintereinander erkannt wird -> abbrechen
    if(laternennetz == laternentraversierer->get_laternennetz()) return;

    // letzte_laternennetz wird aktualisiert
    // falls das Auto zum ersten mal erkannt wird, um somit den Absturz des Programms zu verhindern
    if(laternentraversierer->get_laternennetz())
        letzte_laternennetz = laternentraversierer->get_laternennetz();
    else letzte_laternennetz = nullptr;

    // laternentraversierer wird aktualisiert
    laternentraversierer->set_laternennetz(laternennetz);

    // Richtung des Autos wird erkannt und dementsprechend werden Lichter an- und ausgeschaltet,
    auto_fahrtrichtung_erkennung();
    schalte_naechsten_laternen_ein();
    schalte_vorherige_laternen_aus();

}
