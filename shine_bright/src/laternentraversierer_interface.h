#pragma once

#include "laternennetz.h"


class Laternennetz;


class LaternentraversiererBase {

    public:
        virtual ~LaternentraversiererBase() = default;

        virtual bool ist_rueckwaerts() = 0;
        virtual void richtung_wechseln() = 0;

        virtual void laternen_einschalten(Laternennetz *ln) = 0;
        virtual void laternen_ausschalten(Laternennetz *ln) = 0;

        virtual void gehe_zum_naechsten_laternennetz() = 0;
        virtual void gehe_zum_vorherigen_laternennetz() = 0;
        virtual void gehe_zum_rechten_laternennetz() = 0;
        virtual void gehe_zum_linken_laternennetz() = 0;

};
