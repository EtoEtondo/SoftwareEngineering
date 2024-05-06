#pragma once

#include "../src/laterne.h"
#include "../src/laternennetz.h"
#include "../src/laternentraversierer.h"
#include "../src/laternensteuerung.h"
#include <QObject>
#include <QtTest/QtTest>


class TestLaternennetz : public QObject {

    Q_OBJECT

    private:
        Laternennetz *sut_;
        Laternentraversierer *lt_;
        Laternensteuerung *ls_;

    public:
        explicit TestLaternennetz(QObject *parent = nullptr) : QObject(parent) {}

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


