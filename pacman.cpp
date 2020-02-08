#include "pacman.h"
#include "mainwindow.h"

extern MainWindow *w;

Pacman::Pacman(QObject *parent) : QObject(parent)
{
    up1.load(":/new/prefix1/pacup1.png");
    up2.load(":/new/prefix1/pacup2.png");
    down1.load(":/new/prefix1/pacdown1.png");
    down2.load(":/new/prefix1/pacdown2.png");
    left1.load(":/new/prefix1/pacleft1.png");
    left2.load(":/new/prefix1/pacleft2.png");
    right1.load(":/new/prefix1/pacright1.png");
    right2.load(":/new/prefix1/pacright2.png");
    round.load(":/new/prefix1/pacround.png");
    up1 = up1.scaled(16,16);
    up2 = up2.scaled(16,16);
    down1 = down1.scaled(16,16);
    down2 = down2.scaled(16,16);
    left1 = left1.scaled(16,16);
    left2 = left2.scaled(16,16);
    right1 = right1.scaled(16,16);
    right2 = right2.scaled(16,16);
    round  = round.scaled(16,16);

    this->setPixmap(left1);
    direction = "left";

}

void Pacman::move()
{
    QPoint p;

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
        p.setX(this->x()-4);
        p.setY(this->y());
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(count == 1){
            this->setPixmap(left1);
        }
        else if (count == 2) {
            this->setPixmap(left2);
        }
        else {
            this->setPixmap(round);
        }
    }
    else if (direction == "right") {
        p.setX(this->x()+4);
        p.setY(this->y());
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(count == 1){
            this->setPixmap(right1);
        }
        else if (count == 2) {
            this->setPixmap(right2);
        }
        else {
            this->setPixmap(round);
        }
    }
    else if (direction == "up") {
        p.setX(this->x());
        p.setY(this->y()-4);
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(count == 1){
            this->setPixmap(up1);
        }
        else if (count == 2) {
            this->setPixmap(up2);
        }
        else {
            this->setPixmap(round);
        }
    }
    else if (direction == "down") {
        p.setX(this->x());
        p.setY(this->y()+4);
        if(w->pathPoint.contains(p)){
            this->setPos(p.x(),p.y());
        }
        else{
            //qDebug()<<"hit wall!";
        }
        if(count == 1){
            this->setPixmap(down1);
        }
        else if (count == 2) {
            this->setPixmap(down2);
        }
        else {
            this->setPixmap(round);
        }
    }

    // cross mid
    if(int(this->x())==-16){
        this->setX(16*28);
    }
    else if(int(this->x())==16*28) {
        this->setX(-16);
    }

    // count
    if(count == 1){
        count = 2;
    }
    else if(count == 2){
        count = 3;
    }
    else{
        count = 1;
    }
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        next_direction = "left";
    }
    else if(event->key()==Qt::Key_Right){
        next_direction = "right";
    }
    else if (event->key()==Qt::Key_Up) {
        next_direction = "up";
    }
    else if (event->key()==Qt::Key_Down) {
        next_direction = "down";
    }
}

bool Pacman::canMove(int x,int y)
{
    for(int i=0;i<w->pathPoint.size();++i){
        if(w->pathPoint[i].x()==x && w->pathPoint[i].y()==y){
            return true;
        }
    }
    return false;
}

void Pacman::die()
{
    direction = "none";
    next_direction = "none";

    die1.load(":/new/prefix1/die1.png");
    die2.load(":/new/prefix1/die2.png");
    die3.load(":/new/prefix1/die3.png");
    die4.load(":/new/prefix1/die4.png");
    die5.load(":/new/prefix1/die5.png");
    die6.load(":/new/prefix1/die6.png");
    die7.load(":/new/prefix1/die7.png");
    die8.load(":/new/prefix1/die8.png");
    die9.load(":/new/prefix1/die9.png");
    die1 = die1.scaled(16,16);
    die2 = die2.scaled(16,16);
    die3 = die3.scaled(16,16);
    die4 = die4.scaled(16,16);
    die5 = die5.scaled(16,16);
    die6 = die6.scaled(16,16);
    die7 = die7.scaled(16,16);
    die8 = die8.scaled(16,16);
    die9 = die9.scaled(16,16);

    if(dieCount==1){
        this->setPixmap(die1);
    }
    else if (dieCount==2) {
        this->setPixmap(die2);
    }
    else if (dieCount==3) {
        this->setPixmap(die3);
    }
    else if (dieCount==4) {
        this->setPixmap(die4);
    }
    else if (dieCount==5) {
        this->setPixmap(die5);
    }
    else if (dieCount==6) {
        this->setPixmap(die6);
    }
    else if (dieCount==7) {
        this->setPixmap(die7);
    }
    else if (dieCount==8) {
        this->setPixmap(die8);
    }
    else if (dieCount==9) {
        this->setPixmap(die9);
    }

    if(dieCount<=9){
        ++dieCount;
    }
    else {
        w->timer->stop();
        w->gameOver("You Lose!!");
    }
}

void Pacman::setDirection(QString str)
{
    next_direction = str;
    direction = str;
}

QString Pacman::getDirection()
{
    return direction;
}
