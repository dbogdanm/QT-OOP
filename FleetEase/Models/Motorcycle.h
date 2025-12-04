#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    int engineCapacity;

public:
    Motorcycle(string _make, string _model, int _year, double _price, int _engineCapacity)
        : Vehicle(_make, _model, _year, _price), engineCapacity(_engineCapacity) {}

    double calculateToll() override {
        return (engineCapacity > 500) ? 10.0 : 5.0;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Engine Capacity: " << engineCapacity << "cc, Toll: $" << calculateToll() << endl;
    }

    int getEngineCapacity() const { return engineCapacity; }
};

#endif
