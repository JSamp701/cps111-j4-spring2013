#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include "world.h"
#include <vector>
#include "user.h"
#include <QUdpSocket>
#include "serverwindow.h"

//NEEDS BUNCHES OF WORK

class Game
{
    static int curGameID;
    World *world;
    QTimer *timer;
    bool over;
    vector<User *> users;
    QUdpSocket *sock;
    ServerWindow *home;
    int readyCount;

private slots:
    void timerHit();




public:
    Game(ServerWindow * window, vector<User*> *vect);
    void endGame(int team);
};

#endif // GAME_H
