#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <memory>
#include "Driver.h"
#include "Route.h"
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"

/**
 * @class Helper
 * @brief Provides utility methods for initializing fleet data.
 *
 * The Helper class contains static methods that return predefined collections
 * of drivers, routes, and vehicles. These methods simulate reading data from files
 * and provide sample data for testing or initialization purposes.
 */
class Helper {
public:
    /**
     * @brief Reads a predefined list of drivers.
     *
     * Simulates reading driver data from a file and returns a list of drivers
     * with predefined information.
     *
     * @return A vector of Driver objects.
     */
    static std::vector<Driver> ReadDriverFromFile()
    {
        return
        {
            Driver(1, "Hunter Biden", "0713456791", 347),
            Driver(2, "Bradley Carter", "0787654321", 118)
        };
    }

    /**
     * @brief Reads a predefined list of routes.
     *
     * Simulates reading route data from a file and returns a list of routes
     * with predefined information.
     *
     * @return A vector of Route objects.
     */
    static std::vector<Route> ReadRouteFromFile()
    {
        return
        {
            Route(1, 148, "Ramnicu-Sarat", "Bucharest"),
            Route(2, 305, "Suceava", "Cluj")
        };
    }

    /**
     * @brief Reads a predefined list of vehicles.
     *
     * Simulates reading vehicle data from a file and returns a list of vehicles
     * with predefined information. The vehicles are stored as unique pointers.
     *
     * @return A vector of unique pointers to Vehicle objects.
     */
    static std::vector<std::unique_ptr<Vehicle>> ReadVehicleFromFile()
    {
        std::vector<std::unique_ptr<Vehicle>> vehicles;
        vehicles.emplace_back(std::make_unique<Bus>(101, "Citaro", 345000, "Mercedes-Benz", 73, false));
        vehicles.emplace_back(std::make_unique<Truck>(102, "S-Series", 320000, "Scania", 21, 38));
        vehicles.emplace_back(std::make_unique<Motorcycle>(103, "Primavera", 1000, "Vespa", 125.0, false));
        return vehicles;
    }
};

#endif
