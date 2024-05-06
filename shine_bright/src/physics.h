#pragma once

#include <QObject>

namespace physics {

class Way : public QObject
{
    Q_OBJECT

public:
    explicit Way();

signals:
    void update(int x, int y);

public slots:
    void start();
    void stop();
    void tick();
};

} // end namespace physics


