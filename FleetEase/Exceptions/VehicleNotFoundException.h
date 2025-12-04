#ifndef VEHICLENOTFOUNDEXCEPTION_H
#define VEHICLENOTFOUNDEXCEPTION_H

#include "FleetException.h"

using namespace std;

class VehicleNotFoundException : public FleetException {
public:
    explicit VehicleNotFoundException(const string& msg) : FleetException(msg) {}
};

#endif
