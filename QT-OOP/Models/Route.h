// Route.h
#ifndef ROUTE_H
#define ROUTE_H
#include <string>
#include <utility>
#include <iostream>
using namespace std;

class Route
{
private:
    int id;
    int distance;
    string startingPoint;
    string endingPoint;

public:
    Route(int id, int distance, string starting_point, string ending_point)
        : id(id),
        distance(distance),
        startingPoint(std::move(starting_point)),
        endingPoint(std::move(ending_point))
    {
    }

    Route(const Route &other)
    {
        id = other.id;
        distance = other.distance;
        startingPoint = other.startingPoint;
        endingPoint = other.endingPoint;
    }

    Route& operator=(const Route &other)
    {
        id = other.id;
        distance = other.distance;
        startingPoint = other.startingPoint;
        endingPoint = other.endingPoint;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Route& route)
    {
        os << "Route id: " << route.id << "\n";
        os << "Route distance: " << route.distance << "\n";
        os << "Route starting point: " << route.startingPoint << "\n";
        os << "Route ending point: " << route.endingPoint << "\n";
        return os;
    }

    bool operator==(const Route& other) const
    {
        return id == other.id && distance == other.distance && startingPoint == other.startingPoint && endingPoint == other.endingPoint;
    }

    int GetId() const
    {
        return id;
    }

    int getDistance() const { return distance; }
    string getStartingPoint() const { return startingPoint; }
    string getEndingPoint() const { return endingPoint; }

    ~Route()= default;

};

#endif //ROUTE_H
