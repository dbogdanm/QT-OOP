#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadAndDisplayData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAndDisplayData()
{
    QString driversData = formatDriverData();
    QString routesData = formatRouteData();
    QString vehiclesData = formatVehicleData();

    ui->textEdit->setPlainText(driversData + "\n" + routesData + "\n" + vehiclesData);
}

QString MainWindow::formatDriverData()
{
    QString data;
    auto drivers = Helper::ReadDriverFromFile();

    for (const auto &driver : drivers)
    {
        std::ostringstream oss;
        oss << driver;
        data += QString::fromStdString(oss.str()) + "\n";
    }

    return data;
}

QString MainWindow::formatRouteData()
{
    QString data;
    auto routes = Helper::ReadRouteFromFile();

    for (const auto &route : routes)
    {
        std::ostringstream oss;
        oss << route;
        data += QString::fromStdString(oss.str()) + "\n";
    }

    return data;
}

QString MainWindow::formatVehicleData()
{
    QString data;
    auto vehicles = Helper::ReadVehicleFromFile();

    for (const auto &vehicle : vehicles)
    {
        std::ostringstream oss;
        oss << vehicle;
        data += QString::fromStdString(oss.str()) + "\n";
    }

    return data;
}
