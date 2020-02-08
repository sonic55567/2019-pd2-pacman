#ifndef POWERPELLET_H
#define POWERPELLET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>

class PowerPellet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit PowerPellet(QObject *parent = nullptr);
    void eaten();
    QString status;

private:
    QPixmap powerpellet,clear;

};

#endif // POWERPELLET_H
