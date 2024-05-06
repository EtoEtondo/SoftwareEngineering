#pragma once

#include "laterne_interface.h"
#include "laternennetz.h"
#include "sensor.h"
#include <QObject>


class Laternennetz;
class Sensor;


class Laterne : public QObject, public LaterneBase {

    Q_OBJECT

	private:
        Laternennetz *laternennetz;
        Sensor *sensor;

        unsigned int id;
        bool licht_an;

	public:
        Laterne(unsigned int id);

        Laternennetz* get_laternennetz();
        void set_laternennetz(Laternennetz* laternennetz);

        Sensor* get_sensor();
        void set_sensor(Sensor* sensor);

        unsigned int get_id() const;

        bool licht_ist_an() const;
        bool licht_ist_aus() const;

        void licht_einschalten();
        void licht_ausschalten();

        void laternennetz_informieren();

    signals:
        void laterne_geht_an(unsigned int laternen_id);
        void laterne_geht_aus(unsigned int laternen_id);

};
