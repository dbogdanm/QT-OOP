#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H
#include <iostream>
#include <vector>
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
using namespace std;

class FleetManager
{
private:
    vector<Driver> drivers;
    vector<Vehicle> vehicles;
    vector<Route> routes;

public:
    FleetManager(const vector<Driver> &drivers, const vector<Vehicle> &vehicles, const vector<Route> &routes)
        : drivers(drivers),
          vehicles(vehicles),
          routes(routes)
    {
    }

    friend ostream& operator<<(ostream& os, const FleetManager& fleetManager)
    {
        os << "Drivers:" << endl;
        for (const Driver& driver : fleetManager.drivers)
            os << driver << endl;

        os << "Vehicles:" << endl;
        for (const Vehicle& vehicle : fleetManager.vehicles)
            os << vehicle << endl;

        os << "Routes:" << endl;
        for (const Route& route : fleetManager.routes)
            os << route << endl;

        return os;
    }

    ~FleetManager() = default;
    //vector is already self managing its memory

};

#endif //FLEETMANAGER_H
