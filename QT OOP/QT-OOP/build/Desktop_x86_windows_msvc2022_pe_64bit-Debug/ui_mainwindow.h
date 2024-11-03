/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *showListButton_6;
    QPushButton *showListButton_7;
    QPushButton *showListButton_8;
    QPushButton *showListButton_9;
    QPushButton *manageButton;
    QPushButton *showListButton_11;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QPushButton *removeDriverButton;
    QPushButton *addDriverButton;
    QLineEdit *driverNameLineEdit;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QMenu *menuFleetManager;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2074, 1035);
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Medium")});
        font.setPointSize(15);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        showListButton_6 = new QPushButton(centralwidget);
        showListButton_6->setObjectName("showListButton_6");
        showListButton_6->setGeometry(QRect(10, 450, 291, 61));
        showListButton_6->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        showListButton_7 = new QPushButton(centralwidget);
        showListButton_7->setObjectName("showListButton_7");
        showListButton_7->setGeometry(QRect(10, 360, 291, 61));
        showListButton_7->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        showListButton_8 = new QPushButton(centralwidget);
        showListButton_8->setObjectName("showListButton_8");
        showListButton_8->setGeometry(QRect(10, 270, 291, 61));
        showListButton_8->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        showListButton_9 = new QPushButton(centralwidget);
        showListButton_9->setObjectName("showListButton_9");
        showListButton_9->setGeometry(QRect(10, 190, 291, 61));
        showListButton_9->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        manageButton = new QPushButton(centralwidget);
        manageButton->setObjectName("manageButton");
        manageButton->setGeometry(QRect(10, 100, 291, 61));
        manageButton->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        showListButton_11 = new QPushButton(centralwidget);
        showListButton_11->setObjectName("showListButton_11");
        showListButton_11->setGeometry(QRect(10, 10, 291, 61));
        showListButton_11->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 400, 291, 71));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 310, 291, 71));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 220, 291, 81));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(10, 140, 291, 71));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(10, 50, 291, 71));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        removeDriverButton = new QPushButton(centralwidget);
        removeDriverButton->setObjectName("removeDriverButton");
        removeDriverButton->setGeometry(QRect(310, 130, 100, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Medium")});
        font1.setPointSize(10);
        removeDriverButton->setFont(font1);
        removeDriverButton->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        addDriverButton = new QPushButton(centralwidget);
        addDriverButton->setObjectName("addDriverButton");
        addDriverButton->setGeometry(QRect(310, 100, 100, 30));
        addDriverButton->setFont(font1);
        addDriverButton->setStyleSheet(QString::fromUtf8("border-radius: 15px; /* Schimb\304\203 valoarea pentru mai mult\304\203/mic\304\203 rotunjire */\n"
"border: 2px solid #3498db; /* Schimb\304\203 culoarea \310\231i grosimea conturului */\n"
"background-color:#154c79; /* Schimb\304\203 culoarea de fundal */\n"
"color: white; /* Schimb\304\203 culoarea textului */"));
        driverNameLineEdit = new QLineEdit(centralwidget);
        driverNameLineEdit->setObjectName("driverNameLineEdit");
        driverNameLineEdit->setGeometry(QRect(340, 340, 113, 24));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(580, 80, 1361, 691));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(430, 130, 113, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 2074, 29));
        menuFleetManager = new QMenu(menubar);
        menuFleetManager->setObjectName("menuFleetManager");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFleetManager->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        showListButton_6->setText(QCoreApplication::translate("MainWindow", "Account", nullptr));
        showListButton_7->setText(QCoreApplication::translate("MainWindow", "Customer complains", nullptr));
        showListButton_8->setText(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        showListButton_9->setText(QCoreApplication::translate("MainWindow", "Trip logs", nullptr));
        manageButton->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        showListButton_11->setText(QCoreApplication::translate("MainWindow", "Fleet", nullptr));
        removeDriverButton->setText(QCoreApplication::translate("MainWindow", "Remove driver", nullptr));
        addDriverButton->setText(QCoreApplication::translate("MainWindow", "Add driver", nullptr));
        menuFleetManager->setTitle(QCoreApplication::translate("MainWindow", "FleetEase", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
