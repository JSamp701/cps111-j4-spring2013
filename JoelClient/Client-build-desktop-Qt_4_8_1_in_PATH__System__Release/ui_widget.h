/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Mar 2 19:04:27 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lblBackground;
    QPushButton *btnLocal;
    QPushButton *btnLoad;
    QPushButton *btnNetwork;
    QPushButton *btnScores;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(200, 195);
        Widget->setAutoFillBackground(false);
        lblBackground = new QLabel(Widget);
        lblBackground->setObjectName(QString::fromUtf8("lblBackground"));
        lblBackground->setGeometry(QRect(0, 0, 200, 200));
        lblBackground->setPixmap(QPixmap(QString::fromUtf8(":/images/mobatitlewindow.png")));
        btnLocal = new QPushButton(Widget);
        btnLocal->setObjectName(QString::fromUtf8("btnLocal"));
        btnLocal->setGeometry(QRect(90, 20, 105, 35));
        btnLocal->setStyleSheet(QString::fromUtf8("background:url(:/images/button.png) no-repeat right top"));
        btnLocal->setDefault(false);
        btnLocal->setFlat(true);
        btnLoad = new QPushButton(Widget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setEnabled(false);
        btnLoad->setGeometry(QRect(90, 60, 105, 35));
        btnLoad->setStyleSheet(QString::fromUtf8("background:url(:/images/button.png) no-repeat right top"));
        btnLoad->setFlat(true);
        btnNetwork = new QPushButton(Widget);
        btnNetwork->setObjectName(QString::fromUtf8("btnNetwork"));
        btnNetwork->setEnabled(false);
        btnNetwork->setGeometry(QRect(90, 100, 105, 35));
        btnNetwork->setStyleSheet(QString::fromUtf8("background:url(:/images/button.png) no-repeat right top"));
        btnNetwork->setFlat(true);
        btnScores = new QPushButton(Widget);
        btnScores->setObjectName(QString::fromUtf8("btnScores"));
        btnScores->setGeometry(QRect(90, 140, 105, 35));
        btnScores->setStyleSheet(QString::fromUtf8("background:url(:/images/button.png) no-repeat right top"));
        btnScores->setFlat(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Game Start", 0, QApplication::UnicodeUTF8));
        lblBackground->setText(QString());
        btnLocal->setText(QApplication::translate("Widget", "Start Game", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("Widget", "Load Game", 0, QApplication::UnicodeUTF8));
        btnNetwork->setText(QApplication::translate("Widget", "Multiplayer", 0, QApplication::UnicodeUTF8));
        btnScores->setText(QApplication::translate("Widget", "High Scores", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
