#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QDir>
#include <QMediaPlayer>


enum {Links = 1, Rechts = 2, Oben = 3, Unten = 4, Andere = 5};


class MovingShape;


namespace Ui {

    class MainWindow;

}


class MainWindow : public QMainWindow {

    Q_OBJECT

    private:
       Ui::MainWindow *ui;
       QLabel *car;
       QMediaPlayer *musik;
       std::vector<QLabel*> laternen_widgets;
       QPixmap on;
       QPixmap off;

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void set_widget(int posX, int posY, unsigned int ID);
        void keyPressEvent(QKeyEvent* event);
        void spiele_musik();

    signals:
        void mw_keypressevent(int signal);

    public slots:
        void moveCar(int offsetX, int offsetY);
        void changeblack(unsigned int ID);
        void changeyellow(unsigned int ID);

};

