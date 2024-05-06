#pragma once

#include "sensor_interface.h"
#include "laterne_interface.h"
#include "laterne.h"


class LaterneBase;
class Laterne;


class Sensor : public SensorBase {

    private:
        LaterneBase *laterne;
        int posX;
        int posY;
        bool auto_erkannt;

	public:
        Sensor();

        Laterne* get_laterne();
        void set_laterne(LaterneBase* laterne);

        bool get_auto_erkannt() const;
        void set_auto_erkannt(bool auto_erkannt);

        int get_posX() const;
        int get_posY() const;
        void set_pos(int posX, int posY);

        void auto_wurde_erkannt();

};
