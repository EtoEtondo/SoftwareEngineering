#pragma once

#include "laternennetz.h"


class Laternennetz;


class LaternensteuerungBase {

    public:
        virtual ~LaternensteuerungBase() = default;

        virtual void update(Laternennetz *laternennetz) = 0;

};
