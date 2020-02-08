#include "dot.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

extern MainWindow *w;

Dot::Dot(QObject *parent) : QObject(parent)
{

    smalldot.load(":/new/prefix1/smalldot.png");
    clear.load(":/new/prefix1/clear.png");
    smalldot = smalldot.scaled(16,16);
    clear = clear.scaled(16,16);
    status = "alive";
    this->setPixmap(smalldot);
}

void Dot::eaten()
{
    this->setPos(0,0);
    this->setPixmap(clear);
    this->status = "eaten";
}

void Dot::dotUpdater()
{
    /*if(collidesWithItem(w->pacman)){
        w->score = w->score+10;
        qDebug()<<"score: "<<w->score;
        // do not use delete //
        delete this;
    }*/
}
