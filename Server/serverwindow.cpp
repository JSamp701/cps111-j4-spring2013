#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    connect(&server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if(!server->listen(QHostAddres::Any, 1337))
    {
        QMessageBox::critical(this, "ERROR", "Cannot start socket.");
        exit(1);
    }
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::clientConnected()
{
}

void ServerWindow::clientDisconnected()
{
}
