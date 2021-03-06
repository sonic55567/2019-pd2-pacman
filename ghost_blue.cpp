#include "ghost_blue.h"
#include "mainwindow.h"

extern MainWindow *w;

blueGhost::blueGhost()
{
    up1.load(":/new/prefix1/ghostupblue1.png");
    up2.load(":/new/prefix1/ghostupblue2.png");
    down1.load(":/new/prefix1/ghostdownblue1.png");
    down2.load(":/new/prefix1/ghostdownblue2.png");
    left1.load(":/new/prefix1/ghostleftblue1.png");
    left2.load(":/new/prefix1/ghostleftblue2.png");
    right1.load(":/new/prefix1/ghostrightblue1.png");
    right2.load(":/new/prefix1/ghostrightblue2.png");
    scare1.load(":/new/prefix1/ghostscaredblue1.png");
    scare2.load(":/new/prefix1/ghostscaredblue2.png");
    up1 = up1.scaled(16,16);
    up2 = up2.scaled(16,16);
    down1 = down1.scaled(16,16);
    down2 = down2.scaled(16,16);
    left1 = left1.scaled(16,16);
    left2 = left2.scaled(16,16);
    right1 = right1.scaled(16,16);
    right2 = right2.scaled(16,16);
    scare1 = scare1.scaled(16,16);
    scare2 = scare2.scaled(16,16);

    this->setPixmap(left1);
    direction = "left";
    this->setType("normal");
}

void blueGhost::move()
{
    QPoint p;
    QPointF pp,ppp;

    // get the target pos

    if(w->pacman->getDirection() == "left"){
        xPos = w->pacman->x()-32;
        yPos = w->pacman->y();
    }
    else if (w->pacman->getDirection() == "right") {
        xPos = w->pacman->x()+32;
        yPos = w->pacman->y();
    }
    else if (w->pacman->getDirection() == "up") {
        xPos = w->pacman->x();
        yPos = w->pacman->y()-32;
    }
    else if (w->pacman->getDirection() == "down") {
        xPos = w->pacman->x();
        yPos = w->pacman->y()+32;
    }
    pp.setX(xPos);
    pp.setY(yPos);

    ppp = pp-w->ghost1->pos();
    ppp = ppp+pp;
    xPos = ppp.x();
    yPos = ppp.y();


    // move method
    if(w->blueGhostMoving == false || (w->isScare2&&w->blueGhostMoving)){
        int i = qrand()%4+1;
        if(i==1){
            next_direction = "left";
        }
        else if (i==2) {
            next_direction = "right";
        }
        else if (i==3) {
            next_direction = "up";
        }
        else {
            next_direction = "down";
        }
    }
    else {
        if(direction=="left" || direction=="right"){
            if(yPos > this->y()){
                next_direction = "down";
            }
            else if(yPos < this->y()){
                next_direction = "up";
            }
        }
        else if (direction=="up" || direction=="down") {
            if(xPos > this->x()){
                next_direction = "right";
            }
            else if (xPos < this->x()) {
                next_direction = "left";
            }
        }
    }

    // turn
    if(next_direction == "left"){
        if(canMove(int(this->x())-1,int(this->y()))){
            direction = "left";
        }
    }
    else if (next_direction == "right") {
        if(canMove(int(this->x())+1,int(this->y()))){
            direction = "right";
        }
    }
    else if (next_direction == "up") {
        if(canMove(int(this->x()),int(this->y())-1)){
            direction = "up";
        }
    }
    else if (next_direction == "down") {
        if(canMove(int(this->x()),int(this->y())+1)){
            direction = "down";
        }
    }

    if(direction == "left"){
        p.setX(int(this->x())-4);
        p.setY(int(this->y()));
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(w->isScare2 == false){
            if(count == 1){
                this->setPixmap(left1);
            }
            else {
                this->setPixmap(left2);
            }
        }
        else{
            if(count == 1){
                this->setPixmap(scare1);
            }
            else {
                this->setPixmap(scare2);
            }
        }
    }
    else if (direction == "right") {
        p.setX(int(this->x())+4);
        p.setY(int(this->y()));
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(w->isScare2 == false){
            if(count == 1){
                this->setPixmap(right1);
            }
            else {
                this->setPixmap(right2);
            }
        }
        else{
            if(count == 1){
                this->setPixmap(scare1);
            }
            else {
                this->setPixmap(scare2);
            }
        }
    }
    else if (direction == "up") {
        p.setX(int(this->x()));
        p.setY(int(this->y())-4);
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(w->isScare2 == false){
            if(count == 1){
                this->setPixmap(up1);
            }
            else {
                this->setPixmap(up2);
            }
        }
        else{
            if(count == 1){
                this->setPixmap(scare1);
            }
            else {
                this->setPixmap(scare2);
            }
        }
    }
    else if (direction == "down") {
        p.setX(int(this->x()));
        p.setY(int(this->y())+4);
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(w->isScare2 == false){
            if(count == 1){
                this->setPixmap(down1);
            }
            else {
                this->setPixmap(down2);
            }
        }
        else{
            if(count == 1){
                this->setPixmap(scare1);
            }
            else {
                this->setPixmap(scare2);
            }
        }
    }

    // cross mid
    if(int(this->x())==-16){
        this->setX(16*28);
    }
    else if(int(this->x())==16*28) {
        this->setX(-16);
    }

    // initialize situation

    p.setX(int(this->x()));
    p.setY(int(this->y()));
    if(!w->pathPoint.contains(p)){
        this->setPos(14*16,100+11*16);
    }


    // count
    if(count == 1){
        count = 2;
    }
    else{
        count = 1;
    }
}

void blueGhost::setType(QString str)
{
    status = str;
}

QString blueGhost::getType()
{
    return status;
}
