#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMdiArea>
#include <QWidget>
#include <QString>
#include "Models/FleetManager.h"
#include "Exceptions/DriverNotFoundException.h"
#include "Exceptions/FleetException.h"
#include "Exceptions/RouteNotFoundException.h"
#include "Exceptions/VehicleNotFoundException.h"

// Forward declarations if needed
class FleetManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(const QString &username, QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Functions declared here must match definitions in .cpp
    void createMenus();
    void createToolBar();
    void createPages();

    void showDashboard();
    void showFleetWindow();
    void showManageWindow();
    void showTripLogsWindow();
    void showReportsWindow();
    void showCustomerComplaintsWindow();
    void showAccountWindow();
    void showFuelConsumptionWindow();
    void showRemindersWindow();
    void showInspectionWindow();

    // Widget creation helper methods
    QWidget* createFleetWidget();
    QWidget* createManageWidget();
    QWidget* createTripLogsWidget();
    QWidget* createReportsWidget();
    QWidget* createCustomerComplaintsWidget();
    QWidget* createAccountWidget();
    QWidget* createFuelConsumptionWidget();
    QWidget* createRemindersWidget();
    QWidget* createInspectionWidget();

private:
    QString m_username;          // Must be declared if used in constructor
    QStackedWidget *stackedWidget;
    QWidget *dashboardPage;
    QWidget *mdiPage;
    QMdiArea *mdiArea;

    FleetManager fleetManager;
};

#endif // MAINWINDOW_H
