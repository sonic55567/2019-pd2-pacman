#ifndef GHOST_RED_H
#define GHOST_RED_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

class redGhost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit redGhost(QObject *parent = nullptr);
    virtual void move();
    virtual void setType(QString);
    virtual QString getType();
    void moveToBeginningPos();
    bool canMove(int,int);

private:
    QPixmap up1,up2,down1,down2,left1,left2,right1,right2;
    QPixmap scare1,scare2;
    QString direction,next_direction;
    int count = 1;
    double xPos,yPos;
    QString status;
};

#endif // GHOST_RED_H
