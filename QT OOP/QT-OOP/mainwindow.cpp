#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QInputDialog>
#include <sstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadAndDisplayData();
    ui->removeDriverButton->setVisible(false);
    ui->removeDriverButton->setVisible(false);
    connect(ui->manageButton, &QPushButton::clicked, this, &MainWindow::toggleManageButtons);
    connect(ui->addDriverButton, &QPushButton::clicked, this, &MainWindow::addDriver);
    connect(ui->removeDriverButton, &QPushButton::clicked, this, &MainWindow::removeDriver);


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

    ui->lineEdit->setText(driversData + "\n" + routesData + "\n" + vehiclesData);
}

void MainWindow::toggleManageButtons()
{
    bool areButtonsVisible = ui->addDriverButton->isVisible();
    ui->addDriverButton->setVisible(!areButtonsVisible);
    ui->removeDriverButton->setVisible(!areButtonsVisible);
}

void MainWindow::addDriver()
{
    QString driverName = QInputDialog::getText(this, "Add Driver", "Enter driver name:");
    if(driverName.isEmpty()) return;

    Helper::AddDriverToFile(driverName.toStdString());
    loadAndDisplayData();
}

void MainWindow::removeDriver()
{
    QString driverName = ui->lineEdit_2->text();
    if(driverName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please enter a driver name to remove.");
        return;
    }
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
