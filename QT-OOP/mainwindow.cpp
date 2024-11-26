// mainwindow.cpp
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    displayFleetData();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{

    centralWidget = new QWidget(this);
    mainLayout = new QHBoxLayout(centralWidget);


    leftLayout = new QVBoxLayout;
    leftLayout->setSpacing(10);
    leftLayout->setContentsMargins(10, 10, 10, 10);


    fleetButton = new QPushButton("Fleet", this);
    manageButton = new QPushButton("Manage", this);
    tripLogsButton = new QPushButton("Trip Logs", this);
    reportsButton = new QPushButton("Reports", this);
    customerComplaintsButton = new QPushButton("Customer Complaints", this);
    accountButton = new QPushButton("Account", this);


    leftLayout->addWidget(fleetButton);
    leftLayout->addWidget(manageButton);
    leftLayout->addWidget(tripLogsButton);
    leftLayout->addWidget(reportsButton);
    leftLayout->addWidget(customerComplaintsButton);
    leftLayout->addWidget(accountButton);
    leftLayout->addStretch();


    rightLayout = new QVBoxLayout;
    rightLayout->setSpacing(10);
    rightLayout->setContentsMargins(10, 10, 10, 10);

    // Inițializare zona de afișare a datelor flotei
    fleetDisplay = new QTextEdit(this);
    fleetDisplay->setReadOnly(true);
    fleetDisplay->setVisible(true); // Vizibil inițial

    rightLayout->addWidget(fleetDisplay);

    // initialize manageWidget, care va conține opțiunile de gestionare
    manageWidget = new QWidget(this);
    manageWidget->setVisible(false); // Ascuns inițial
    QVBoxLayout *manageOptionsLayout = new QVBoxLayout(manageWidget);

    // Inițializare butoane de gestionare
    addDriverButton = new QPushButton("Add Driver", this);
    removeDriverButton = new QPushButton("Remove Driver", this);
    addVehicleButton = new QPushButton("Add Vehicle", this);
    removeVehicleButton = new QPushButton("Remove Vehicle", this);
    addRouteButton = new QPushButton("Add Route", this);
    removeRouteButton = new QPushButton("Remove Route", this);

    // Inițializare câmpuri de text și butoane de confirmare, ascunse inițial
    // Add Driver
    addDriverInput = new QLineEdit(this);
    addDriverInput->setPlaceholderText("Enter driver name");
    addDriverInput->setVisible(false);
    confirmAddDriverButton = new QPushButton("Confirm", this);
    confirmAddDriverButton->setVisible(false);

    // Remove Driver
    removeDriverInput = new QLineEdit(this);
    removeDriverInput->setPlaceholderText("Enter driver name to remove");
    removeDriverInput->setVisible(false);
    confirmRemoveDriverButton = new QPushButton("Confirm", this);
    confirmRemoveDriverButton->setVisible(false);

    // Add Vehicle
    addVehicleInput = new QLineEdit(this);
    addVehicleInput->setPlaceholderText("Enter vehicle VIN");
    addVehicleInput->setVisible(false);
    confirmAddVehicleButton = new QPushButton("Confirm", this);
    confirmAddVehicleButton->setVisible(false);

    // Remove Vehicle
    removeVehicleInput = new QLineEdit(this);
    removeVehicleInput->setPlaceholderText("Enter vehicle VIN to remove");
    removeVehicleInput->setVisible(false);
    confirmRemoveVehicleButton = new QPushButton("Confirm", this);
    confirmRemoveVehicleButton->setVisible(false);

    // Add Route
    addRouteInput = new QLineEdit(this);
    addRouteInput->setPlaceholderText("Enter route ID");
    addRouteInput->setVisible(false);
    confirmAddRouteButton = new QPushButton("Confirm", this);
    confirmAddRouteButton->setVisible(false);

    // Remove Route
    removeRouteInput = new QLineEdit(this);
    removeRouteInput->setPlaceholderText("Enter route ID to remove");
    removeRouteInput->setVisible(false);
    confirmRemoveRouteButton = new QPushButton("Confirm", this);
    confirmRemoveRouteButton->setVisible(false);

    // Creare layout-uri pentru fiecare opțiune de gestionare
    // Add Driver Layout
    QHBoxLayout *addDriverLayout = new QHBoxLayout;
    addDriverLayout->addWidget(addDriverButton);
    addDriverLayout->addWidget(addDriverInput);
    addDriverLayout->addWidget(confirmAddDriverButton);
    manageOptionsLayout->addLayout(addDriverLayout);

    // Remove Driver Layout
    QHBoxLayout *removeDriverLayout = new QHBoxLayout;
    removeDriverLayout->addWidget(removeDriverButton);
    removeDriverLayout->addWidget(removeDriverInput);
    removeDriverLayout->addWidget(confirmRemoveDriverButton);
    manageOptionsLayout->addLayout(removeDriverLayout);

    // Add Vehicle Layout
    QHBoxLayout *addVehicleLayout = new QHBoxLayout;
    addVehicleLayout->addWidget(addVehicleButton);
    addVehicleLayout->addWidget(addVehicleInput);
    addVehicleLayout->addWidget(confirmAddVehicleButton);
    manageOptionsLayout->addLayout(addVehicleLayout);

    // Remove Vehicle Layout
    QHBoxLayout *removeVehicleLayout = new QHBoxLayout;
    removeVehicleLayout->addWidget(removeVehicleButton);
    removeVehicleLayout->addWidget(removeVehicleInput);
    removeVehicleLayout->addWidget(confirmRemoveVehicleButton);
    manageOptionsLayout->addLayout(removeVehicleLayout);

    // Add Route Layout
    QHBoxLayout *addRouteLayout = new QHBoxLayout;
    addRouteLayout->addWidget(addRouteButton);
    addRouteLayout->addWidget(addRouteInput);
    addRouteLayout->addWidget(confirmAddRouteButton);
    manageOptionsLayout->addLayout(addRouteLayout);

    // Remove Route Layout
    QHBoxLayout *removeRouteLayout = new QHBoxLayout;
    removeRouteLayout->addWidget(removeRouteButton);
    removeRouteLayout->addWidget(removeRouteInput);
    removeRouteLayout->addWidget(confirmRemoveRouteButton);
    manageOptionsLayout->addLayout(removeRouteLayout);

    // Adăugare manageWidget la layout-ul drept
    rightLayout->addWidget(manageWidget);

    // Adăugare layout-uri la layout-ul principal
    mainLayout->addLayout(leftLayout, 1);  // Proporție de 1 pentru stânga
    mainLayout->addLayout(rightLayout, 3); // Proporție de 3 pentru dreapta

    // Setare widget central
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Conectare butoane principale la sloturi
    connect(fleetButton, &QPushButton::clicked, this, &MainWindow::onFleetClicked);
    connect(manageButton, &QPushButton::clicked, this, &MainWindow::onManageClicked);
    connect(tripLogsButton, &QPushButton::clicked, this, &MainWindow::onTripLogsClicked);
    connect(reportsButton, &QPushButton::clicked, this, &MainWindow::onReportsClicked);
    connect(customerComplaintsButton, &QPushButton::clicked, this, &MainWindow::onCustomerComplaintsClicked);
    connect(accountButton, &QPushButton::clicked, this, &MainWindow::onAccountClicked);

    // Conectare butoane de gestionare la sloturi
    connect(addDriverButton, &QPushButton::clicked, this, &MainWindow::onAddDriverClicked);
    connect(removeDriverButton, &QPushButton::clicked, this, &MainWindow::onRemoveDriverClicked);
    connect(addVehicleButton, &QPushButton::clicked, this, &MainWindow::onAddVehicleClicked);
    connect(removeVehicleButton, &QPushButton::clicked, this, &MainWindow::onRemoveVehicleClicked);
    connect(addRouteButton, &QPushButton::clicked, this, &MainWindow::onAddRouteClicked);
    connect(removeRouteButton, &QPushButton::clicked, this, &MainWindow::onRemoveRouteClicked);

    // Conectare butoane de confirmare la sloturi
    connect(confirmAddDriverButton, &QPushButton::clicked, this, &MainWindow::onConfirmAddDriver);
    connect(confirmRemoveDriverButton, &QPushButton::clicked, this, &MainWindow::onConfirmRemoveDriver);
    connect(confirmAddVehicleButton, &QPushButton::clicked, this, &MainWindow::onConfirmAddVehicle);
    connect(confirmRemoveVehicleButton, &QPushButton::clicked, this, &MainWindow::onConfirmRemoveVehicle);
    connect(confirmAddRouteButton, &QPushButton::clicked, this, &MainWindow::onConfirmAddRoute);
    connect(confirmRemoveRouteButton, &QPushButton::clicked, this, &MainWindow::onConfirmRemoveRoute);
}

void MainWindow::onFleetClicked()
{
    // Afișare date fleet
    displayFleetData();

    // Ascundere opțiuni de gestionare și afișare fleetDisplay
    manageWidget->setVisible(false);
    fleetDisplay->setVisible(true);
}

void MainWindow::onManageClicked()
{
    // Afișare opțiuni de gestionare și ascundere fleetDisplay
    manageWidget->setVisible(true);
    fleetDisplay->setVisible(false);

    // Resetare și ascundere câmpuri de input
    addDriverInput->clear();
    confirmAddDriverButton->setVisible(false);
    addDriverInput->setVisible(false);

    removeDriverInput->clear();
    confirmRemoveDriverButton->setVisible(false);
    removeDriverInput->setVisible(false);

    addVehicleInput->clear();
    confirmAddVehicleButton->setVisible(false);
    addVehicleInput->setVisible(false);

    removeVehicleInput->clear();
    confirmRemoveVehicleButton->setVisible(false);
    removeVehicleInput->setVisible(false);

    addRouteInput->clear();
    confirmAddRouteButton->setVisible(false);
    addRouteInput->setVisible(false);

    removeRouteInput->clear();
    confirmRemoveRouteButton->setVisible(false);
    removeRouteInput->setVisible(false);
}

void MainWindow::onTripLogsClicked()
{
    // Implementare specifică pentru Trip Logs
    QMessageBox::information(this, "Trip Logs", "Trip Logs functionality is not implemented yet.");
}

void MainWindow::onReportsClicked()
{
    // Implementare specifică pentru Reports
    QMessageBox::information(this, "Reports", "Reports functionality is not implemented yet.");
}

void MainWindow::onCustomerComplaintsClicked()
{
    // Implementare specifică pentru Customer Complaints
    QMessageBox::information(this, "Customer Complaints", "Customer Complaints functionality is not implemented yet.");
}

void MainWindow::onAccountClicked()
{
    // Implementare specifică pentru Account
    QMessageBox::information(this, "Account", "Account functionality is not implemented yet.");
}

// Sloturi pentru butoanele de gestionare
void MainWindow::onAddDriverClicked()
{
    addDriverInput->setVisible(true);
    confirmAddDriverButton->setVisible(true);
}

void MainWindow::onRemoveDriverClicked()
{
    removeDriverInput->setVisible(true);
    confirmRemoveDriverButton->setVisible(true);
}

void MainWindow::onAddVehicleClicked()
{
    addVehicleInput->setVisible(true);
    confirmAddVehicleButton->setVisible(true);
}

void MainWindow::onRemoveVehicleClicked()
{
    removeVehicleInput->setVisible(true);
    confirmRemoveVehicleButton->setVisible(true);
}

void MainWindow::onAddRouteClicked()
{
    addRouteInput->setVisible(true);
    confirmAddRouteButton->setVisible(true);
}

void MainWindow::onRemoveRouteClicked()
{
    removeRouteInput->setVisible(true);
    confirmRemoveRouteButton->setVisible(true);
}

// Sloturi pentru confirmarea acțiunilor
void MainWindow::onConfirmAddDriver()
{
    QString driverName = addDriverInput->text().trimmed();
    if (driverName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Driver name cannot be empty.");
        return;
    }

    addDriverToFile(driverName);
    QMessageBox::information(this, "Success", "Driver added successfully.");
    addDriverInput->clear();
    addDriverInput->setVisible(false);
    confirmAddDriverButton->setVisible(false);
    displayFleetData();
}

void MainWindow::onConfirmRemoveDriver()
{
    QString driverName = removeDriverInput->text().trimmed();
    if (driverName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Driver name cannot be empty.");
        return;
    }

    removeDriverFromFile(driverName);
    QMessageBox::information(this, "Success", "Driver removed successfully.");
    removeDriverInput->clear();
    removeDriverInput->setVisible(false);
    confirmRemoveDriverButton->setVisible(false);
    displayFleetData();
}

void MainWindow::onConfirmAddVehicle()
{
    QString vehicleVin = addVehicleInput->text().trimmed();
    if (vehicleVin.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Vehicle VIN cannot be empty.");
        return;
    }

    addVehicleToFile(vehicleVin);
    QMessageBox::information(this, "Success", "Vehicle added successfully.");
    addVehicleInput->clear();
    addVehicleInput->setVisible(false);
    confirmAddVehicleButton->setVisible(false);
    displayFleetData();
}

void MainWindow::onConfirmRemoveVehicle()
{
    QString vehicleVin = removeVehicleInput->text().trimmed();
    if (vehicleVin.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Vehicle VIN cannot be empty.");
        return;
    }

    removeVehicleFromFile(vehicleVin);
    QMessageBox::information(this, "Success", "Vehicle removed successfully.");
    removeVehicleInput->clear();
    removeVehicleInput->setVisible(false);
    confirmRemoveVehicleButton->setVisible(false);
    displayFleetData();
}

void MainWindow::onConfirmAddRoute()
{
    QString routeId = addRouteInput->text().trimmed();
    if (routeId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Route ID cannot be empty.");
        return;
    }

    addRouteToFile(routeId);
    QMessageBox::information(this, "Success", "Route added successfully.");
    addRouteInput->clear();
    addRouteInput->setVisible(false);
    confirmAddRouteButton->setVisible(false);
    displayFleetData();
}

void MainWindow::onConfirmRemoveRoute()
{
    QString routeId = removeRouteInput->text().trimmed();
    if (routeId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Route ID cannot be empty.");
        return;
    }

    removeRouteFromFile(routeId);
    QMessageBox::information(this, "Success", "Route removed successfully.");
    removeRouteInput->clear();
    removeRouteInput->setVisible(false);
    confirmRemoveRouteButton->setVisible(false);
    displayFleetData();
}

// Funcții auxiliare pentru gestionarea fișierelor

void MainWindow::addDriverToFile(const QString &driverName)
{
    QFile file("drivers.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open drivers.txt for writing.");
        return;
    }

    QTextStream out(&file);
    out << driverName << "\n";
    file.close();
}

void MainWindow::removeDriverFromFile(const QString &driverName)
{
    QFile file("drivers.txt");
    if (!file.exists()) {
        QMessageBox::warning(this, "File Error", "drivers.txt does not exist.");
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open drivers.txt for reading.");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line != driverName)
            lines << line;
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open drivers.txt for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
}

void MainWindow::addVehicleToFile(const QString &vehicleVin)
{
    QFile file("vehicles.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open vehicles.txt for writing.");
        return;
    }

    QTextStream out(&file);
    out << vehicleVin << "\n";
    file.close();
}

void MainWindow::removeVehicleFromFile(const QString &vehicleVin)
{
    QFile file("vehicles.txt");
    if (!file.exists()) {
        QMessageBox::warning(this, "File Error", "vehicles.txt does not exist.");
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open vehicles.txt for reading.");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line != vehicleVin)
            lines << line;
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open vehicles.txt for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
}

void MainWindow::addRouteToFile(const QString &routeId)
{
    QFile file("routes.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open routes.txt for writing.");
        return;
    }

    QTextStream out(&file);
    out << routeId << "\n";
    file.close();
}

void MainWindow::removeRouteFromFile(const QString &routeId)
{
    QFile file("routes.txt");
    if (!file.exists()) {
        QMessageBox::warning(this, "File Error", "routes.txt does not exist.");
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open routes.txt for reading.");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line != routeId)
            lines << line;
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Cannot open routes.txt for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
}

// Funcție pentru afișarea datelor flotei
void MainWindow::displayFleetData()
{
    QString driversData = "";
    QFile driversFile("drivers.txt");
    if (driversFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&driversFile);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty())
                driversData += line + "\n";
        }
        driversFile.close();
    }

    QString vehiclesData = "";
    QFile vehiclesFile("vehicles.txt");
    if (vehiclesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&vehiclesFile);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty())
                vehiclesData += line + "\n";
        }
        vehiclesFile.close();
    }

    QString routesData = "";
    QFile routesFile("routes.txt");
    if (routesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&routesFile);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty())
                routesData += line + "\n";
        }
        routesFile.close();
    }

    QString combinedData = "--- Drivers ---\n" + driversData +
                           "\n--- Vehicles ---\n" + vehiclesData +
                           "\n--- Routes ---\n" + routesData;

    fleetDisplay->setPlainText(combinedData);
}
