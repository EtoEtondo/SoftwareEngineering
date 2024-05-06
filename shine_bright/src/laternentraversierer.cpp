#include "laternentraversierer.h"
#include <QDebug>


Laternentraversierer::Laternentraversierer() {
    aktuelles_laternennetz = nullptr;
    rueckwaerts = false;
    qDebug() << "Laternentraversierer wurde erstellt." << endl;
}


Laternennetz* Laternentraversierer::get_laternennetz() {
    return aktuelles_laternennetz;
}


void Laternentraversierer::set_laternennetz(Laternennetz *neues_laternennetz) {
    this->aktuelles_laternennetz = neues_laternennetz;
}


bool Laternentraversierer::ist_rueckwaerts() {
    return rueckwaerts;
}


void Laternentraversierer::richtung_wechseln() {
    rueckwaerts = !rueckwaerts;
}


/* Diese Hilfsfunktionen sind unabhängig von der Traversierungsrichtung des Laternentraversierers */
void laternen_an_kreuzung_einschalten_fall1(Laternennetz *ln) {

    Laternennetz *ln_r = ln->get_rechte_laternennetz();
    Laternennetz *ln_l = ln->get_linke_laternennetz();

    if(ln_r) {
        if(ln_r->get_naechste_laternennetz() &&
           ln_r->get_vorherige_laternennetz()   ) {
            if(!ln_r->get_naechste_laternennetz()->ist_kreuzung())
                ln_r->get_naechste_laternennetz()->laterne_einschalten();
            else ln_r->get_vorherige_laternennetz()->laterne_einschalten();
        }
    }

    if(ln_l) {
        if(ln_l->get_naechste_laternennetz() &&
           ln_l->get_vorherige_laternennetz()   ) {
            if(!ln_l->get_naechste_laternennetz()->ist_kreuzung())
                ln_l->get_naechste_laternennetz()->laterne_einschalten();
            else ln_l->get_vorherige_laternennetz()->laterne_einschalten();
        }
    }

}


void laternen_an_kreuzung_einschalten_fall2(Laternennetz *ln) {

    Laternennetz *ln_r = ln->get_rechte_laternennetz();
    Laternennetz *ln_l = ln->get_linke_laternennetz();

    if(ln_r) ln_r->laterne_einschalten();
    if(ln_l) ln_l->laterne_einschalten();

}


void Laternentraversierer::laternen_einschalten(Laternennetz* ln) {

    Laternennetz *naechste_ln;
    Laternennetz *uebernaechste_ln;

    if(ln == nullptr) return;
    ln->laterne_einschalten();

    if(ist_rueckwaerts()) {
        naechste_ln = ln->get_vorherige_laternennetz();
        if(naechste_ln) {
            naechste_ln->laterne_einschalten();
            uebernaechste_ln = naechste_ln->get_vorherige_laternennetz();
            if(uebernaechste_ln) {
                uebernaechste_ln->laterne_einschalten();
                if(!uebernaechste_ln->ist_kreuzung() && naechste_ln->ist_kreuzung())
                    laternen_an_kreuzung_einschalten_fall1(naechste_ln);
                else if(uebernaechste_ln->ist_kreuzung() && naechste_ln->ist_kreuzung())
                    laternen_an_kreuzung_einschalten_fall2(naechste_ln);
            }
        }
    }
    else {
        naechste_ln = ln->get_naechste_laternennetz();
        if(naechste_ln) {
            naechste_ln->laterne_einschalten();
            uebernaechste_ln = naechste_ln->get_naechste_laternennetz();
            if(uebernaechste_ln) {
                uebernaechste_ln->laterne_einschalten();
                if(!uebernaechste_ln->ist_kreuzung() && naechste_ln->ist_kreuzung())
                    laternen_an_kreuzung_einschalten_fall1(naechste_ln);
                else if(uebernaechste_ln->ist_kreuzung() && naechste_ln->ist_kreuzung())
                    laternen_an_kreuzung_einschalten_fall2(naechste_ln);
            }
        }
    }

}


/* Diese Hilfsfunktionen sind unabhängig von der Traversierungsrichtung des Laternentraversierers */
void laternen_an_kreuzung_ausschalten_fall1(Laternennetz *ln) {

    Laternennetz *ln_r = ln->get_rechte_laternennetz();
    Laternennetz *n_ln_r;
    Laternennetz *ln_l = ln->get_linke_laternennetz();
    Laternennetz *n_ln_l;

    if(ln_r) {
        if(ln_r->get_naechste_laternennetz() &&
           ln_r->get_vorherige_laternennetz()   ) {
            if(!ln_r->get_naechste_laternennetz()->ist_kreuzung()) {
                ln_r->get_naechste_laternennetz()->laterne_ausschalten();
                n_ln_r = ln_r->get_naechste_laternennetz()->get_naechste_laternennetz();
                if(n_ln_r) n_ln_r->laterne_ausschalten();
            }
            else {
                ln_r->get_vorherige_laternennetz()->laterne_ausschalten();
                n_ln_r = ln_r->get_vorherige_laternennetz()->get_vorherige_laternennetz();
                if(n_ln_r) n_ln_r->laterne_ausschalten();
            }
        }
    }

    if(ln_l) {
        if(ln_l->get_naechste_laternennetz() &&
           ln_l->get_vorherige_laternennetz()   ) {
            if(!ln_l->get_naechste_laternennetz()->ist_kreuzung()) {
                ln_l->get_naechste_laternennetz()->laterne_ausschalten();
                n_ln_l = ln_l->get_naechste_laternennetz()->get_naechste_laternennetz();
                if(n_ln_l) n_ln_l->laterne_ausschalten();
            }
            else {
                ln_l->get_vorherige_laternennetz()->laterne_ausschalten();
                n_ln_l = ln_l->get_vorherige_laternennetz()->get_vorherige_laternennetz();
                if(n_ln_l) n_ln_l->laterne_ausschalten();
            }
        }
    }

}


void laternen_an_kreuzung_ausschalten_fall2(Laternennetz *ln) {

    Laternennetz *ln_r = ln->get_rechte_laternennetz();
    Laternennetz *ln_l = ln->get_linke_laternennetz();

    if(ln_r) ln_r->laterne_ausschalten();
    if(ln_l) ln_l->laterne_ausschalten();

}


void Laternentraversierer::laternen_ausschalten(Laternennetz* ln) {

    Laternennetz *letzte_ln;
    Laternennetz *vorletzte_ln;

    if(ln == nullptr) return;

    if(!ist_rueckwaerts()) {
        letzte_ln = ln->get_vorherige_laternennetz();
        if(letzte_ln) {
            vorletzte_ln = letzte_ln->get_vorherige_laternennetz();
            if(vorletzte_ln) {
                if(vorletzte_ln->get_vorherige_laternennetz())
                    vorletzte_ln->get_vorherige_laternennetz()->laterne_ausschalten();
                if(vorletzte_ln->ist_kreuzung() && letzte_ln->ist_kreuzung())
                    laternen_an_kreuzung_ausschalten_fall1(vorletzte_ln);
                else if(vorletzte_ln->ist_kreuzung() && !letzte_ln->ist_kreuzung())
                    laternen_an_kreuzung_ausschalten_fall2(vorletzte_ln);
            }
        }
    }
    else {
        letzte_ln = ln->get_naechste_laternennetz();
        if(letzte_ln) {
            vorletzte_ln = letzte_ln->get_naechste_laternennetz();
            if(vorletzte_ln) {
                if(vorletzte_ln->get_naechste_laternennetz())
                    vorletzte_ln->get_naechste_laternennetz()->laterne_ausschalten();
                if(vorletzte_ln->ist_kreuzung() && letzte_ln->ist_kreuzung())
                    laternen_an_kreuzung_ausschalten_fall1(vorletzte_ln);
                else if(vorletzte_ln->ist_kreuzung() && !letzte_ln->ist_kreuzung())
                    laternen_an_kreuzung_ausschalten_fall2(vorletzte_ln);
            }
        }
    }

}


void Laternentraversierer::gehe_zum_naechsten_laternennetz() {
    if(!aktuelles_laternennetz) return;
    if(ist_rueckwaerts() && aktuelles_laternennetz->get_vorherige_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_vorherige_laternennetz();
    else if(aktuelles_laternennetz->get_naechste_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_naechste_laternennetz();
}


void Laternentraversierer::gehe_zum_vorherigen_laternennetz() {
    if(!aktuelles_laternennetz) return;
    if(ist_rueckwaerts() && aktuelles_laternennetz->get_naechste_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_naechste_laternennetz();
    else if(aktuelles_laternennetz->get_vorherige_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_vorherige_laternennetz();
}


void Laternentraversierer::gehe_zum_rechten_laternennetz() {
    if(!aktuelles_laternennetz) return;
    if(ist_rueckwaerts() && aktuelles_laternennetz->get_linke_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_linke_laternennetz();
    else if(aktuelles_laternennetz->get_rechte_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_rechte_laternennetz();
}


void Laternentraversierer::gehe_zum_linken_laternennetz() {
    if(!aktuelles_laternennetz) return;
    if(ist_rueckwaerts() && aktuelles_laternennetz->get_rechte_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_rechte_laternennetz();
    else if(aktuelles_laternennetz->get_linke_laternennetz())
            aktuelles_laternennetz = aktuelles_laternennetz->get_linke_laternennetz();
}

