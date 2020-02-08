#ifndef DOT_H
#define DOT_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>

class Dot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Dot(QObject *parent = nullptr);
    void eaten();
    QString status;

private:
    QPixmap smalldot,clear;

public slots:
    void dotUpdater();

};

#endif // DOT_H
