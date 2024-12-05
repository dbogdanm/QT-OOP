#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include <utility>

/**
 * @class Driver
 * @brief Represents a driver in the system.
 *
 * The Driver class contains information about a driver, including their ID, name,
 * phone number, and the number of hours they've worked. It also tracks the total number
 * of drivers in the system using a static member variable.
 */
class Driver
{
private:
    /**
     * @brief Unique ID of the driver.
     */
    int id;

    /**
     * @brief Name of the driver.
     */
    std::string name;

    /**
     * @brief Phone number of the driver.
     */
    std::string phone;

    /**
     * @brief Number of hours the driver has worked.
     */
    int numberOfHours;

    /**
     * @brief Total number of drivers in the system.
     */
    static int totalDrivers;

public:
    /**
     * @brief Constructs a Driver with the specified details.
     *
     * @param id The unique ID of the driver.
     * @param name The name of the driver.
     * @param phone The phone number of the driver.
     * @param numberOfHours The number of hours the driver has worked.
     */
    Driver(int id, std::string name, std::string phone, int numberOfHours)
        : id(id), name(std::move(name)), phone(std::move(phone)), numberOfHours(numberOfHours)
    {
        ++totalDrivers;
    }

    /**
     * @brief Destroys the Driver object.
     *
     * Decrements the total number of drivers when a Driver object is destroyed.
     */
    ~Driver()
    {
        --totalDrivers;
    }

    /**
     * @brief Copy constructor for Driver.
     *
     * @param other The Driver object to copy.
     *
     * Increments the total number of drivers when a copy is created.
     */
    Driver(const Driver& other)
        : id(other.id), name(other.name),
        phone(other.phone), numberOfHours(other.numberOfHours)
    {
        ++totalDrivers;
    }

    /**
     * @brief Copy assignment operator for Driver.
     *
     * @param other The Driver object to assign from.
     * @return A reference to the assigned Driver object.
     */
    Driver& operator=(Driver other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Driver objects.
     *
     * @param first The first Driver object.
     * @param second The second Driver object.
     */
    friend void swap(Driver& first, Driver& second) noexcept
    {
        using std::swap;
        swap(first.id, second.id);
        swap(first.name, second.name);
        swap(first.phone, second.phone);
        swap(first.numberOfHours, second.numberOfHours);
    }

    /**
     * @brief Gets the ID of the driver.
     *
     * @return The unique ID of the driver.
     */
    [[nodiscard]] int getId() const
    {
        return id;
    }

    /**
     * @brief Updates the number of hours worked by the driver.
     *
     * @param newNumberOfHours The new number of hours to set.
     */
    void updateNumberOfHours(int newNumberOfHours)
    {
        numberOfHours = newNumberOfHours;
    }

    /**
     * @brief Displays the details of the driver.
     *
     * Outputs the driver's ID, name, phone number, and hours worked to the console.
     */
    void display() const
    {
        std::cout << "Driver ID: " << id << ", Name: " << name
                  << ", Phone: " << phone << ", Hours: " << numberOfHours << std::endl;
    }

    /**
     * @brief Gets the total number of drivers in the system.
     *
     * @return The total number of Driver objects created minus the ones destroyed.
     */
    static int getTotalDrivers()
    {
        return totalDrivers;
    }
};

#endif // DRIVER_H
