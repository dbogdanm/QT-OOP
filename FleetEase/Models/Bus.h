#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
    int seatingCapacity;

public:
    Bus(string _make, string _model, int _year, double _price, int _seatingCapacity)
        : Vehicle(_make, _model, _year, _price), seatingCapacity(_seatingCapacity) {}

    double calculateToll() override {
        return seatingCapacity * 2.5;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Seating Capacity: " << seatingCapacity << ", Toll: $" << calculateToll() << endl;
    }

    int getSeatingCapacity() const { return seatingCapacity; }
};

#endif
