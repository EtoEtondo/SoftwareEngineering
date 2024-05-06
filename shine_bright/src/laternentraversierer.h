#pragma once

#include "laternentraversierer_interface.h"
#include "laternennetz.h"


class Laternennetz;


class Laternentraversierer : public LaternentraversiererBase {

    private:
        Laternennetz *aktuelles_laternennetz;
        bool rueckwaerts;

    public:
        Laternentraversierer();

        Laternennetz* get_laternennetz();
        void set_laternennetz(Laternennetz *neues_laternennetz);

        bool ist_rueckwaerts();
        void richtung_wechseln();

        void laternen_einschalten(Laternennetz *ln);
        void laternen_ausschalten(Laternennetz *ln);

        void gehe_zum_naechsten_laternennetz();
        void gehe_zum_vorherigen_laternennetz();
        void gehe_zum_rechten_laternennetz();
        void gehe_zum_linken_laternennetz();

};

