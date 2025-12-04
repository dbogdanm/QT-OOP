#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;

public:
    Vehicle(string _make, string _model, int _year, double _price) {
        make = _make;
        model = _model;
        year = _year;
        price = _price;
    }

    virtual ~Vehicle() {}

    virtual double calculateToll() = 0;

    virtual void displayInfo() {
        cout << "Make: " << make << ", Model: " << model 
             << ", Year: " << year << ", Price: $" << price << endl;
    }

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
};

#endif
