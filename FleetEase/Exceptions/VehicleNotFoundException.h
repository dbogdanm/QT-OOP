#ifndef VEHICLENOTFOUNDEXCEPTION_H
#define VEHICLENOTFOUNDEXCEPTION_H

#include "FleetException.h"

/**
 * @class VehicleNotFoundException
 * @brief Exception thrown when a vehicle cannot be found in the fleet system.
 *
 * This exception is used to indicate that a specific vehicle, identified by its unique VIN
 * (Vehicle Identification Number), does not exist or cannot be located in the fleet management system.
 */
class VehicleNotFoundException : public FleetException
{
public:
    /**
     * @brief Constructs a VehicleNotFoundException with the specified VIN.
     *
     * @param vin The unique Vehicle Identification Number of the vehicle that could not be found.
     *
     * Initializes the exception with a custom error message that includes the
     * vehicle's VIN for debugging purposes.
     */
    explicit VehicleNotFoundException(int vin)
        : FleetException("Vehicle with VIN " + std::to_string(vin) + " not found.") {}
};

#endif
