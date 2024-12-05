#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

/**
 * @class Bus
 * @brief Represents a bus, derived from the Vehicle class.
 *
 * The Bus class extends the Vehicle class by adding specific attributes such as seating capacity
 * and WiFi availability. It includes functionality for displaying details, performing maintenance,
 * and creating a copy of the bus object.
 */
class Bus : public Vehicle
{
private:
    /**
     * @brief The seating capacity of the bus.
     */
    int seatingCapacity;

    /**
     * @brief Indicates whether the bus has WiFi.
     */
    bool hasWiFi;

public:
    /**
     * @brief Constructs a Bus with the specified attributes.
     *
     * @param vin The Vehicle Identification Number (VIN) of the bus.
     * @param model The model name of the bus.
     * @param kilometers The total kilometers driven by the bus.
     * @param brand The brand of the bus.
     * @param seatingCapacity The seating capacity of the bus.
     * @param hasWiFi A boolean indicating if the bus has WiFi.
     */
    Bus(int vin, const std::string& model, int kilometers, const std::string& brand,
        int seatingCapacity, bool hasWiFi)
        : Vehicle(vin, model, kilometers, brand),
          seatingCapacity(seatingCapacity), hasWiFi(hasWiFi) {}

    /**
     * @brief Copy constructor for Bus.
     *
     * @param other The Bus object to copy.
     */
    Bus(const Bus& other)
        : Vehicle(other), seatingCapacity(other.seatingCapacity), hasWiFi(other.hasWiFi) {}

    /**
     * @brief Copy assignment operator for Bus.
     *
     * @param other The Bus object to assign from.
     * @return A reference to the assigned Bus object.
     */
    Bus& operator=(Bus other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Bus objects.
     *
     * @param first The first Bus object.
     * @param second The second Bus object.
     */
    friend void swap(Bus& first, Bus& second) noexcept
    {
        using std::swap;
        first.swapBase(second); // Swap base members
        swap(first.seatingCapacity, second.seatingCapacity);
        swap(first.hasWiFi, second.hasWiFi);
    }

    /**
     * @brief Destroys the Bus object.
     */
    ~Bus() override = default;

    /**
     * @brief Displays detailed information about the Bus.
     *
     * Overrides the display method from the Vehicle class to include bus-specific attributes.
     */
    void display() const override
    {
        std::cout << "Bus - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Seating Capacity: " << seatingCapacity
                  << ", WiFi: " << (hasWiFi ? "Yes" : "No") << std::endl;
    }

    /**
     * @brief Performs maintenance on the Bus.
     *
     * Overrides the performMaintenance method from the Vehicle class.
     */
    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Bus VIN " << vin << std::endl;
    }

    /**
     * @brief Creates a unique pointer to a cloned Bus object.
     *
     * @return A unique pointer to a copy of the Bus.
     */
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Bus>(*this);
    }

    /**
     * @brief Gets the seating capacity of the bus.
     *
     * @return The seating capacity of the bus.
     */
    [[nodiscard]] int getSeatingCapacity() const
    {
        return seatingCapacity;
    }

    /**
     * @brief Gets the WiFi availability status of the bus.
     *
     * @return True if the bus has WiFi, false otherwise.
     */
    [[nodiscard]] bool getHasWiFi() const
    {
        return hasWiFi;
    }
};

#endif
#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

/**
 * @class Bus
 * @brief Represents a bus, derived from the Vehicle class.
 *
 * The Bus class extends the Vehicle class by adding specific attributes such as seating capacity
 * and WiFi availability. It includes functionality for displaying details, performing maintenance,
 * and creating a copy of the bus object.
 */
class Bus : public Vehicle
{
private:
    /**
     * @brief The seating capacity of the bus.
     */
    int seatingCapacity;

    /**
     * @brief Indicates whether the bus has WiFi.
     */
    bool hasWiFi;

public:
    /**
     * @brief Constructs a Bus with the specified attributes.
     *
     * @param vin The Vehicle Identification Number (VIN) of the bus.
     * @param model The model name of the bus.
     * @param kilometers The total kilometers driven by the bus.
     * @param brand The brand of the bus.
     * @param seatingCapacity The seating capacity of the bus.
     * @param hasWiFi A boolean indicating if the bus has WiFi.
     */
    Bus(int vin, const std::string& model, int kilometers, const std::string& brand,
        int seatingCapacity, bool hasWiFi)
        : Vehicle(vin, model, kilometers, brand),
          seatingCapacity(seatingCapacity), hasWiFi(hasWiFi) {}

    /**
     * @brief Copy constructor for Bus.
     *
     * @param other The Bus object to copy.
     */
    Bus(const Bus& other)
        : Vehicle(other), seatingCapacity(other.seatingCapacity), hasWiFi(other.hasWiFi) {}

    /**
     * @brief Copy assignment operator for Bus.
     *
     * @param other The Bus object to assign from.
     * @return A reference to the assigned Bus object.
     */
    Bus& operator=(Bus other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Bus objects.
     *
     * @param first The first Bus object.
     * @param second The second Bus object.
     */
    friend void swap(Bus& first, Bus& second) noexcept
    {
        using std::swap;
        first.swapBase(second); // Swap base members
        swap(first.seatingCapacity, second.seatingCapacity);
        swap(first.hasWiFi, second.hasWiFi);
    }

    /**
     * @brief Destroys the Bus object.
     */
    ~Bus() override = default;

    /**
     * @brief Displays detailed information about the Bus.
     *
     * Overrides the display method from the Vehicle class to include bus-specific attributes.
     */
    void display() const override
    {
        std::cout << "Bus - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Seating Capacity: " << seatingCapacity
                  << ", WiFi: " << (hasWiFi ? "Yes" : "No") << std::endl;
    }

    /**
     * @brief Performs maintenance on the Bus.
     *
     * Overrides the performMaintenance method from the Vehicle class.
     */
    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Bus VIN " << vin << std::endl;
    }

    /**
     * @brief Creates a unique pointer to a cloned Bus object.
     *
     * @return A unique pointer to a copy of the Bus.
     */
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Bus>(*this);
    }

    /**
     * @brief Gets the seating capacity of the bus.
     *
     * @return The seating capacity of the bus.
     */
    int getSeatingCapacity() const
    {
        return seatingCapacity;
    }

    /**
     * @brief Gets the WiFi availability status of the bus.
     *
     * @return True if the bus has WiFi, false otherwise.
     */
    bool getHasWiFi() const
    {
        return hasWiFi;
    }
};

#endif
