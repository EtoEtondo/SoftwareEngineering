#include "testauto.h"
#include "testlaternennetz.h"
#include "testsensor.h"
#include "testsystemtest.h"
#include "testintegrationstest.h"
#include <QApplication>
#include <QtTest/QtTest>


int main(int argc, char **argv) {

    QApplication app(argc, argv);

    TestAuto car;
    TestLaternennetz laternennetz;
    TestSensor sensor;
    TestSystemtest system;
    TestIntegrationstest integration;

    int auto_test = QTest::qExec(&car, argc, argv);
    int laternennetz_test = QTest::qExec(&laternennetz, argc, argv);
    int sensor_test = QTest::qExec(&sensor, argc, argv);
    int system_test = QTest::qExec(&system, argc, argv);
    int integration_test = QTest::qExec(&integration, argc, argv);

    // wenn alle Tests erfolgreich -> return 0
    if(auto_test || sensor_test || laternennetz_test || system_test || integration_test) return 0;
    else return 1;

}
