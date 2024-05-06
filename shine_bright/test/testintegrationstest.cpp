#include "testintegrationstest.h"


bool MockLaternensteuerung::get_testwert1() const {
    return this->testwert1;
}


void MockLaternensteuerung::update(Laternennetz *laternennetz) {
    this->testwert1 = true;
}


void TestIntegrationstest::init() {

    laterne_ = new Laterne(0);
    sensor_ = new Sensor();
    laterne_->set_sensor(sensor_);
    sensor_->set_laterne(laterne_);

    laternensteuerung_ = new MockLaternensteuerung();
    laternennetz_ = new Laternennetz(laternensteuerung_);
    laternennetz_->set_aktuelle_laterne(laterne_);
    laterne_->set_laternennetz(laternennetz_);

}


void TestIntegrationstest::cleanup() {
    delete laterne_;
    laterne_ = nullptr;
    delete laternennetz_;
    laternennetz_ = nullptr;
    delete laternensteuerung_;
    laternensteuerung_ = nullptr;
}


void TestIntegrationstest::test() {

    laterne_->laternennetz_informieren();
    QVERIFY(laternensteuerung_->get_testwert1());

    laternennetz_->laterne_einschalten();
    QVERIFY(laterne_->licht_ist_an());

    laternennetz_->laterne_ausschalten();
    QVERIFY(laterne_->licht_ist_aus());

}
