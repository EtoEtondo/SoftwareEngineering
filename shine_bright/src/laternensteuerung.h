#pragma once

#include "laternensteuerung_interface.h"
#include "laternentraversierer.h"
#include "laternennetz.h"


class Laternentraversierer;
class Laternennetz;


class Laternensteuerung : public LaternensteuerungBase {

    private:
        Laternentraversierer *laternentraversierer;
        Laternennetz *letzte_laternennetz;

        void schalte_naechsten_laternen_ein();
        void schalte_vorherige_laternen_aus();

        void auto_fahrtrichtung_erkennung();

    public:
        Laternensteuerung(Laternentraversierer *laternentraversierer);      

        void update(Laternennetz *laternennetz);

};


