#ifndef DRIVER_H
#define DRIVER_H
#include <utility>
#include <iostream>

using namespace std;

class Driver
{
private:
    int id;
    string name;
    string phone;
    int numberOfHours;

public:
    Driver(int id, string name, string phone, int number_of_hours)
        : id(id),
          name(std::move(name)),
          phone(std::move(phone)),
          numberOfHours(number_of_hours)
    {
    }


    Driver(const Driver &other)
    {
        id = other.id;
        name = other.name;
        phone = other.phone;
        numberOfHours = other.numberOfHours;
    }

    Driver& operator =(const Driver &other)
    {
        id = other.id;
        name = other.name;
        phone = other.phone;
        numberOfHours = other.numberOfHours;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Driver& driver)
    {
        os << "Driver id: " << driver.id << "\n";
        os << "Driver name: " << driver.name << "\n";
        os << "Driver phone: " << driver.phone << "\n";
        os << "Driver number of hours: " << driver.numberOfHours << "\n";
        return os;
    }

    ~Driver() = default;

};

#endif //DRIVER_H

