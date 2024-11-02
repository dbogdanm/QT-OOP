#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "Models\Helper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadAndDisplayData();
   // void on_showListButton_clicked();

private:
    Ui::MainWindow *ui;
    QString formatDriverData();
    QString formatRouteData();
    QString formatVehicleData();
};

#endif // MAINWINDOW_H
