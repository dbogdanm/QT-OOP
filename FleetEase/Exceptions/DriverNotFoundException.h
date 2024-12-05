#ifndef DRIVERNOTFOUNDEXCEPTION_H
#define DRIVERNOTFOUNDEXCEPTION_H

#include "FleetException.h"

/**
 * @class DriverNotFoundException
 * @brief Exception thrown when a driver is not found in the fleet system.
 *
 * This exception inherits from the FleetException base class and is used to
 * indicate that a specific driver, identified by their unique ID, cannot be
 * located in the fleet system.
 */
class DriverNotFoundException : public FleetException
{
public:
    /**
     * @brief Constructs a DriverNotFoundException with the specified driver ID.
     *
     * @param driverId The unique ID of the driver that could not be found.
     *
     * The constructor initializes the exception with a custom error message that
     * includes the driver's ID for easier debugging.
     */
    explicit DriverNotFoundException(int driverId)
        : FleetException("Driver with ID " + std::to_string(driverId) + " not found.") {}
};

#endif
