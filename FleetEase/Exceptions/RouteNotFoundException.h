#ifndef ROUTENOTFOUNDEXCEPTION_H
#define ROUTENOTFOUNDEXCEPTION_H

#include "FleetException.h"

/**
 * @class RouteNotFoundException
 * @brief Exception thrown when a route cannot be found in the fleet system.
 *
 * This exception is used to indicate that a specific route, identified by its unique ID,
 * does not exist or cannot be located in the fleet management system.
 */
class RouteNotFoundException : public FleetException
{
public:
    /**
     * @brief Constructs a RouteNotFoundException with the specified route ID.
     *
     * @param routeId The unique ID of the route that could not be found.
     *
     * Initializes the exception with a custom error message that includes the
     * route's ID for debugging purposes.
     */
    explicit RouteNotFoundException(int routeId)
        : FleetException("Route with ID " + std::to_string(routeId) + " not found.") {}
};

#endif
