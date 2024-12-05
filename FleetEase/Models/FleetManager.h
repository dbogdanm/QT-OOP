#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Exceptions/DriverNotFoundException.h".h"
#include "Exceptions/FleetException.h"
#include "Exceptions/RouteNotFoundException.h"
#include "Exceptions/VehicleNotFoundException.h"

/**
 * @class FleetManager
 * @brief Manages the fleet system including drivers, vehicles, and routes.
 *
 * The FleetManager class provides functionality for managing a fleet, which
 * includes adding, removing, and displaying drivers, vehicles, and routes. It
 * supports dynamic memory management for vehicles and ensures deep copies are made
 * for safe object handling.
 */
class FleetManager
{
private:
    /**
     * @brief List of drivers managed by the fleet.
     */
    std::vector<Driver> drivers;

    /**
     * @brief List of vehicles managed by the fleet, stored as unique pointers.
     */
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    /**
     * @brief List of routes managed by the fleet.
     */
    std::vector<Route> routes;

public:
    /**
     * @brief Constructs a FleetManager with the specified lists of drivers, vehicles, and routes.
     *
     * @param drivers A list of drivers to initialize the fleet with.
     * @param vehicles A list of unique pointers to vehicles to initialize the fleet with.
     * @param routes A list of routes to initialize the fleet with.
     */
    FleetManager(std::vector<Driver> drivers,
                 std::vector<std::unique_ptr<Vehicle>> vehicles,
                 std::vector<Route> routes)
        : drivers(std::move(drivers)),
          vehicles(std::move(vehicles)),
          routes(std::move(routes)) {}

    FleetManager() = default;

    /**
     * @brief Copy constructor for FleetManager.
     *
     * Creates a deep copy of the given FleetManager, ensuring that each vehicle
     * is cloned properly.
     *
     * @param other The FleetManager object to copy.
     */
    FleetManager(const FleetManager& other)
    {
        drivers = other.drivers;
        vehicles.clear();
        for (const auto& v : other.vehicles)
        {
            vehicles.emplace_back(v->clone());
        }
        routes = other.routes;
    }

    /**
     * @brief Copy assignment operator for FleetManager.
     *
     * Performs a deep copy of another FleetManager object using the copy-and-swap idiom.
     *
     * @param other The FleetManager object to assign from.
     * @return A reference to the assigned FleetManager object.
     */
    FleetManager& operator=(FleetManager other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two FleetManager objects.
     *
     * Used for implementing the copy-and-swap idiom.
     *
     * @param first The first FleetManager object.
     * @param second The second FleetManager object.
     */
    friend void swap(FleetManager& first, FleetManager& second) noexcept
    {
        using std::swap;
        swap(first.drivers, second.drivers);
        swap(first.vehicles, second.vehicles);
        swap(first.routes, second.routes);
    }

    /**
     * @brief Destroys the FleetManager object.
     */
    ~FleetManager() = default;

    /**
     * @brief Adds a driver to the fleet.
     *
     * @param driver The driver to add.
     */
    void addDriver(const Driver& driver)
    {
        drivers.push_back(driver);
    }

    /**
     * @brief Removes a driver by their ID.
     *
     * @param id The ID of the driver to remove.
     * @throws DriverNotFoundException If the driver with the given ID is not found.
     */
    void removeDriverById(int id)
    {
        auto it = std::remove_if(drivers.begin(), drivers.end(),
                                 [id](const Driver& d)
                                 {
                                     return d.getId() == id;
                                 });
        if (it == drivers.end())
        {
            throw DriverNotFoundException(id);
        }
        drivers.erase(it, drivers.end());
    }

    /**
     * @brief Adds a route to the fleet.
     *
     * @param route The route to add.
     */
    void addRoute(const Route& route)
    {
        routes.push_back(route);
    }

    /**
     * @brief Removes a route by its ID.
     *
     * @param id The ID of the route to remove.
     * @throws RouteNotFoundException If the route with the given ID is not found.
     */
    void removeRouteById(int id)
    {
        auto it = std::remove_if(routes.begin(), routes.end(),
                                 [id](const Route& r)
                                 {
                                     return r.getId() == id;
                                 });
        if (it == routes.end())
        {
            throw RouteNotFoundException(id);
        }
        routes.erase(it, routes.end());
    }

    /**
     * @brief Adds a vehicle to the fleet.
     *
     * @param vehicle A unique pointer to the vehicle to add.
     */
    void addVehicle(std::unique_ptr<Vehicle> vehicle)
    {
        vehicles.emplace_back(std::move(vehicle));
    }

    /**
     * @brief Removes a vehicle by its VIN.
     *
     * @param vin The VIN of the vehicle to remove.
     * @throws VehicleNotFoundException If the vehicle with the given VIN is not found.
     */
    void removeVehicleByVin(int vin)
    {
        auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                                 [vin](const std::unique_ptr<Vehicle>& v)
                                 {
                                     return v->getVin() == vin;
                                 });
        if (it == vehicles.end())
        {
            throw VehicleNotFoundException(vin);
        }
        vehicles.erase(it, vehicles.end());
    }

    /**
     * @brief Displays detailed information about the fleet.
     *
     * Outputs information about drivers, vehicles (with dynamic type details),
     * and routes to the console.
     */
    void displayFleet() const
    {
        std::cout << "=== Fleet Information ===" << std::endl;
        std::cout << "\nDrivers:" << std::endl;

        for (const auto& driver : drivers)
        {
            driver.display();
        }

        std::cout << "\nVehicles:" << std::endl;

        for (const auto& vehicle : vehicles)
        {
            vehicle->display();

            if (auto bus = dynamic_cast<Bus*>(vehicle.get()))
            {
                std::cout << "This is a Bus with seating capacity: " << bus->getSeatingCapacity() << std::endl;
            }
            else if (auto truck = dynamic_cast<Truck*>(vehicle.get()))
            {
                std::cout << "This is a Truck with load capacity of: " << truck->getLoadCapacity() << " tons" << std::endl;
            }
            else if (auto motorcycle = dynamic_cast<Motorcycle*>(vehicle.get()))
            {
                std::cout << "This is a Motorcycle with engine displacement: " << motorcycle->getEngineDisplacement() << "cc" << std::endl;
            }
        }

        std::cout << "\nRoutes:" << std::endl;

        for (const auto& route : routes)
        {
            route.display();
        }

        std::cout << "===============================" << std::endl;
    }
};

#endif // FLEETMANAGER_H
