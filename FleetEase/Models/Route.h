#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>
#include <utility>

/**
 * @class Route
 * @brief Represents a route with details about its distance and endpoints.
 *
 * The Route class encapsulates information about a transportation route, including
 * its unique ID, distance, starting point, and ending point. It provides methods
 * for displaying the route and accessing its attributes.
 */
class Route
{
private:
    /**
     * @brief Unique ID of the route.
     */
    int id;

    /**
     * @brief Distance of the route in kilometers.
     */
    int distance;

    /**
     * @brief Starting point of the route.
     */
    std::string startingPoint;

    /**
     * @brief Ending point of the route.
     */
    std::string endingPoint;

public:
    /**
     * @brief Constructs a Route with the specified details.
     *
     * @param id The unique ID of the route.
     * @param distance The distance of the route in kilometers.
     * @param startingPoint The name of the starting point.
     * @param endingPoint The name of the ending point.
     */
    Route(int id, int distance, std::string startingPoint, std::string endingPoint)
        : id(id), distance(distance), startingPoint(std::move(startingPoint)), endingPoint(std::move(endingPoint)) {}

    /**
     * @brief Copy constructor for Route.
     *
     * Creates a copy of the given Route object.
     *
     * @param other The Route object to copy.
     */
    Route(const Route& other)
        : id(other.id), distance(other.distance),
          startingPoint(other.startingPoint), endingPoint(other.endingPoint) {}

    /**
     * @brief Copy assignment operator for Route.
     *
     * Performs a deep copy of another Route object using the copy-and-swap idiom.
     *
     * @param other The Route object to assign from.
     * @return A reference to the assigned Route object.
     */
    Route& operator=(Route other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Route objects.
     *
     * Used for implementing the copy-and-swap idiom.
     *
     * @param first The first Route object.
     * @param second The second Route object.
     */
    friend void swap(Route& first, Route& second) noexcept
    {
        using std::swap;
        swap(first.id, second.id);
        swap(first.distance, second.distance);
        swap(first.startingPoint, second.startingPoint);
        swap(first.endingPoint, second.endingPoint);
    }

    /**
     * @brief Gets the ID of the route.
     *
     * @return The unique ID of the route.
     */
    [[nodiscard]] int getId() const
    {
        return id;
    }

    /**
     * @brief Displays detailed information about the route.
     *
     * Outputs the route's ID, distance, starting point, and ending point to the console.
     */
    void display() const
    {
        std::cout << "Route ID: " << id << ", Distance: " << distance
                  << " km, From: " << startingPoint << " To: " << endingPoint << std::endl;
    }
};

#endif
