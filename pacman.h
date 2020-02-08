#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

class Pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Pacman(QObject *parent = nullptr);

    //move
    void move();
    void keyPressEvent(QKeyEvent *event);
    bool canMove(int,int);
    void die();
    void setDirection(QString);


    QString getDirection();

signals:

public slots:

private:
    // images
    QPixmap up1,up2,down1,down2,left1,left2,right1,right2,round;
    QPixmap die1,die2,die3,die4,die5,die6,die7,die8,die9;
    QString direction,next_direction;
    int count = 1;
    int dieCount = 1;
};

#endif // PACMAN_H
