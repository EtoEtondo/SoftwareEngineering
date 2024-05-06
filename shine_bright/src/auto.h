#pragma once

#include <QObject>


namespace logic {

class Auto : public QObject {

    Q_OBJECT

	private:
        int geschwindigkeit = 10;
        int posX = 0;
        int posY = 0;
        int alte_posX = 0;
        int alte_posY = 0;

	public:
        explicit Auto(int geschwindigkeit, int posX, int posY);
    
        int get_geschwindigkeit() const;
        void set_geschwindigkeit(int geschwindigkeit);

        int get_posX() const;
        int get_posY() const;
        int get_old_posX() const;
        int get_old_posY() const;
        void set_pos(int posX, int posY);

        void move_right();
        void move_left();
        void move_up();
        void move_down();

    signals:
        void positionChanged(int relativeX, int relativeY);

    public slots:
        void update();

};

} // Ende Logik
