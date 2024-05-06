#pragma once

#include "../src/auto.h"
#include "../src/laterne.h"
#include "../src/laternennetz.h"
#include "../src/laternensteuerung.h"
#include "../src/laternentraversierer.h"
#include "../src/sensor.h"
#include "../src/physik.h"
#include <QObject>
#include <QtTest/QtTest>


using namespace std;
using namespace logic;
using namespace physics;


class MockHelper : public QObject {

    Q_OBJECT

    signals:
        void fahr_rechts(int signal);

};


class TestSystemtest : public QObject {

    Q_OBJECT

    private:
        vector<Sensor*> sensoren;
        vector<Laterne*> laternen;
        vector<Laternennetz*> laternennetz;
        Laternentraversierer *laternentraversierer;
        Laternensteuerung *laternensteuerung;
        Auto *car;
        Fahren *drive;
        MockHelper *helper;

    public:
        explicit TestSystemtest(QObject *parent = nullptr) : QObject(parent) {}
        void erstelle_geraden_strassenabschnitt(int anfang_nr, int ende_nr);

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
