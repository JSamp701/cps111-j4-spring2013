#ifndef USER_H
#define USER_H

//NEEDS BUNCHES OF WORK

#include <string>
#include <QWidget>

class PlCh;
class QTcpSocket;

class User : public QWidget
{
    Q_OBJECT
    std::string userName;
    int team;
    QTcpSocket *sock;
    PlCh *character;


public:
    User();
    void setSocket(QTcpSocket * newSock){sock = newSock;}
    void setCharacter(PlCh *newChar){character = newChar;}
    void setUsername(std::string user){userName = user;}
    void defaultTeam(){team = 1;}
};

#endif // USER_H
