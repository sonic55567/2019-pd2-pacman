#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scene = new QGraphicsScene(0,0,ui->board->width()-2,ui->board->height()-2);
    ui->board->setScene(scene);
    ui->board->setBackgroundBrush(QBrush("#000000",Qt::SolidPattern));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMainMenu()
{
    // clean screen
    scene->clear();
    //creat title
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Pacman"));
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    title->setDefaultTextColor("#FFFFFF");
    int txPos = int(this->width())/2 - int(title->boundingRect().width())/2;
    int tyPos = 125;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    // creat play button
    Button *playButton = new Button(QString("Play"));
    playButton->setFontSize(20);
    int bxPos = int(this->width())/2 - int(playButton->boundingRect().width())/2;
    int byPos = 300;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(Game()));
    scene->addItem(playButton);

    // creat quit button
    Button *quitButton = new Button(QString("Quit"));
    quitButton->setFontSize(20);
    int qxPos = int(this->width())/2 - int(quitButton->boundingRect().width())/2;
    int qyPos = 400;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void MainWindow::start()
{
    // clear the screen
    scene->clear();

    QPixmap map;
    map.load(":/new/prefix1/map.png");
    map = map.scaled(448,496,Qt::KeepAspectRatio);

    QGraphicsPixmapItem *pacmanMap = new QGraphicsPixmapItem();
    pacmanMap->setPixmap(map);
    pacmanMap->setPos(0,100);
    scene->addItem(pacmanMap);


    // pacman timer
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updater()));
    timer->start(50);

    // ghost timer
    ghostTimer = new QTimer();
    connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghostUpdater()));
    ghostTimer->start(50);

    // set dots on map
    QPoint p;
    for(int i=0;i<28;++i){
        for(int j=0;j<31;++j){


            if(i==1 || i==26){
                if((j>=1 && j<=8 && j!=3) || (j>=20 && j<=22) || (j>=26 && j<=29)){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==2 || i==10 || i==11 || i==16 || i==17 || i==25 ){
                if(j==1||j==5||j==8||j==20||j==23||j==26||j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==3 || i==24){
                if(j==1||j==5||j==8||j==20||(j>=23&&j<=26)||j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==4 || i==5 || i==22 || i==23){
                if(j==1||j==5||j==8||j==20||j==26||j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==6 || i==21){
                if((j>=1&&j<=26) || j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==7 || i==8 || i==19 || i==20){
                if(j==1 || j==5 || j==20 || j==23 || j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==9 || i==18){
                if(j==1 || (j>=5&&j<=8) || j==20 || (j>=23&&j<=26) || j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==12 || i==15){
                if((j>=1&&j<=5) || j==8 || (j>=20&&j<=23) || (j>=26&&j<=29)){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
            else if(i==13 || i==14){
                if(j==5 || j==29){
                    Dot *dot = new Dot();
                    dot->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(dot);
                    smallballPoint.push_front(p);
                    dotPtr.push_front(dot);
                }
            }
        }
    }

    // set power pellet on map
    for(int i=0;i<28;++i){
        for(int j=0;j<31;++j){
            if(i==1){
                if(j==3 || j==23){
                    PowerPellet *pellet = new PowerPellet();
                    pellet->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(pellet);
                    powerpelletPoint.push_front(p);
                    pelletPtr.push_front(pellet);
                }
            }
            else if(i==26){
                if(j==3 || j==23){
                    PowerPellet *pellet = new PowerPellet();
                    pellet->setPos(16*i,100+16*j);
                    p.setX(16*i);
                    p.setY(100+16*j);
                    scene->addItem(pellet);
                    powerpelletPoint.push_front(p);
                    pelletPtr.push_front(pellet);
                }
            }
        }
    }

    // set the path
    getPacmanPathPoint();

    // score initialize
    score = 0;

    // make ghosts
    ghost1 = new redGhost();
    scene->addItem(ghost1);
    ghost1->setPos(12*16,100+11*16);

    ghost2 = new blueGhost();
    scene->addItem(ghost2);
    ghost2->setPos(13*16,100+14*16);

    ghost3 = new orangeGhost();
    scene->addItem(ghost3);
    ghost3->setPos(14*16,100+14*16);

    ghost4 = new pinkGhost();
    scene->addItem(ghost4);
    ghost4->setPos(15*16,100+14*16);

    redGhostMoving = true;
    blueGhostMoving = true;
    pinkGhostMoving = true;
    orangeGhostMoving = true;

    // scare mode
    scareCounter1 = 0;
    scareCounter2 = 0;
    scareCounter3 = 0;
    scareCounter4 = 0;
    isScare1 = false;
    isScare2 = false;
    isScare3 = false;
    isScare4 = false;

    // creat pacman
    pacman = new Pacman();
    pacman->setPos(13*16,100+23*16);
    scene->addItem(pacman);

    // make pacman focusable
    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    pacman->setFocus();

    // creat GUI
    scoreOnBoard = "Score: " + QString::number(score);
    text = new QGraphicsTextItem(scoreOnBoard);
    scene->addItem(text);
    text->setPos(25,25);
    text->setDefaultTextColor("#FFFFFF");
    text->setFont(QFont("comic sans",25));

}


void MainWindow::getPacmanPathPoint()
{
    /////////
    // row //
    /////////
    addPacmanPathPoint(16*1,100+16*1,16*12,100+16*1);
    addPacmanPathPoint(16*15,100+16*1,16*26,100+16*1);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*5,16*26,100+16*5);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*8,16*6,100+16*8);
    addPacmanPathPoint(16*9,100+16*8,16*12,100+16*8);
    addPacmanPathPoint(16*15,100+16*8,16*18,100+16*8);
    addPacmanPathPoint(16*21,100+16*8,16*26,100+16*8);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*9,100+16*11,16*18,100+16*11);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*-1,100+16*14,16*9,100+16*14);
    addPacmanPathPoint(16*18,100+16*14,16*28,100+16*14);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*9,100+16*17,16*18,100+16*17);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*20,16*12,100+16*20);
    addPacmanPathPoint(16*15,100+16*20,16*26,100+16*20);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*23,16*3,100+16*23);
    addPacmanPathPoint(16*6,100+16*23,16*21,100+16*23);
    addPacmanPathPoint(16*24,100+16*23,16*26,100+16*23);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*26,16*6,100+16*26);
    addPacmanPathPoint(16*9,100+16*26,16*12,100+16*26);
    addPacmanPathPoint(16*15,100+16*26,16*18,100+16*26);
    addPacmanPathPoint(16*21,100+16*26,16*26,100+16*26);
    ////////////////////////////////////////////////////////////
    addPacmanPathPoint(16*1,100+16*29,16*26,100+16*29);

    ////////////
    // column //
    ////////////
    addPacmanPathPoint(16*1,100+16*1,16*1,100+16*8);
    addPacmanPathPoint(16*1,100+16*20,16*1,100+16*23);
    addPacmanPathPoint(16*1,100+16*26,16*1,100+16*29);

    addPacmanPathPoint(16*3,100+16*23,16*3,100+16*26);

    addPacmanPathPoint(16*6,100+16*1,16*6,100+16*26);

    addPacmanPathPoint(16*9,100+16*5,16*9,100+16*8);
    addPacmanPathPoint(16*9,100+16*11,16*9,100+16*20);
    addPacmanPathPoint(16*9,100+16*23,16*9,100+16*26);

    addPacmanPathPoint(16*12,100+16*1,16*12,100+16*5);
    addPacmanPathPoint(16*12,100+16*8,16*12,100+16*11);
    addPacmanPathPoint(16*12,100+16*20,16*12,100+16*23);
    addPacmanPathPoint(16*12,100+16*26,16*12,100+16*29);

    addPacmanPathPoint(16*15,100+16*1,16*15,100+16*5);
    addPacmanPathPoint(16*15,100+16*8,16*15,100+16*11);
    addPacmanPathPoint(16*15,100+16*20,16*15,100+16*23);
    addPacmanPathPoint(16*15,100+16*26,16*15,100+16*29);

    addPacmanPathPoint(16*18,100+16*5,16*18,100+16*8);
    addPacmanPathPoint(16*18,100+16*11,16*18,100+16*20);
    addPacmanPathPoint(16*18,100+16*23,16*18,100+16*26);

    addPacmanPathPoint(16*21,100+16*1,16*21,100+16*26);

    addPacmanPathPoint(16*24,100+16*23,16*24,100+16*26);

    addPacmanPathPoint(16*26,100+16*1,16*26,100+16*8);
    addPacmanPathPoint(16*26,100+16*20,16*26,100+16*23);
    addPacmanPathPoint(16*26,100+16*26,16*26,100+16*29);

}

void MainWindow::addPacmanPathPoint(int x1, int y1, int x2, int y2)
{
    QPoint p;
    if(x1 == x2){
        if(y1 >= y2){
            for(int i=y2;i<=y1;++i){
                p.setX(x1);
                p.setY(i);
                if(pathPoint.contains(p) == false){
                    pathPoint.push_front(p);
                }
            }
        }
        else{
            for(int i=y1;i<=y2;++i){
                p.setX(x1);
                p.setY(i);
                if(pathPoint.contains(p) == false){
                    pathPoint.push_front(p);
                }
            }
        }
    }
    else if (y1 == y2) {
        if(x1 >= x2){
            for(int i=x2;i<=x1;++i){
                p.setX(i);
                p.setY(y1);
                if(pathPoint.contains(p) == false){
                    pathPoint.push_front(p);
                }
            }
        }
        else {
            for(int i=x1;i<=x2;++i){
                p.setX(i);
                p.setY(y1);
                if(pathPoint.contains(p) == false){
                    pathPoint.push_front(p);
                }
            }
        }
    }
}

void MainWindow::eatDot()
{
    for(int i=0;i<dotPtr.size();++i){
        if(pacman->pos()==dotPtr[i]->pos()){
            dotPtr[i]->eaten();
            score = score+10;
            qDebug()<<"score: "<<score;
            break;
        }
    }
}

void MainWindow::eatPowerPellet()
{
    for(int i=0;i<pelletPtr.size();++i){
        if(pacman->collidesWithItem(pelletPtr[i])){
            pelletPtr[i]->eaten();
            score = score+50;
            qDebug()<<"score: "<<score;
            ghostScare();
            break;
        }
    }
}

void MainWindow::eatGhost()
{
    if(pacman->collidesWithItem(ghost1) && ghost1->getType()=="scared"){
        qDebug()<<"eateat";

        score = score+200;
        ghost1->setType("eat");
        isScare1 = false;
    }
    if(pacman->collidesWithItem(ghost2) && ghost2->getType()=="scared"){

        score = score+200;
        ghost2->setType("eat");
        isScare2 = false;
    }
    if(pacman->collidesWithItem(ghost3) && ghost3->getType()=="scared"){

        score = score+200;
        ghost3->setType("eat");
        isScare3 = false;
    }
    if(pacman->collidesWithItem(ghost4) && ghost4->getType()=="scared"){

        score = score+200;
        ghost4->setType("eat");
        isScare4 = false;
    }
}

void MainWindow::isGhostMoving()
{
    if(pos1 == ghost1->pos()){
        redGhostMoving = false;
    }
    else {
        redGhostMoving = true;
    }
    if(pos2 == ghost2->pos()){
        blueGhostMoving = false;
    }
    else {
        blueGhostMoving = true;
    }
    if(pos3 == ghost3->pos()){
        orangeGhostMoving = false;
    }
    else {
        orangeGhostMoving = true;
    }
    if(pos4 == ghost4->pos()){
        pinkGhostMoving = false;
    }
    else {
        pinkGhostMoving = true;
    }
}

void MainWindow::ghostScare()
{
    ghostTimer->start(200);
    scareCounter1 = 1;
    scareCounter2 = 1;
    scareCounter3 = 1;
    scareCounter4 = 1;
    ghost1->setType("scared");
    ghost2->setType("scared");
    ghost3->setType("scared");
    ghost4->setType("scared");
    isScare1 = true;
    isScare2 = true;
    isScare3 = true;
    isScare4 = true;

}

void MainWindow::gameover()
{
    if(pacman->collidesWithItem(ghost1) && ghost1->getType()=="normal"){
        timer->start(150);
        ghostTimer->stop();
        pacman->setDirection("none");
    }
    else if(pacman->collidesWithItem(ghost2) && ghost2->getType()=="normal"){
        timer->start(150);
        ghostTimer->stop();
        pacman->setDirection("none");
    }
    else if (pacman->collidesWithItem(ghost3) && ghost3->getType()=="normal") {
        timer->start(150);
        ghostTimer->stop();
        pacman->setDirection("none");
    }
    else if (pacman->collidesWithItem(ghost4) && ghost4->getType()=="normal") {
        timer->start(150);
        ghostTimer->stop();
        pacman->setDirection("none");
    }
}

void MainWindow::updateScoreBoard()
{
    scoreOnBoard = "Score: " + QString::number(score);
    text->setPlainText(scoreOnBoard);
}

void MainWindow::wingame()
{
    int flag = 0;
    for(int i=0;i<dotPtr.size();++i){
        if(dotPtr[i]->status != "eaten"){
            ++flag;
        }
    }
    for(int i=0;i<pelletPtr.size();++i){
        if(pelletPtr[i]->status != "eaten"){
            ++flag;
        }
    }
    if(flag==0){
        gameOver("You Win!!");
    }
}

void MainWindow::drawMessageBoard(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem *panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void MainWindow::gameOver(QString winMessage)
{
    displayGameOverWindow(winMessage);
}

void MainWindow::displayGameOverWindow(QString message)
{
    // disable all scene items
    for(int i=0;i<scene->items().size();++i){
        scene->items()[i]->setEnabled(false);
    }

    // pop up the message
    drawMessageBoard(0,0,int(scene->width()),int(scene->height()),Qt::gray,0.35);

    // creat the button
    /*Button *playAgain = new Button(QString("Play Again"));
    playAgain->setFontSize(20);
    playAgain->setPos(this->width()/2-playAgain->boundingRect().width()/2,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    Button *menu = new Button(QString("Back to Menu"));
    menu->setFontSize(20);
    menu->setPos(this->width()/2-menu->boundingRect().width()/2,400);
    scene->addItem(menu);
    connect(menu,SIGNAL(clicked()),this,SLOT(restartMenu()));*/

    Button *quit = new Button(QString("Quit"));
    quit->setFontSize(20);
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,350);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // creat the message
    QGraphicsTextItem *title = new QGraphicsTextItem(message);
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    title->setPos(this->width()/2 - title->boundingRect().width()/2,125);
    scene->addItem(title);

}


void MainWindow::updater()
{
    if(pacman->getDirection()!="none"){
       pacman->move();
    }
    else{
        pacman->die();
    }

    eatDot();
    eatPowerPellet();
    eatGhost();
    updateScoreBoard();
    wingame();
    gameover();
}

void MainWindow::ghostUpdater()
{
    pos1 = ghost1->pos();
    pos2 = ghost2->pos();
    pos3 = ghost3->pos();
    pos4 = ghost4->pos();
    if(isScare1){
        ++scareCounter1;
    }
    if(isScare2){
        ++scareCounter2;
    }
    if(isScare3){
        ++scareCounter3;
    }
    if(isScare4){
        ++scareCounter4;
    }
    if(scareCounter1==0 && scareCounter2==0 && scareCounter3==0 && scareCounter4==0){
        ghostTimer->start(50);
    }
    if(scareCounter1>40){
        scareCounter1 = 0;
        isScare1 = false;
        ghost1->setType("normal");
    }
    if(scareCounter2>40){
        scareCounter2 = 0;
        isScare2 = false;
        ghost2->setType("normal");
    }
    if(scareCounter3>40){
        scareCounter3 = 0;
        isScare3 = false;
        ghost3->setType("normal");
    }
    if(scareCounter4>40){
        scareCounter4 = 0;
        isScare4 = false;
        ghost4->setType("normal");
    }

    if(ghost1->getType()!="eat"){
        ghost1->move();
    }
    else {
        scareCounter1 = 0;
        ghost1->moveToBeginningPos();
    }

    if(ghost2->getType()!="eat"){
        ghost2->move();
    }
    else {
        scareCounter2 = 0;
        ghost2->moveToBeginningPos();
    }

    if(ghost3->getType()!="eat"){
        ghost3->move();
    }
    else {
        scareCounter3 = 0;
        ghost3->moveToBeginningPos();
    }

    if(ghost4->getType()!="eat"){
        ghost4->move();
    }
    else {
        scareCounter4 = 0;
        ghost4->moveToBeginningPos();
    }

    isGhostMoving();

}

void MainWindow::Game()
{
    start();
}

void MainWindow::restartGame()
{
    Game();
}

void MainWindow::restartMenu()
{
    displayMainMenu();
}
