#pragma once

#include "../src/auto.h"
#include <QObject>
#include <QtTest/QtTest>


class TestAuto : public QObject {

    Q_OBJECT

    private:
        logic::Auto *sut_;

    public:
        explicit TestAuto(QObject *parent = nullptr) : QObject(parent) {}

    private slots:

        // Executed by QtTest before and after test suite
        void initTestCase() {}
        void cleanupTestCase() {}

        // Executed by QtTest before and after each test
        void init();
        void cleanup();

        // Test
        void teste_bewegung1();
        void teste_bewegung2();

};


