#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QVector>
#include "pacman.h"
#include "dot.h"
#include "powerpellet.h"
#include "ghost_blue.h"
#include "ghost_orange.h"
#include "ghost_pink.h"
#include "ghost_red.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayMainMenu();
    void start();
    void getPacmanPathPoint();
    void addPacmanPathPoint(int,int,int,int);
    void eatDot();
    void eatPowerPellet();
    void eatGhost();
    void isGhostMoving();
    void ghostScare();
    void gameover();
    void updateScoreBoard();
    void wingame();

    // game over
    void drawMessageBoard(int,int,int,int,QColor,double);
    void gameOver(QString);
    void displayGameOverWindow(QString);


    QGraphicsScene *scene;
    Pacman *pacman;
    redGhost *ghost1;
    redGhost *ghost2;
    redGhost *ghost3;
    redGhost *ghost4;
    QTimer *timer;
    QTimer *ghostTimer;
    QVector<QPoint> pathPoint;
    QVector<QPoint> smallballPoint;
    QVector<QPoint> powerpelletPoint;
    QVector<Dot *> dotPtr;
    QVector<PowerPellet *> pelletPtr;
    int score;
    QPointF pos1,pos2,pos3,pos4;
    bool redGhostMoving,blueGhostMoving,pinkGhostMoving,orangeGhostMoving;
    int scareCounter1,scareCounter2,scareCounter3,scareCounter4;
    bool isScare1,isScare2,isScare3,isScare4;
    QGraphicsTextItem *text;
    QString scoreOnBoard;


private:
    Ui::MainWindow *ui;

public slots:
    void updater();
    void ghostUpdater();
    void Game();
    void restartGame();
    void restartMenu();
};

#endif // MAINWINDOW_H
