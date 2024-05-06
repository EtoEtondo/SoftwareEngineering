#pragma once


class SensorBase {

    public:
        virtual ~SensorBase() = default;

        virtual bool get_auto_erkannt() const = 0;
        virtual void set_auto_erkannt(bool auto_erkannt) = 0;

        virtual int get_posX() const = 0;
        virtual int get_posY() const = 0;
        virtual void set_pos(int posX, int posY) = 0;

        virtual void auto_wurde_erkannt() = 0;

};
