#include "Models\Helper.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <QInputDialog>


const fs::path Helper::DriverFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Driver.txt)";
const string Helper::DriverFileNotFound = "Driver.txt not found";
const string Helper::DriverReadError = "Error while reading from Driver.txt";
const string Helper::RouteReadError = "Error while reading from Routes.txt";
const string Helper::RouteFileNotFound = "Routes.txt not found";
const fs::path Helper::RouteFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Routes.txt)";
const fs::path Helper::VehicleFilePath = R"(C:\Users\ripip\Desktop\QT OOP\QT-OOP\Vehicle.txt)";
const string Helper::VehicleFileNotFound = "Vehicle.txt not found";
const string Helper::VehicleReadError = "Error while reading from Vehicle.txt";

void Helper::AddDriverToFile(const string& driverName)
{
    std::ofstream outFile(DriverFilePath, std::ios::app);
    if(outFile.is_open())
    {
        outFile << driverName << "\n";
        outFile.close();
    }
}

void Helper::RemoveDriverFromFile(const string& driverName)
{
    std::vector<Driver> drivers = ReadDriverFromFile();
    std::ofstream outFile(DriverFilePath, std::ios::trunc);

    if(outFile.is_open())
    {
        for(const auto& driver : drivers)
        {
            // Presupunem că Driver are o funcție getName() care returnează numele ca string
            if(driver.getName() != driverName)
            {
                outFile << driver.GetId() << " " << driver.getName() << " "
                        << driver.getPhone() << " " << driver.getNumberOfHours() << "\n";
            }
        }

        outFile.close();
    }
}

std::vector<Driver> Helper::ReadDriverFromFile()
{
    std::ifstream file(DriverFilePath);
    if (!file)
    {
        std::cout << DriverFileNotFound << std::endl;
        return {};
    }

    std::vector<Driver> drivers;
    int numberOfDrivers;
    file >> numberOfDrivers;

    for (int i = 0; i < numberOfDrivers; i++)
    {
        int id, numberOfHours;
        std::string name, phone;
        if (file >> id >> name >> phone >> numberOfHours)
        {
            drivers.emplace_back(id, name, phone, numberOfHours);
        }
        else
        {
            std::cout << DriverReadError << " at line " << i + 1 << std::endl;
        }
    }

    file.close();
    return drivers;
}

std::vector<Route> Helper::ReadRouteFromFile()
{
    std::ifstream file(RouteFilePath);
    if (!file)
    {
        std::cout << RouteFileNotFound << std::endl;
        return {};
    }

    std::vector<Route> routes;
    int numberOfRoutes;
    file >> numberOfRoutes;

    for (int i = 0; i < numberOfRoutes; i++)
    {
        int id, distance;
        std::string startingPoint, endingPoint;
        if (file >> id >> distance >> startingPoint >> endingPoint)
        {
            routes.emplace_back(id, distance, startingPoint, endingPoint);
        }
        else
        {
            std::cout << RouteReadError << " at line " << i + 1 << std::endl;
        }
    }

    file.close();
    return routes;
}

std::vector<Vehicle> Helper::ReadVehicleFromFile()
{
    std::ifstream file(VehicleFilePath);
    if (!file)
    {
        std::cout << VehicleFileNotFound << std::endl;
        return {};
    }

    std::vector<Vehicle> vehicles;
    int numberOfVehicles;
    file >> numberOfVehicles;

    for (int i = 0; i < numberOfVehicles; i++)
    {
        int id, kilometers;
        std::string brand, model;
        if (file >> id >> model >> kilometers >> brand)
        {
            vehicles.emplace_back(id, model, kilometers, brand);
        }
        else
        {
            std::cout << VehicleReadError << " at line " << i + 1 << std::endl;
        }
    }

    file.close();
    return vehicles;
}
