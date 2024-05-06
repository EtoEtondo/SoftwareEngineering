#pragma once

#include "../src/sensor.h"
#include "../src/laterne_interface.h"
#include <QObject>
#include <QtTest/QtTest>


class MockLaterne : public LaterneBase {

    private:
        bool testwert1 = false;

    public:
        explicit MockLaterne() {}

        void laternennetz_informieren();
        bool get_testwert1() const;

};


class TestSensor : public QObject {

    Q_OBJECT

    private:        
        Sensor *sut_;
        MockLaterne *l_;

    public:
        explicit TestSensor(QObject *parent = nullptr) : QObject(parent) {}

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
