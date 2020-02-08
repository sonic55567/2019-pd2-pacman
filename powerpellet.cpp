#include "powerpellet.h"

PowerPellet::PowerPellet(QObject *parent) : QObject(parent)
{
    powerpellet.load(":/new/prefix1/pellet.png");
    clear.load(":/new/prefix1/clear.png");
    powerpellet = powerpellet.scaled(16,16);
    clear = clear.scaled(16,16);
    status = "alive";

    this->setPixmap(powerpellet);
}

void PowerPellet::eaten()
{
    this->setPos(0,0);
    this->setPixmap(clear);
    this->status = "eaten";
}
