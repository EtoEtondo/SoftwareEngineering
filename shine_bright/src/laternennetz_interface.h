#pragma once


class LaternennetzBase {

    public:
        virtual ~LaternennetzBase() = default;

        virtual void laterne_ausschalten() = 0;
        virtual void laterne_einschalten() = 0;

        virtual bool ist_kreuzung() = 0;
        virtual bool ist_strassenende() = 0;

        virtual void laternensteuerung_informieren()  = 0;

};
