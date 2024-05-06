#include "testlaternennetz.h"


void TestLaternennetz::init() {
    lt_ = new Laternentraversierer();
    ls_ = new Laternensteuerung(lt_);
    sut_ = new Laternennetz(ls_);
    QVERIFY(sut_->get_aktuelle_laterne() == nullptr);
    QVERIFY(sut_->get_naechste_laternennetz() == nullptr);
    QVERIFY(sut_->get_vorherige_laternennetz() == nullptr);
    QVERIFY(sut_->get_rechte_laternennetz() == nullptr);
    QVERIFY(sut_->get_linke_laternennetz() == nullptr);
    QVERIFY(sut_->ist_kreuzung() == false);
    QVERIFY(sut_->ist_strassenende() == false);
    sut_->set_aktuelle_laterne(new Laterne(0));
    QVERIFY(sut_->get_aktuelle_laterne() != nullptr);
}


void TestLaternennetz::cleanup() {
    delete sut_->get_aktuelle_laterne();
    delete sut_->get_naechste_laternennetz();
    delete sut_->get_vorherige_laternennetz();
    delete sut_->get_rechte_laternennetz();
    delete sut_->get_linke_laternennetz();
    delete sut_;
    sut_ = nullptr;
}


void TestLaternennetz::test() {

    sut_->set_naechste_laternennetz(new Laternennetz(ls_));
    QVERIFY(sut_->ist_strassenende() == true);
    QVERIFY(sut_->ist_kreuzung() == false);

    sut_->set_vorherige_laternennetz(new Laternennetz(ls_));
    QVERIFY(sut_->ist_strassenende() == false);
    QVERIFY(sut_->ist_kreuzung() == false);

    sut_->set_rechte_laternennetz(new Laternennetz(ls_));
    QVERIFY(sut_->ist_strassenende() == false);
    QVERIFY(sut_->ist_kreuzung() == false);

    sut_->set_linke_laternennetz(new Laternennetz(ls_));
    QVERIFY(sut_->ist_strassenende() == false);
    QVERIFY(sut_->ist_kreuzung() == true);

}
