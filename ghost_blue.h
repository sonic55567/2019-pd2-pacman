#ifndef GHOST_BLUE_H
#define GHOST_BLUE_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include "ghost_red.h"

class blueGhost : public redGhost
{
    Q_OBJECT
public:
    explicit blueGhost();
    virtual void move();
    virtual void setType(QString);
    virtual QString getType();

private:
    QPixmap up1,up2,down1,down2,left1,left2,right1,right2;
    QPixmap scare1,scare2;
    QString direction,next_direction;
    int count = 1;
    double xPos,yPos;
    QString status;
};

#endif // GHOST_BLUE_H
