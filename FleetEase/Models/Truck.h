#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    int axles;

public:
    Truck(string _make, string _model, int _year, double _price, int _axles)
        : Vehicle(_make, _model, _year, _price), axles(_axles) {}

    double calculateToll() override {
        return axles * 5.0;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Axles: " << axles << ", Toll: $" << calculateToll() << endl;
    }

    int getAxles() const { return axles; }
};

#endif
