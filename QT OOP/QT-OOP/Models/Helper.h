#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include "Driver.h"
#include "Vehicle.h"
#include "Route.h"

using namespace std;
namespace fs = filesystem;

class Helper
{
public:
    static vector<Driver> ReadDriverFromFile();
    static vector<Route> ReadRouteFromFile();
    static vector<Vehicle> ReadVehicleFromFile();

private:
    static const fs::path DriverFilePath;
    static const string DriverFileNotFound;
    static const string DriverReadError;
    static const string RouteReadError;
    static const string RouteFileNotFound;
    static const fs::path RouteFilePath;
    static const fs::path VehicleFilePath;
    static const string VehicleFileNotFound;
    static const string VehicleReadError;
};

#endif // HELPER_H
