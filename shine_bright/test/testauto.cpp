#include "testauto.h"


void TestAuto::init() {
    sut_ = new logic::Auto(10, 5, 1);
    QVERIFY(sut_->get_geschwindigkeit() == 10);
    QVERIFY(sut_->get_posY() == 1);
    QVERIFY(sut_->get_posX() == 5);
}


void TestAuto::cleanup() {
	delete sut_;
    sut_ = nullptr;
}


void TestAuto::teste_bewegung1() {

    sut_->set_geschwindigkeit(10);
    sut_->set_pos(0, 0);

    for(int i=0; i < 10; i++){
        sut_->move_left();
        sut_->move_up();
    }

    QVERIFY(sut_->get_posX() == -100);
    QVERIFY(sut_->get_posY() == -100);

}


void TestAuto::teste_bewegung2() {

    sut_->set_geschwindigkeit(5);
    sut_->set_pos(0, 0);

    for(int i=0; i < 10; i++){
        sut_->move_right();
        sut_->move_down();
    }

    QVERIFY(sut_->get_posX() == 50);
    QVERIFY(sut_->get_posY() == 50);

}
