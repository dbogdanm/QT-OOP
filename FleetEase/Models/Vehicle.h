#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <memory>
#include <utility>

/**
 * @class Vehicle
 * @brief Abstract base class representing a generic vehicle.
 *
 * The Vehicle class serves as a base class for specific vehicle types such as
 * cars, buses, motorcycles, and trucks. It includes common attributes like VIN,
 * model, kilometers driven, and brand. The class enforces implementation of
 * specific methods in derived classes through pure virtual functions.
 */
class Vehicle
{
protected:
    /**
     * @brief The Vehicle Identification Number (VIN) of the vehicle.
     */
    int vin;

    /**
     * @brief The model name of the vehicle.
     */
    std::string model;

    /**
     * @brief The total kilometers driven by the vehicle.
     */
    int kilometers;

    /**
     * @brief The brand of the vehicle.
     */
    std::string brand;

public:
    /**
     * @brief Constructs a Vehicle with the specified attributes.
     *
     * @param vin The Vehicle Identification Number (VIN).
     * @param model The model name of the vehicle.
     * @param kilometers The kilometers driven by the vehicle.
     * @param brand The brand of the vehicle.
     */
    Vehicle(int vin, std::string model, int kilometers, std::string brand)
        : vin(vin), model(std::move(model)), kilometers(kilometers), brand(std::move(brand)) {}

    /**
     * @brief Copy constructor for Vehicle.
     *
     * Creates a copy of the given Vehicle object.
     *
     * @param other The Vehicle object to copy.
     */
    Vehicle(const Vehicle& other)
        : vin(other.vin), model(other.model),
          kilometers(other.kilometers), brand(other.brand) {}

    /**
     * @brief Virtual destructor for Vehicle.
     *
     * Ensures proper cleanup of resources in derived classes.
     */
    virtual ~Vehicle() = default;

    /**
     * @brief Displays detailed information about the vehicle.
     *
     * This is a pure virtual function that must be implemented in derived classes.
     */
    virtual void display() const = 0;

    /**
     * @brief Performs maintenance on the vehicle.
     *
     * This is a pure virtual function that must be implemented in derived classes.
     */
    virtual void performMaintenance() = 0;

    /**
     * @brief Creates a unique pointer to a cloned Vehicle object.
     *
     * This is a pure virtual function that must be implemented in derived classes
     * to support cloning.
     *
     * @return A unique pointer to a copy of the Vehicle.
     */
    [[nodiscard]] virtual std::unique_ptr<Vehicle> clone() const = 0;

    /**
     * @brief Displays basic information about the vehicle.
     *
     * Outputs the VIN, model, kilometers driven, and brand to the console.
     */
    void showInfo() const
    {
        std::cout << "VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand << std::endl;
    }

    /**
     * @brief Gets the VIN of the vehicle.
     *
     * @return The Vehicle Identification Number (VIN).
     */
    [[nodiscard]] int getVin() const
    {
        return vin;
    }

protected:
    /**
     * @brief Swaps the base attributes of two Vehicle objects.
     *
     * This method is intended for use in derived class implementations of the
     * copy-and-swap idiom.
     *
     * @param other The Vehicle object to swap with.
     */
    void swapBase(Vehicle& other) noexcept
    {
        using std::swap;
        swap(vin, other.vin);
        swap(model, other.model);
        swap(kilometers, other.kilometers);
        swap(brand, other.brand);
    }

public:
    /**
     * @brief Deleted assignment operator for Vehicle.
     *
     * Copy assignment is prohibited for Vehicle objects to prevent shallow copies.
     */
    Vehicle& operator=(const Vehicle& other) = delete;
};

#endif
