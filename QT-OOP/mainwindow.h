// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Sloturi pentru butoanele principale
    void onFleetClicked();
    void onManageClicked();
    void onTripLogsClicked();
    void onReportsClicked();
    void onCustomerComplaintsClicked();
    void onAccountClicked();

    // Sloturi pentru butoanele de gestionare
    void onAddDriverClicked();
    void onRemoveDriverClicked();
    void onAddVehicleClicked();
    void onRemoveVehicleClicked();
    void onAddRouteClicked();
    void onRemoveRouteClicked();

    // Sloturi pentru confirmarea acțiunilor
    void onConfirmAddDriver();
    void onConfirmRemoveDriver();
    void onConfirmAddVehicle();
    void onConfirmRemoveVehicle();
    void onConfirmAddRoute();
    void onConfirmRemoveRoute();

private:
    // Butoane principale
    QPushButton *fleetButton;
    QPushButton *manageButton;
    QPushButton *tripLogsButton;
    QPushButton *reportsButton;
    QPushButton *customerComplaintsButton;
    QPushButton *accountButton;

    // Butoane de gestionare
    QPushButton *addDriverButton;
    QPushButton *removeDriverButton;
    QPushButton *addVehicleButton;
    QPushButton *removeVehicleButton;
    QPushButton *addRouteButton;
    QPushButton *removeRouteButton;

    // Câmpuri de text și butoane de confirmare pentru fiecare acțiune
    QLineEdit *addDriverInput;
    QPushButton *confirmAddDriverButton;

    QLineEdit *removeDriverInput;
    QPushButton *confirmRemoveDriverButton;

    QLineEdit *addVehicleInput;
    QPushButton *confirmAddVehicleButton;

    QLineEdit *removeVehicleInput;
    QPushButton *confirmRemoveVehicleButton;

    QLineEdit *addRouteInput;
    QPushButton *confirmAddRouteButton;

    QLineEdit *removeRouteInput;
    QPushButton *confirmRemoveRouteButton;

    // Zona de afișare a datelor flotei
    QTextEdit *fleetDisplay;

    // Layout-uri principale
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *mainLayout;
    QWidget *centralWidget;
    QWidget *manageWidget;

    // Funcții auxiliare
    void setupUI();
    void showManageOptions(bool show);
    void displayFleetData();

    // Funcții pentru gestionarea fișierelor
    void addDriverToFile(const QString &driverName);
    void removeDriverFromFile(const QString &driverName);
    void addVehicleToFile(const QString &vehicleVin);
    void removeVehicleFromFile(const QString &vehicleVin);
    void addRouteToFile(const QString &routeId);
    void removeRouteFromFile(const QString &routeId);
};

#endif // MAINWINDOW_H
