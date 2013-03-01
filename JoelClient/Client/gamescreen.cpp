#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "entitylabel.h"
#include <QPixmap>

gameScreen::gameScreen(QWidget *parent) :
    QWidget(parent),
    gsui(new Ui::gameScreen)
{
    gsui->setupUi(this);
    //REM
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->start();
    //REM

    wdgtPicture = new QWidget(this);
    wdgtPicture->setGeometry(20,20,4000,3000);
    wdgtPicture->setStyleSheet("background-image:url(:/images/mapsm.png)");
    hero = new EntityLabel(wdgtPicture);
    hero->setGeometry(100,100,36,50);
    //QPixmap icon(":/images/hero1.png");
    //hero->setPixmap(icon);
    hero->setStyleSheet("background:url(:/images/hero1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    hero->show();

}

gameScreen::~gameScreen()
{
    delete gsui;
}

void gameScreen::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        wPressed = true;
        qDebug() << "W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        aPressed = true;
        qDebug() << "A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        sPressed = true;
        qDebug() << "S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        dPressed = true;
        qDebug() << "D";
        //REM
    }
}

void gameScreen::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        wPressed = false;
        qDebug() << "~W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        aPressed = false;
        qDebug() << "~A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        sPressed = false;
        qDebug() << "~S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        dPressed = false;
        qDebug() << "~D";
        //REM
    }
    if(e->key() == Qt::Key_Up)
    {
        //gsui->wdgtPicture->scroll(0, -10);
        wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()+20);
        qDebug()<<"UP";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Left)
    {
        wdgtPicture->move(wdgtPicture->x()+20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(10, 0);
        qDebug()<<"LEFT";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Down)
    {
        wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()-20);
        //gsui->wdgtPicture->scroll(0, 10);
        qDebug()<<"DOWN";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Right)
    {
        wdgtPicture->move(wdgtPicture->x()-20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(-10, 0);
        qDebug()<<"RIGHT";
        //gsui->wdgtPicture->repaint();
    }
}

//REM
void gameScreen::onTimerHit()
{
    qDebug() << "Tick";
    if(wPressed && !aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x(), hero->y()-2);
    }

    if(wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+1, hero->y()-1);
    }

    if(!wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+2, hero->y());
    }

    if(!wPressed && !aPressed && sPressed && dPressed)
    {
        hero->move(hero->x()+1, hero->y()+1);
    }

    if(!wPressed && !aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x(), hero->y()+2);
    }

    if(!wPressed && aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x()-1, hero->y()+1);
    }

    if(!wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-2, hero->y());
    }

    if(wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-1, hero->y()-1);
    }


}

void gameScreen::closeEvent(QCloseEvent *)
{
    timer->stop();
    qDebug()<<"Timer stopped";
}
