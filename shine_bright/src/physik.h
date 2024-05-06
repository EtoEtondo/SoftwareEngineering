#pragma once

#include "src/auto.h"
#include "src/laterne.h"
#include "src/sensor.h"
#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPoint>


enum{Links_ = 1, Rechts_ = 2, Oben_ = 3, Unten_ = 4};


using namespace logic;


namespace physics {

class Fahren : public QObject {

    Q_OBJECT

    private:
        double berechne_abstand(Laterne *laterne);

    public:
        Auto *physik_auto;
        std::vector <Laterne*> physik_laternen;
        explicit Fahren();
        void check_abstand_zu_laternen();

    public slots:
        void keyPressEvent_(int signal);

};

} // Ende Physik
