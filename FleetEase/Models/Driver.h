#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>

using namespace std;

class Driver {
private:
    string name;
    string licenseNumber;
    int experienceYears;

public:
    Driver(string _name, string _licenseNumber, int _experienceYears)
        : name(_name), licenseNumber(_licenseNumber), experienceYears(_experienceYears) {}

    void displayDriverInfo() const {
        cout << "Driver: " << name << ", License: " << licenseNumber 
             << ", Experience: " << experienceYears << " years" << endl;
    }

    string getName() const { return name; }
    string getLicenseNumber() const { return licenseNumber; }
    int getExperienceYears() const { return experienceYears; }
};

#endif
