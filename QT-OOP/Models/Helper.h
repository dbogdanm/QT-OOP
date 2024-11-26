// Helper.h
#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>
#include "Driver.h"
#include "Vehicle.h"
#include "Route.h"

using namespace std;
namespace fs = std::filesystem;

class Helper
{
public:
    // Metode pentru Șoferi
    static vector<Driver> ReadDriverFromFile();
    static void AddDriverToFile(const string& driverName);
    static void RemoveDriverFromFile(const string& driverName);

    // Metode pentru Vehicule
    static vector<Vehicle> ReadVehicleFromFile();
    static void AddVehicleToFile(const string& vehicleVin);
    static void RemoveVehicleFromFile(const string& vehicleVin);

    // Metode pentru Rute
    static vector<Route> ReadRouteFromFile();
    static void AddRouteToFile(const string& routeId);
    static void RemoveRouteFromFile(const string& routeId);

private:
    // Căi către fișiere
    static const fs::path DriverFilePath;
    static const string DriverFileNotFound;
    static const string DriverReadError;

    static const fs::path VehicleFilePath;
    static const string VehicleFileNotFound;
    static const string VehicleReadError;

    static const fs::path RouteFilePath;
    static const string RouteFileNotFound;
    static const string RouteReadError;
};

#endif // HELPER_H
