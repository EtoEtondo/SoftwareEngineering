#pragma once

#include "../src/sensor.h"
#include "../src/laterne.h"
#include "../src/laternennetz.h"
#include "../src/laternensteuerung_interface.h"
#include <QObject>
#include <QtTest/QtTest>


class MockLaternensteuerung : public LaternensteuerungBase {

    private:
        bool testwert1 = false;

    public:
        explicit MockLaternensteuerung() {}

        void update(Laternennetz *laternennetz);
        bool get_testwert1() const;

};


class TestIntegrationstest : public QObject {

    Q_OBJECT

    private:
        Sensor *sensor_;
        Laterne *laterne_;
        Laternennetz *laternennetz_;
        MockLaternensteuerung *laternensteuerung_;

    private slots:

        // Executed by QtTest before and after test suite
        void initTestCase() {}
        void cleanupTestCase() {}

        // Executed by QtTest before and after each test
        void init();
        void cleanup();

        // Test
        void test();

};
