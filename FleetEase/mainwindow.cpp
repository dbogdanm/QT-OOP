#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Truck.h"
#include "Motorcycle.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    for (Vehicle* v : vehicles) {
        delete v;
    }
    delete ui;
}

void MainWindow::on_addVehicleButton_clicked() {
    QString type = ui->vehicleTypeComboBox->currentText();
    QString make = ui->makeLineEdit->text();
    QString model = ui->modelLineEdit->text();
    int year = ui->yearSpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    if (type == "Truck") {
        int axles = ui->axlesSpinBox->value();
        vehicles.push_back(new Truck(make.toStdString(), model.toStdString(), year, price, axles));
    } else if (type == "Motorcycle") {
        int engine = ui->engineSpinBox->value();
        vehicles.push_back(new Motorcycle(make.toStdString(), model.toStdString(), year, price, engine));
    }
    updateVehicleList();
}

void MainWindow::on_addRouteButton_clicked() {
    QString source = ui->sourceLineEdit->text();
    QString destination = ui->destLineEdit->text();
    double distance = ui->distanceDoubleSpinBox->value();

    routes.emplace_back(source.toStdString(), destination.toStdString(), distance);
    updateRouteList();
}

void MainWindow::on_calculateTollButton_clicked() {
    double totalToll = 0.0;
    for (Vehicle* v : vehicles) {
        totalToll += v->calculateToll();
    }
    ui->totalTollLabel->setText("Total Toll: $" + QString::number(totalToll));
}

void MainWindow::updateVehicleList() {
    ui->vehicleListWidget->clear();
    for (Vehicle* v : vehicles) {
        QString info = QString::fromStdString(v->getMake() + " " + v->getModel());
        ui->vehicleListWidget->addItem(info);
    }
}

void MainWindow::updateRouteList() {
    ui->routeListWidget->clear();
    for (const Route& r : routes) {
        QString info = QString::fromStdString(r.getSource() + " -> " + r.getDestination());
        ui->routeListWidget->addItem(info);
    }
}
