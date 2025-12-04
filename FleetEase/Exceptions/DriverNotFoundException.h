#ifndef DRIVERNOTFOUNDEXCEPTION_H
#define DRIVERNOTFOUNDEXCEPTION_H

#include "FleetException.h"

using namespace std;

class DriverNotFoundException : public FleetException {
public:
    explicit DriverNotFoundException(const string& msg) : FleetException(msg) {}
};

#endif
