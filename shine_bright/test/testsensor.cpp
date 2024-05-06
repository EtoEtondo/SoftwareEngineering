#include "testsensor.h"


bool MockLaterne::get_testwert1() const {
    return this->testwert1;
}


void MockLaterne::laternennetz_informieren() {
    this->testwert1 = true;
}


void TestSensor::init() {

    sut_ = new Sensor();
    l_ = new MockLaterne();

    sut_->set_laterne(l_);

    QVERIFY(sut_->get_auto_erkannt() == false);
    QVERIFY(sut_->get_posX() == 0);
    QVERIFY(sut_->get_posY() == 0);

}


void TestSensor::cleanup() {
    delete l_;
    l_ = nullptr;
    delete sut_;
    sut_ = nullptr;   
}


void TestSensor::test() {

    sut_->auto_wurde_erkannt();
    QVERIFY(sut_->get_auto_erkannt() == true);
    QVERIFY(l_->get_testwert1() == true);

    sut_->set_auto_erkannt(false);
    QVERIFY(sut_->get_auto_erkannt() == false);

}
