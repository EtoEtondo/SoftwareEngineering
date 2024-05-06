#pragma once

#include "laternennetz_interface.h"
#include "laterne.h"
#include "laternensteuerung.h"


class Laterne;
class LaternensteuerungBase;


class Laternennetz : public LaternennetzBase {

    private:
        Laterne *aktuelle;
        LaternensteuerungBase *laternensteuerung;

        Laternennetz *naechste;
        Laternennetz *vorherige;
        Laternennetz *rechte;   // Wenn keine Kreuzung dann NULL
        Laternennetz *linke;    // Wenn keine Kreuzung dann NULL

        bool kreuzung;
        bool strassenende;

        void strassentyp_zuweisung();

    public:
        Laternennetz(LaternensteuerungBase *laternensteuerung);

        Laterne* get_aktuelle_laterne();
        Laternennetz* get_naechste_laternennetz();
        Laternennetz* get_vorherige_laternennetz();
        Laternennetz* get_rechte_laternennetz();
        Laternennetz* get_linke_laternennetz();

        void set_aktuelle_laterne(Laterne *laterne);
        void set_naechste_laternennetz(Laternennetz *laterne);
        void set_vorherige_laternennetz(Laternennetz *laterne);
        void set_rechte_laternennetz(Laternennetz *laterne);
        void set_linke_laternennetz(Laternennetz *laterne);

        void laterne_ausschalten();
        void laterne_einschalten();

        bool ist_kreuzung();
        bool ist_strassenende();

        void laternensteuerung_informieren();

};


