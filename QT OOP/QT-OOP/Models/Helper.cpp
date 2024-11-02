#include "Models\Helper.h"


const fs::path Helper::DriverFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Driver.txt)";
const string Helper::DriverFileNotFound = "Driver.txt not found";
const string Helper::DriverReadError = "Error while reading from Driver.txt";
const string Helper::RouteReadError = "Error while reading from Routes.txt";
const string Helper::RouteFileNotFound = "Routes.txt not found";
const fs::path Helper::RouteFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Routes.txt)";
const fs::path Helper::VehicleFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Vehicle.txt)";
const string Helper::VehicleFileNotFound = "Vehicle.txt not found";
const string Helper::VehicleReadError = "Error while reading from Vehicle.txt";


vector<Driver> Helper::ReadDriverFromFile()
{
    ifstream file(DriverFilePath);
    if (!file)
    {
        cout << DriverFileNotFound << endl;
        return {};
    }

    vector<Driver> drivers;
    int numberOfDrivers;
    file >> numberOfDrivers;

    for (int i = 0; i < numberOfDrivers; i++)
    {
        int id, numberOfHours;
        string name, phone;
        if (file >> id >> name >> phone >> numberOfHours)
        {
            drivers.emplace_back(id, name, phone, numberOfHours);
        }
        else
        {
            cout << DriverReadError << " at line " << i + 1 << endl;
        }
    }

    file.close();
    return drivers;
}

vector<Route> Helper::ReadRouteFromFile()
{
    ifstream file(RouteFilePath);
    if (!file)
    {
        cout << RouteFileNotFound << endl;
        return {};
    }

    vector<Route> routes;
    int numberOfRoutes;
    file >> numberOfRoutes;

    for (int i = 0; i < numberOfRoutes; i++)
    {
        int id, distance;
        string startingPoint, endingPoint;
        if (file >> id >> distance >> startingPoint >> endingPoint)
        {
            routes.emplace_back(id, distance, startingPoint, endingPoint);
        }
        else
        {
            cout << RouteReadError << " at line " << i + 1 << endl;
        }
    }

    file.close();
    return routes;
}

vector<Vehicle> Helper::ReadVehicleFromFile()
{
    ifstream file(VehicleFilePath);
    if (!file)
    {
        cout << VehicleFileNotFound << endl;
        return {};
    }

    vector<Vehicle> vehicles;
    int numberOfVehicles;
    file >> numberOfVehicles;

    for (int i = 0; i < numberOfVehicles; i++)
    {
        int id, kilometers;
        string brand, model;
        if (file >> id >> model >> kilometers >> brand)
        {
            vehicles.emplace_back(id, model, kilometers, brand);
        }
        else
        {
            cout << VehicleReadError << " at line " << i + 1 << endl;
        }
    }

    file.close();
    return vehicles;
}
