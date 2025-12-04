#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>

using namespace std;

class Route {
private:
    string source;
    string destination;
    double distance;

public:
    Route(string _source, string _destination, double _distance)
        : source(_source), destination(_destination), distance(_distance) {}

    void displayRoute() {
        cout << "Source: " << source << ", Destination: " << destination 
             << ", Distance: " << distance << " km" << endl;
    }

    string getSource() const { return source; }
    string getDestination() const { return destination; }
    double getDistance() const { return distance; }
};

#endif
