#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include <string>
#include <user.h>
#include <sstream>
#include <QTextCodec>
#include <QString>
#include <counter.h>
#include <QLabel>
#include <QDebug>

//Release-1.0
ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow),
    ticks(0)
{
    ui->setupUi(this);

    connect(&server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if(!server.listen(QHostAddress::Any, 5000))
    {
        QMessageBox::critical(this, "ERROR", "Cannot start socket.");
        exit(1);
    }

    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timerGo = false;
    game = NULL;
    ui->spinPlayers->setValue(2);
    paused = false;
    //timer->start();
    curUserID = 1;
    qDebug()<<curUserID;
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::clientConnected()
{
    if(game == NULL)
    {
        User *user = new User();
        QTcpSocket *sock = server.nextPendingConnection();
        connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
        connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        user->setSocket(sock);
        unUsers.push_back(user);
        QString idMessage;
        idMessage.append("97179 777 ");
        idMessage.append(QString::number(curUserID));
        idMessage.append("\n");
        user->setUserID(curUserID);
        ++curUserID;
        sock->write(idMessage.toAscii());
    }
    else
    {
        QTcpSocket *sock = server.nextPendingConnection();
        sock->close();
        sock->deleteLater();
    }
}

void ServerWindow::clientDisconnected()
{
    qDebug()<<"clientDisconnected()";
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    for(int i = 0; i < unUsers.size(); ++i)
    {
        if(sock== unUsers.at(i)->getSock())
        {
            QString name(unUsers.at(i)->getName().c_str());
            User* user = unUsers.at(i);
            unUsers.erase(unUsers.begin() + i);
            delete user;
        }
    }
    sock->deleteLater();
    if(unUsers.size()==0)
    {
        on_btnReset_clicked();
    }
}

void ServerWindow::dataReceived()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    QString str = sock->readLine();
    if(game == NULL)
    {
        for(uint i = 0; i < unUsers.size(); ++i)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                if(!unUsers.at(i)->checkInstanceVars())
                {
                    QStringList List = str.split(" ",QString::SkipEmptyParts);
                    if(List.at(0) == "5")
                    {
                        unUsers.at(i)->setTeam(GetUserTeam());
                        unUsers.at(i)->setUsername(GetLoadUsername());
                        game = Game::Load(this, &unUsers);
                        timer->start();
                    }
                    else if (List.at(0) != "9")
                    {
                        int team;
                        team = List.at(0).toInt();
                        std::string username = List.at(1).toStdString();
                        unUsers.at(i)->setTeam(team);
                        unUsers.at(i)->setUsername(username);
                        if(!timerGo)
                        {
                            paused = false;
                            timerGo = true;
                            timerHit();
                        }
                    }
                    else
                    {
                        unUsers.at(i)->setTeam(List.at(1).toInt());
                        unUsers.at(i)->setUsername(List.at(2).toStdString());
                        if(unUsers.size() == ui->spinPlayers->value())
                        {
                            bool go = true;
                            for(int i = 0; i < unUsers.size(); ++i)
                            {
                                if(!unUsers.at(i)->checkInstanceVars())
                                {
                                    go = false;
                                    break;
                                }
                            }
                            if(go)
                            {
                                timerGo = true;
                                timerHit();
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(uint i = 0; i < unUsers.size(); i++)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                if(str.at(0) == '7')
                {
                    for(int i = 0; i < unUsers.size(); ++i)
                    {
                        unUsers.at(i)->getSock()->write("97179 7\n");
                    }
                    if(paused)
                    {
                        timer->start();
                        paused = false;
                    }
                    else
                    {
                        timer->stop();
                        paused = true;
                    }
                }
                else
                {
                    unUsers.at(i)->command(str.toStdString());
                    return;
                }
            }
        }
    }
}

void ServerWindow::timerHit()
{
    ticks += 20;
    if(timerGo)
    {
        timerGo = false;
        game = new Game(this, &unUsers);
        timer->start();
    }
    else
    {
        if(!game->getOver())
        {
            QString message = game->onTick().c_str();
            if(message != "" && message != "97179\n")
            {
                for(uint i = 0; i < unUsers.size(); ++i)
                {
                    unUsers.at(i)->getSock()->write(message.toAscii());
                }
            }
        }
        else
        {
            timer->stop();
        }
    }
}


int ServerWindow::GetUserTeam()
{
}

string ServerWindow::GetLoadUsername()
{
}

void ServerWindow::on_btnReset_clicked()
{
    timer->stop();
    timerGo = false;
    game = NULL;
    vector<QTcpSocket*> socks;
    for(int i = 0; i < unUsers.size(); ++i)
    {
        unUsers.at(i)->getSock()->close();
    }
    unUsers.clear();
}
