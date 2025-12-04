#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Vehicle.h"
#include "Route.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addVehicleButton_clicked();
    void on_addRouteButton_clicked();
    void on_calculateTollButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Vehicle*> vehicles;
    std::vector<Route> routes;
    void updateVehicleList();
    void updateRouteList();
};

#endif
