#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QPixmap>
#include <QLabel>
#include <QKeyEvent>
#include <QDir>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("shine_bright");

    this->car = findChild<QLabel *>("car");
    qDebug() << "Fenstergroeße ist" << this->width() << "x" << this->height();
    qDebug() << "Autogroeße ist" << this->car->size().width() << "x" << this->car->size().height() << endl;

    this->on = QPixmap (":/on.png");
    this->off = QPixmap (":/off.png");

    musik = new QMediaPlayer(this);

}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::moveCar(int offsetX, int offsetY) {
    this->car->move(offsetX, offsetY);
}


void MainWindow::changeblack(unsigned int ID) {
    laternen_widgets[ID]->setPixmap(this->off);
}


void MainWindow::changeyellow(unsigned int ID) {
    laternen_widgets[ID]->setPixmap(this->on);
}


void MainWindow::set_widget(int posX, int posY, unsigned int ID) {
    //QLabel *laterne = new QLabel;
    laternen_widgets.push_back(new QLabel(this));
    laternen_widgets[ID]->setPixmap(this->off);
    laternen_widgets[ID]->move(posX, posY);
    laternen_widgets[ID]->show();
    qDebug() << "Laternenbild gesetzt:" << posX << ", " << posY << endl;
}


bool lock_musik = true;

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int signal;
    if(lock_musik) {
        spiele_musik();
        lock_musik = false;
    }

    if(event->key() == Qt::Key_Left) {
        signal = Links;
    }
    else if(event->key() == Qt::Key_Right) {
        signal = Rechts;
    }
    else if(event->key() == Qt::Key_Up) {
        signal = Oben;
    }
    else if(event->key() == Qt::Key_Down) {
        signal = Unten;
    }
    else {
        signal = Andere;
    }

    emit mw_keypressevent(signal);
}


void MainWindow::spiele_musik() {
    qDebug()<<QDir::currentPath();
    musik->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/../../../../../shine_bright/data/they_see_me_rollin.mp3"));
    musik->setVolume(50);
    musik->play();
}
