#include "mainwindow.h"
#include "Models/Helper.h"
#include "Models/FleetManager.h"
#include "Exceptions/DriverNotFoundException.h".h"
#include "Exceptions/RouteNotFoundException.h"
#include "Exceptions/VehicleNotFoundException.h"
#include "Models/Helper.h"
#include "Exceptions/FleetException.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

// Constructor now takes username (login result) and sets up everything
MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent), m_username(username)
{
    // Initialize FleetManager with sample data
    auto drivers = Helper::ReadDriverFromFile();
    auto vehicles = Helper::ReadVehicleFromFile();
    auto routes = Helper::ReadRouteFromFile();
    fleetManager = FleetManager(drivers, std::move(vehicles), routes);

    setWindowTitle("FleetEase - " + m_username);

    createPages();
    createMenus();
    createToolBar();

    setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
{
    // Dashboard menu
    QMenu *menuFleet = menuBar()->addMenu("Home");
    QAction *dashboardAction = menuFleet->addAction("Dashboard");
    connect(dashboardAction, &QAction::triggered, this, &MainWindow::showDashboard);

    // Sections menu (for MDI)
    QMenu *sectionsMenu = menuBar()->addMenu("Sections");

    QAction *fleetAct = new QAction("Fleet", this);
    connect(fleetAct, &QAction::triggered, this, &MainWindow::showFleetWindow);
    sectionsMenu->addAction(fleetAct);

    QAction *manageAct = new QAction("Manage", this);
    connect(manageAct, &QAction::triggered, this, &MainWindow::showManageWindow);
    sectionsMenu->addAction(manageAct);

    QAction *tripLogsAct = new QAction("Trip Logs", this);
    connect(tripLogsAct, &QAction::triggered, this, &MainWindow::showTripLogsWindow);
    sectionsMenu->addAction(tripLogsAct);

    QAction *reportsAct = new QAction("Reports", this);
    connect(reportsAct, &QAction::triggered, this, &MainWindow::showReportsWindow);
    sectionsMenu->addAction(reportsAct);

    QAction *ccAct = new QAction("Customer Complaints", this);
    connect(ccAct, &QAction::triggered, this, &MainWindow::showCustomerComplaintsWindow);
    sectionsMenu->addAction(ccAct);

    QAction *accountAct = new QAction("Account", this);
    connect(accountAct, &QAction::triggered, this, &MainWindow::showAccountWindow);
    sectionsMenu->addAction(accountAct);

    QAction *fuelAct = new QAction("Fuel Consumption", this);
    connect(fuelAct, &QAction::triggered, this, &MainWindow::showFuelConsumptionWindow);
    sectionsMenu->addAction(fuelAct);

    QAction *remindersAct = new QAction("Reminders", this);
    connect(remindersAct, &QAction::triggered, this, &MainWindow::showRemindersWindow);
    sectionsMenu->addAction(remindersAct);

    QAction *inspectionAct = new QAction("Inspection", this);
    connect(inspectionAct, &QAction::triggered, this, &MainWindow::showInspectionWindow);
    sectionsMenu->addAction(inspectionAct);

    // View Menu for MDI arrangement
    QMenu *viewMenu = menuBar()->addMenu("View");
    QAction *cascadeAction = new QAction("Cascade", this);
    QAction *tileAction = new QAction("Tile", this);
    connect(cascadeAction, &QAction::triggered, mdiArea, &QMdiArea::cascadeSubWindows);
    connect(tileAction, &QAction::triggered, mdiArea, &QMdiArea::tileSubWindows);
    viewMenu->addAction(cascadeAction);
    viewMenu->addAction(tileAction);

    // File menu for exit
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    fileMenu->addAction(exitAction);
}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("MainToolbar");
    toolBar->setMovable(false);

    QAction *fleetAct = new QAction("Fleet", this);
    toolBar->addAction(fleetAct);
    connect(fleetAct, &QAction::triggered, this, &MainWindow::showFleetWindow);

    QAction *manageAct = new QAction("Manage", this);
    toolBar->addAction(manageAct);
    connect(manageAct, &QAction::triggered, this, &MainWindow::showManageWindow);

    QAction *tripLogsAct = new QAction("Trip Logs", this);
    toolBar->addAction(tripLogsAct);
    connect(tripLogsAct, &QAction::triggered, this, &MainWindow::showTripLogsWindow);

    QAction *reportsAct = new QAction("Reports", this);
    toolBar->addAction(reportsAct);
    connect(reportsAct, &QAction::triggered, this, &MainWindow::showReportsWindow);

    QAction *ccAct = new QAction("Complaints", this);
    toolBar->addAction(ccAct);
    connect(ccAct, &QAction::triggered, this, &MainWindow::showCustomerComplaintsWindow);

    QAction *accountAct = new QAction("Account", this);
    toolBar->addAction(accountAct);
    connect(accountAct, &QAction::triggered, this, &MainWindow::showAccountWindow);

    QAction *fuelAct = new QAction("Fuel", this);
    toolBar->addAction(fuelAct);
    connect(fuelAct, &QAction::triggered, this, &MainWindow::showFuelConsumptionWindow);

    QAction *remindersAct = new QAction("Reminders", this);
    toolBar->addAction(remindersAct);
    connect(remindersAct, &QAction::triggered, this, &MainWindow::showRemindersWindow);

    QAction *inspAct = new QAction("Inspection", this);
    toolBar->addAction(inspAct);
    connect(inspAct, &QAction::triggered, this, &MainWindow::showInspectionWindow);
}

void MainWindow::createPages()
{
    stackedWidget = new QStackedWidget(this);

    // Dashboard page (from your original code)
    dashboardPage = new QWidget(this);
    {
        QVBoxLayout *layout = new QVBoxLayout(dashboardPage);
        layout->addWidget(new QLabel("Bine ai venit, " + m_username + "!"));
    }
    stackedWidget->addWidget(dashboardPage);

    // MDI page
    mdiPage = new QWidget(this);
    {
        QVBoxLayout *layout = new QVBoxLayout(mdiPage);
        mdiArea = new QMdiArea(mdiPage);
        layout->addWidget(mdiArea);
        mdiPage->setLayout(layout);
    }
    stackedWidget->addWidget(mdiPage);

    stackedWidget->setCurrentWidget(dashboardPage);
}

// Show the dashboard page
void MainWindow::showDashboard()
{
    stackedWidget->setCurrentWidget(dashboardPage);
}

// Each of these shows a sub-window inside the MDI area and switches to the MDI page.
void MainWindow::showFleetWindow()
{
    // Switch to MDI page
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createFleetWidget());
    sub->setWindowTitle("Fleet");
    sub->show();
}

void MainWindow::showManageWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createManageWidget());
    sub->setWindowTitle("Manage");
    sub->show();
}

void MainWindow::showTripLogsWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createTripLogsWidget());
    sub->setWindowTitle("Trip Logs");
    sub->show();
}

void MainWindow::showReportsWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createReportsWidget());
    sub->setWindowTitle("Reports");
    sub->show();
}

void MainWindow::showCustomerComplaintsWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createCustomerComplaintsWidget());
    sub->setWindowTitle("Customer Complaints");
    sub->show();
}

void MainWindow::showAccountWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createAccountWidget());
    sub->setWindowTitle("Account");
    sub->show();
}

void MainWindow::showFuelConsumptionWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createFuelConsumptionWidget());
    sub->setWindowTitle("Fuel Consumption");
    sub->show();
}

void MainWindow::showRemindersWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createRemindersWidget());
    sub->setWindowTitle("Reminders");
    sub->show();
}

void MainWindow::showInspectionWindow()
{
    stackedWidget->setCurrentWidget(mdiPage);
    QMdiSubWindow *sub = mdiArea->addSubWindow(createInspectionWidget());
    sub->setWindowTitle("Inspection");
    sub->show();
}

// Widget creation methods (from previous complex code)

// Fleet
QWidget* MainWindow::createFleetWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);

    QPushButton *showFleetBtn = new QPushButton("Display Fleet");
    connect(showFleetBtn, &QPushButton::clicked, [this]() {
        fleetManager.displayFleet();
        QMessageBox::information(nullptr, "Fleet Info", "Fleet info printed to console.");
    });

    layout->addWidget(new QLabel("Fleet Overview"));
    layout->addWidget(showFleetBtn);
    return w;
}

// Manage
QWidget* MainWindow::createManageWidget()
{
    QWidget *w = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(w);

    QVBoxLayout *leftPanel = new QVBoxLayout;

    // Add driver
    {
        QHBoxLayout *addDriverLayout = new QHBoxLayout;
        addDriverLayout->addWidget(new QLabel("Add Driver:"));
        QLineEdit *driverIdEdit = new QLineEdit; driverIdEdit->setPlaceholderText("ID");
        QLineEdit *driverNameEdit = new QLineEdit; driverNameEdit->setPlaceholderText("Name");
        QLineEdit *driverPhoneEdit = new QLineEdit; driverPhoneEdit->setPlaceholderText("Phone");
        QLineEdit *driverHoursEdit = new QLineEdit; driverHoursEdit->setPlaceholderText("Hours");
        QPushButton *confirmAddDriver = new QPushButton("Confirm");
        connect(confirmAddDriver, &QPushButton::clicked, [this, driverIdEdit, driverNameEdit, driverPhoneEdit, driverHoursEdit]() {
            int id = driverIdEdit->text().toInt();
            QString name = driverNameEdit->text();
            QString phone = driverPhoneEdit->text();
            int hours = driverHoursEdit->text().toInt();
            Driver d(id, name.toStdString(), phone.toStdString(), hours);
            fleetManager.addDriver(d);
            QMessageBox::information(nullptr, "Success", "Driver added.");
        });
        addDriverLayout->addWidget(driverIdEdit);
        addDriverLayout->addWidget(driverNameEdit);
        addDriverLayout->addWidget(driverPhoneEdit);
        addDriverLayout->addWidget(driverHoursEdit);
        addDriverLayout->addWidget(confirmAddDriver);
        leftPanel->addLayout(addDriverLayout);
    }

    // Remove driver
    {
        QHBoxLayout *removeDriverLayout = new QHBoxLayout;
        removeDriverLayout->addWidget(new QLabel("Remove Driver by ID:"));
        QLineEdit *removeDriverIdEdit = new QLineEdit; removeDriverIdEdit->setPlaceholderText("ID");
        QPushButton *confirmRemoveDriver = new QPushButton("Remove");
        connect(confirmRemoveDriver, &QPushButton::clicked, [this, removeDriverIdEdit]() {
            int id = removeDriverIdEdit->text().toInt();
            try {
                fleetManager.removeDriverById(id);
                QMessageBox::information(nullptr, "Success", "Driver removed.");
            } catch (const DriverNotFoundException &ex) {
                QMessageBox::warning(nullptr, "Error", ex.what());
            }
        });
        removeDriverLayout->addWidget(removeDriverIdEdit);
        removeDriverLayout->addWidget(confirmRemoveDriver);
        leftPanel->addLayout(removeDriverLayout);
    }

    // Add Vehicle
    {
        QHBoxLayout *addVehicleLayout = new QHBoxLayout;
        addVehicleLayout->addWidget(new QLabel("Add Vehicle (Bus):"));
        QLineEdit *vinEdit = new QLineEdit; vinEdit->setPlaceholderText("VIN");
        QLineEdit *modelEdit = new QLineEdit; modelEdit->setPlaceholderText("Model");
        QLineEdit *kmEdit = new QLineEdit; kmEdit->setPlaceholderText("KM");
        QLineEdit *brandEdit = new QLineEdit; brandEdit->setPlaceholderText("Brand");
        QLineEdit *seatEdit = new QLineEdit; seatEdit->setPlaceholderText("Seats");
        QLineEdit *wifiEdit = new QLineEdit; wifiEdit->setPlaceholderText("Wifi? 0/1");
        QPushButton *confirmAddVehicle = new QPushButton("Confirm");
        connect(confirmAddVehicle, &QPushButton::clicked, [this, vinEdit, modelEdit, kmEdit, brandEdit, seatEdit, wifiEdit]() {
            int vin = vinEdit->text().toInt();
            std::string model = modelEdit->text().toStdString();
            int km = kmEdit->text().toInt();
            std::string brand = brandEdit->text().toStdString();
            int seats = seatEdit->text().toInt();
            bool wifi = (wifiEdit->text().toInt() == 1);
            fleetManager.addVehicle(std::make_unique<Bus>(vin, model, km, brand, seats, wifi));
            QMessageBox::information(nullptr, "Success", "Bus added.");
        });
        addVehicleLayout->addWidget(vinEdit);
        addVehicleLayout->addWidget(modelEdit);
        addVehicleLayout->addWidget(kmEdit);
        addVehicleLayout->addWidget(brandEdit);
        addVehicleLayout->addWidget(seatEdit);
        addVehicleLayout->addWidget(wifiEdit);
        addVehicleLayout->addWidget(confirmAddVehicle);
        leftPanel->addLayout(addVehicleLayout);
    }

    // Remove Vehicle
    {
        QHBoxLayout *removeVehicleLayout = new QHBoxLayout;
        removeVehicleLayout->addWidget(new QLabel("Remove Vehicle by VIN:"));
        QLineEdit *removeVinEdit = new QLineEdit; removeVinEdit->setPlaceholderText("VIN");
        QPushButton *removeVehicleBtn = new QPushButton("Remove");
        connect(removeVehicleBtn, &QPushButton::clicked, [this, removeVinEdit]() {
            int vin = removeVinEdit->text().toInt();
            try {
                fleetManager.removeVehicleByVin(vin);
                QMessageBox::information(nullptr, "Success", "Vehicle removed.");
            } catch (const VehicleNotFoundException &ex) {
                QMessageBox::warning(nullptr, "Error", ex.what());
            }
        });
        removeVehicleLayout->addWidget(removeVinEdit);
        removeVehicleLayout->addWidget(removeVehicleBtn);
        leftPanel->addLayout(removeVehicleLayout);
    }

    // Add Route
    {
        QHBoxLayout *addRouteLayout = new QHBoxLayout;
        addRouteLayout->addWidget(new QLabel("Add Route:"));
        QLineEdit *routeIdEdit = new QLineEdit; routeIdEdit->setPlaceholderText("ID");
        QLineEdit *distEdit = new QLineEdit; distEdit->setPlaceholderText("Distance");
        QLineEdit *startEdit = new QLineEdit; startEdit->setPlaceholderText("Start");
        QLineEdit *endEdit = new QLineEdit; endEdit->setPlaceholderText("End");
        QPushButton *confirmAddRoute = new QPushButton("Add Route");
        connect(confirmAddRoute, &QPushButton::clicked, [this, routeIdEdit, distEdit, startEdit, endEdit]() {
            int id = routeIdEdit->text().toInt();
            int dist = distEdit->text().toInt();
            std::string st = startEdit->text().toStdString();
            std::string ed = endEdit->text().toStdString();
            Route r(id, dist, st, ed);
            fleetManager.addRoute(r);
            QMessageBox::information(nullptr, "Success", "Route added.");
        });
        addRouteLayout->addWidget(routeIdEdit);
        addRouteLayout->addWidget(distEdit);
        addRouteLayout->addWidget(startEdit);
        addRouteLayout->addWidget(endEdit);
        addRouteLayout->addWidget(confirmAddRoute);
        leftPanel->addLayout(addRouteLayout);
    }

    // Remove Route
    {
        QHBoxLayout *removeRouteLayout = new QHBoxLayout;
        removeRouteLayout->addWidget(new QLabel("Remove Route by ID:"));
        QLineEdit *removeRouteIdEdit = new QLineEdit; removeRouteIdEdit->setPlaceholderText("ID");
        QPushButton *removeRouteBtn = new QPushButton("Remove Route");
        connect(removeRouteBtn, &QPushButton::clicked, [this, removeRouteIdEdit]() {
            int id = removeRouteIdEdit->text().toInt();
            try {
                fleetManager.removeRouteById(id);
                QMessageBox::information(nullptr, "Success", "Route removed.");
            } catch (const RouteNotFoundException &ex) {
                QMessageBox::warning(nullptr, "Error", ex.what());
            }
        });
        removeRouteLayout->addWidget(removeRouteIdEdit);
        removeRouteLayout->addWidget(removeRouteBtn);
        leftPanel->addLayout(removeRouteLayout);
    }

    layout->addLayout(leftPanel);
    return w;
}

QWidget* MainWindow::createTripLogsWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Trip Logs Section"));
    QTableWidget *table = new QTableWidget(5, 4);
    table->setHorizontalHeaderLabels({"Date", "Driver ID", "Vehicle VIN", "Distance"});
    layout->addWidget(table);
    return w;
}

QWidget* MainWindow::createReportsWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Reports:"));
    QPushButton *generateBtn = new QPushButton("Generate Monthly Report");
    connect(generateBtn, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "Report", "Monthly report generated!");
    });
    layout->addWidget(generateBtn);
    return w;
}

QWidget* MainWindow::createCustomerComplaintsWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Customer Complaints:"));
    QTableWidget *table = new QTableWidget(3, 3);
    table->setHorizontalHeaderLabels({"ID", "Complaint", "Status"});
    layout->addWidget(table);

    QPushButton *resolveBtn = new QPushButton("Mark Selected as Resolved");
    connect(resolveBtn, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "Resolved", "Complaint resolved!");
    });
    layout->addWidget(resolveBtn);
    return w;
}

QWidget* MainWindow::createAccountWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Account Management:"));
    QLineEdit *usernameEdit = new QLineEdit; usernameEdit->setPlaceholderText("Username");
    QLineEdit *passwordEdit = new QLineEdit; passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);
    QPushButton *loginBtn = new QPushButton("Login");
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginBtn);

    connect(loginBtn, &QPushButton::clicked, [usernameEdit, passwordEdit]() {
        if (usernameEdit->text() == "admin" && passwordEdit->text() == "admin")
            QMessageBox::information(nullptr, "Login", "Login successful!");
        else
            QMessageBox::warning(nullptr, "Login", "Wrong credentials!");
    });

    return w;
}

QWidget* MainWindow::createFuelConsumptionWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Fuel Consumption Tracking:"));
    QLineEdit *vinEdit = new QLineEdit; vinEdit->setPlaceholderText("Vehicle VIN");
    QPushButton *calcBtn = new QPushButton("Calculate Fuel Consumption");
    connect(calcBtn, &QPushButton::clicked, [vinEdit]() {
        QMessageBox::information(nullptr, "Fuel", "Fuel consumption for VIN "
                                                      + vinEdit->text() + ": 23 L/100km");
    });
    layout->addWidget(vinEdit);
    layout->addWidget(calcBtn);
    return w;
}

QWidget* MainWindow::createRemindersWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Reminders:"));
    QTableWidget *table = new QTableWidget(2, 2);
    table->setHorizontalHeaderLabels({"Reminder", "Due Date"});
    table->setItem(0,0,new QTableWidgetItem("Bus #101 Maintenance"));
    table->setItem(0,1,new QTableWidgetItem("2025-01-10"));
    table->setItem(1,0,new QTableWidgetItem("Truck #102 License Renewal"));
    table->setItem(1,1,new QTableWidgetItem("2025-02-05"));
    layout->addWidget(table);
    return w;
}

QWidget* MainWindow::createInspectionWidget()
{
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(new QLabel("Inspection Records:"));
    QTableWidget *table = new QTableWidget(2, 3);
    table->setHorizontalHeaderLabels({"VIN", "Last Inspection Date", "Status"});
    table->setItem(0,0,new QTableWidgetItem("101"));
    table->setItem(0,1,new QTableWidgetItem("2024-11-20"));
    table->setItem(0,2,new QTableWidgetItem("OK"));
    table->setItem(1,0,new QTableWidgetItem("102"));
    table->setItem(1,1,new QTableWidgetItem("2024-10-15"));
    table->setItem(1,2,new QTableWidgetItem("Needs Follow-Up"));
    layout->addWidget(table);
    return w;
}
