#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class gameScreen;

#include <QWidget>
#include "widget.h"
#include <QKeyEvent>
#include <QDebug>
#include <assert.h>
#include <QPixmap>
#include "entitylabel.h"
#include <vector>
#include <QResizeEvent>
#include <QFrame>
#include <QTcpSocket>
#include "scorewindow.h"
#include <QPushButton>
#include <QStringList>
#include <QTcpSocket>
#include <QList>
#include <vector>
//REM
#include <QTimer>
//REM

class ScoreObject
{
private:
    QString user;
    int playerDeaths;
    int minionKills;
    int towerKills;
    int playerTeam;

public:
    void setDeaths(int i){playerDeaths = i;}
    void setMKills(int i){minionKills = i;}
    void setTKills(int i){towerKills = i;}
    void setTeam(int i){playerTeam = i;}
    void setUsername(QString &s){user = s;}

    int deaths(){return playerDeaths;}
    int mKills(){return minionKills;}
    int tKills(){return towerKills;}
    int team(){return playerTeam;}
    QString username(){return user;}
};


class gameScreen : public QWidget
{
    Q_OBJECT
    EntityLabel *hero;
    
public:
    explicit gameScreen(QWidget *parent = 0);
    void connectWidget(Widget *newW){w = newW;}
    ~gameScreen();
    void takeOverKeyboard() { wdgtGame->grabKeyboard(); }
    void passSocket(QTcpSocket *s) {sock = s;}

    void createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name);
    void moveEntity(int id, int x, int y);
    void changeEntityState(int id, int state);
    void changeEntityHealth(int id, int healthPercent);
    void animate(int id);
    void exterminate(int id);
    void showLbl(int id);


    EntityLabel* getByID(int id);

private slots:
    void onTimerHit();
    void return_to_menu();
    void serverDisconnected();
    void unPause();
    void readCommand();
    void lblClicked();
    
private:
    Ui::gameScreen *gsui;
    QWidget *wdgtGame;
    QWidget *wdgtPicture;
    QFrame *gameFrame;
    QFrame *pause;
    QPushButton *menu;
    QPushButton *btnPause;
    QLabel *bar;
    Widget *w;
    QTcpSocket *sock;
    std::vector<EntityLabel*> objects;

    //update methods called from server

     void updatePlayer(QStringList player);
     void updatePos(EntityLabel *lblToUpdate, int x, int y, int width, int height);

protected:
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *);
    void resizeEvent ( QResizeEvent * event );

    QTimer *timer;

    bool pPressed;

    bool upPressed;
    bool rightPressed;
    bool downPressed;
    bool leftPressed;
};

#endif // GAMESCREEN_H
