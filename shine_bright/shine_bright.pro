#-------------------------------------------------
#
# Project Shine Bright for SE2
#
#-------------------------------------------------

QT += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shine_bright
TEMPLATE = app

DESTDIR = dist
OBJECTS_DIR = build

VERSION = 0.1

DEFINES += QT_DEPRECATED_WARNINGS \
        APP_VERSION=\\\"$$VERSION\\\"

CONFIG(debug, debug|release) {
    CONFIG += console
}

SOURCES += \
    src/auto.cpp \
    src/laterne.cpp \
    src/laternensteuerung.cpp \
    src/laternentraversierer.cpp \
    src/laternennetz.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/physik.cpp \
    src/sensor.cpp

HEADERS += \
    src/auto.h \
    src/helper_json.h \
    src/laterne.h \
    src/laterne_interface.h \
    src/laternennetz_interface.h \
    src/laternensteuerung.h \
    src/laternensteuerung_interface.h \
    src/laternentraversierer.h \
    src/laternennetz.h \
    src/laternentraversierer_interface.h \
    src/mainwindow.h \
    src/physik.h \
    src/sensor.h \
    src/sensor_interface.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    data/data.qrc

test {
    message(Test build)

    QT += testlib
    TARGET = shine_bright-test

    SOURCES -= \
        src/main.cpp \
        src/mainwindow.cpp

    SOURCES += \
        test/testauto.cpp \
        test/testsensor.cpp \
        test/testlaternennetz.cpp \
        test/testsystemtest.cpp \
        test/testintegrationstest.cpp \
        test/testmain.cpp

    HEADERS -= \
        src/mainwindow.h

    HEADERS += \
        test/testsensor.h \
        test/testauto.h \
        test/testlaternennetz.h \
        test/testintegrationstest.h \
        test/testsystemtest.h

} else {
    message(Normal build)
}
