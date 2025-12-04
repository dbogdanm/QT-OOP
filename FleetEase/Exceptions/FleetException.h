#ifndef FLEETEXCEPTION_H
#define FLEETEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class FleetException : public exception {
protected:
    string message;

public:
    explicit FleetException(const string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
