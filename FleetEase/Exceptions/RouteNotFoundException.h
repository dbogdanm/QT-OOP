#ifndef ROUTENOTFOUNDEXCEPTION_H
#define ROUTENOTFOUNDEXCEPTION_H

#include "FleetException.h"

using namespace std;

class RouteNotFoundException : public FleetException {
public:
    explicit RouteNotFoundException(const string& msg) : FleetException(msg) {}
};

#endif
