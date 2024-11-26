// Helper.cpp
#include "Models\Helper.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// Definirea constantelor
const fs::path Helper::DriverFilePath = R"(C:\Users\gicap\OneDrive\Desktop\QT OOP\Driver.txt)";
const string Helper::DriverFileNotFound = "Driver.txt not found";
const string Helper::DriverReadError = "Error while reading from Driver.txt";

const fs::path Helper::VehicleFilePath = R"(C:\Users\gicap\OneDrive\Desktop\QT OOP\Vehicle.txt)";
const string Helper::VehicleFileNotFound = "Vehicle.txt not found";
const string Helper::VehicleReadError = "Error while reading from Vehicle.txt";

const fs::path Helper::RouteFilePath = R"(C:\Users\gicap\OneDrive\Desktop\QT OOP\Routes.txt)";
const string Helper::RouteFileNotFound = "Routes.txt not found";
const string Helper::RouteReadError = "Error while reading from Routes.txt";

// Funcții pentru Șoferi
vector<Driver> Helper::ReadDriverFromFile()
{
    std::ifstream file(DriverFilePath);
    if (!file)
    {
        std::cout << DriverFileNotFound << std::endl;
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
            std::cout << DriverReadError << " at driver " << i + 1 << std::endl;
            // Omitere a șoferului invalid
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    file.close();
    return drivers;
}

void Helper::AddDriverToFile(const string& driverName)
{
    // Citirea șoferilor existenți
    vector<Driver> drivers = ReadDriverFromFile();

    // Generarea unui nou ID
    int newId = 1;
    for (const auto& driver : drivers)
    {
        if (driver.GetId() >= newId)
            newId = driver.GetId() + 1;
    }

    // Crearea unui nou șofer cu date implicite pentru telefon și ore
    Driver newDriver(newId, driverName, "N/A", 0);
    drivers.push_back(newDriver);

    // Scrierea înapoi a tuturor șoferilor cu actualizarea numărului
    std::ofstream outFile(DriverFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << drivers.size() << "\n";
        for(const auto& driver : drivers)
        {
            outFile << driver.GetId() << " " << driver.getName() << " "
                    << driver.getPhone() << " " << driver.getNumberOfHours() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Driver.txt for writing." << std::endl;
    }
}

void Helper::RemoveDriverFromFile(const string& driverName)
{
    vector<Driver> drivers = ReadDriverFromFile();
    vector<Driver> updatedDrivers;

    bool found = false;
    for(const auto& driver : drivers)
    {
        if(driver.getName() != driverName)
        {
            updatedDrivers.push_back(driver);
        }
        else
        {
            found = true;
        }
    }

    if(!found)
    {
        std::cout << "Driver not found: " << driverName << std::endl;
        return;
    }

    // Scrierea înapoi a tuturor șoferilor cu actualizarea numărului
    std::ofstream outFile(DriverFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << updatedDrivers.size() << "\n";
        for(const auto& driver : updatedDrivers)
        {
            outFile << driver.GetId() << " " << driver.getName() << " "
                    << driver.getPhone() << " " << driver.getNumberOfHours() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Driver.txt for writing." << std::endl;
    }
}

// Funcții pentru Vehicule
vector<Vehicle> Helper::ReadVehicleFromFile()
{
    std::ifstream file(VehicleFilePath);
    if (!file)
    {
        std::cout << VehicleFileNotFound << std::endl;
        return {};
    }

    vector<Vehicle> vehicles;
    int numberOfVehicles;
    file >> numberOfVehicles;

    for (int i = 0; i < numberOfVehicles; i++)
    {
        int vin, kilometers;
        string model, brand;
        if (file >> vin >> model >> kilometers >> brand)
        {
            vehicles.emplace_back(vin, model, kilometers, brand);
        }
        else
        {
            std::cout << VehicleReadError << " at vehicle " << i + 1 << std::endl;
            // Omitere a vehiculului invalid
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    file.close();
    return vehicles;
}

void Helper::AddVehicleToFile(const string& vehicleVin)
{
    // Convertire VIN din string la int
    int vin;
    try
    {
        vin = stoi(vehicleVin);
    }
    catch(const invalid_argument& e)
    {
        std::cerr << "Invalid VIN format: " << vehicleVin << std::endl;
        return;
    }

    // Citirea vehiculelor existente
    vector<Vehicle> vehicles = ReadVehicleFromFile();

    // Verificarea dacă VIN-ul există deja
    for(const auto& vehicle : vehicles)
    {
        if(vehicle.GetVin() == vin)
        {
            std::cerr << "Vehicle with VIN " << vin << " already exists." << std::endl;
            return;
        }
    }

    // Crearea unui nou vehicul cu date implicite pentru model și brand
    Vehicle newVehicle(vin, "N/A", 0, "N/A");
    vehicles.push_back(newVehicle);

    // Scrierea înapoi a tuturor vehiculelor cu actualizarea numărului
    std::ofstream outFile(VehicleFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << vehicles.size() << "\n";
        for(const auto& vehicle : vehicles)
        {
            outFile << vehicle.GetVin() << " " << vehicle.getModel() << " "
                    << vehicle.getKilometers() << " " << vehicle.getBrand() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Vehicle.txt for writing." << std::endl;
    }
}

void Helper::RemoveVehicleFromFile(const string& vehicleVin)
{
    // Convertire VIN din string la int
    int vin;
    try
    {
        vin = stoi(vehicleVin);
    }
    catch(const invalid_argument& e)
    {
        std::cerr << "Invalid VIN format: " << vehicleVin << std::endl;
        return;
    }

    vector<Vehicle> vehicles = ReadVehicleFromFile();
    vector<Vehicle> updatedVehicles;

    bool found = false;
    for(const auto& vehicle : vehicles)
    {
        if(vehicle.GetVin() != vin)
        {
            updatedVehicles.push_back(vehicle);
        }
        else
        {
            found = true;
        }
    }

    if(!found)
    {
        std::cout << "Vehicle VIN not found: " << vin << std::endl;
        return;
    }

    // Scrierea înapoi a tuturor vehiculelor cu actualizarea numărului
    std::ofstream outFile(VehicleFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << updatedVehicles.size() << "\n";
        for(const auto& vehicle : updatedVehicles)
        {
            outFile << vehicle.GetVin() << " " << vehicle.getModel() << " "
                    << vehicle.getKilometers() << " " << vehicle.getBrand() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Vehicle.txt for writing." << std::endl;
    }
}

// Funcții pentru Rute
vector<Route> Helper::ReadRouteFromFile()
{
    std::ifstream file(RouteFilePath);
    if (!file)
    {
        std::cout << RouteFileNotFound << std::endl;
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
            std::cout << RouteReadError << " at route " << i + 1 << std::endl;
            // Omitere a rutei invalide
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    file.close();
    return routes;
}

void Helper::AddRouteToFile(const string& routeId)
{
    // Convertire Route ID din string la int
    int id;
    try
    {
        id = stoi(routeId);
    }
    catch(const invalid_argument& e)
    {
        std::cerr << "Invalid Route ID format: " << routeId << std::endl;
        return;
    }

    // Citirea rutelor existente
    vector<Route> routes = ReadRouteFromFile();

    // Verificarea dacă ID-ul rutelor există deja
    for(const auto& route : routes)
    {
        if(route.GetId() == id)
        {
            std::cerr << "Route with ID " << id << " already exists." << std::endl;
            return;
        }
    }

    // Crearea unei noi rute cu date implicite pentru distanță și punctele de plecare/arrivare
    Route newRoute(id, 0, "N/A", "N/A");
    routes.push_back(newRoute);

    // Scrierea înapoi a tuturor rutelor cu actualizarea numărului
    std::ofstream outFile(RouteFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << routes.size() << "\n";
        for(const auto& route : routes)
        {
            outFile << route.GetId() << " " << route.getDistance() << " "
                    << route.getStartingPoint() << " " << route.getEndingPoint() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Routes.txt for writing." << std::endl;
    }
}

void Helper::RemoveRouteFromFile(const string& routeId)
{
    // Convertire Route ID din string la int
    int id;
    try
    {
        id = stoi(routeId);
    }
    catch(const invalid_argument& e)
    {
        std::cerr << "Invalid Route ID format: " << routeId << std::endl;
        return;
    }

    vector<Route> routes = ReadRouteFromFile();
    vector<Route> updatedRoutes;

    bool found = false;
    for(const auto& route : routes)
    {
        if(route.GetId() != id)
        {
            updatedRoutes.push_back(route);
        }
        else
        {
            found = true;
        }
    }

    if(!found)
    {
        std::cout << "Route ID not found: " << id << std::endl;
        return;
    }

    // Scrierea înapoi a tuturor rutelor cu actualizarea numărului
    std::ofstream outFile(RouteFilePath, std::ios::trunc);
    if(outFile.is_open())
    {
        outFile << updatedRoutes.size() << "\n";
        for(const auto& route : updatedRoutes)
        {
            outFile << route.GetId() << " " << route.getDistance() << " "
                    << route.getStartingPoint() << " " << route.getEndingPoint() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open Routes.txt for writing." << std::endl;
    }
}
