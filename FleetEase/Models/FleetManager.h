#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include <vector>
#include <algorithm>
#include "Vehicle.h"
#include "Driver.h"
#include "Route.h"
#include "FleetException.h"
#include "VehicleNotFoundException.h"

using namespace std;

class FleetManager {
private:
    vector<Vehicle*> vehicles;
    vector<Driver*> drivers;
    vector<Route> routes;

public:
    ~FleetManager() {
        for (Vehicle* v : vehicles) delete v;
        for (Driver* d : drivers) delete d;
    }

    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void addDriver(Driver* d) {
        drivers.push_back(d);
    }

    void addRoute(const Route& r) {
        routes.push_back(r);
    }

    void removeVehicle(int index) {
        if (index >= 0 && index < vehicles.size()) {
            delete vehicles[index];
            vehicles.erase(vehicles.begin() + index);
        } else {
            throw VehicleNotFoundException("Invalid vehicle index for removal.");
        }
    }

    const vector<Vehicle*>& getVehicles() const { return vehicles; }
    const vector<Driver*>& getDrivers() const { return drivers; }
    const vector<Route>& getRoutes() const { return routes; }
};

#endif
