#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

/**
 * @class Truck
 * @brief Represents a truck, derived from the Vehicle class.
 *
 * The Truck class extends the Vehicle class by adding specific attributes such as
 * load capacity and fuel efficiency. It overrides base class methods to provide
 * truck-specific functionality and supports cloning, displaying, and maintenance operations.
 */
class Truck : public Vehicle
{
private:
    /**
     * @brief The load capacity of the truck in tons.
     */
    double loadCapacity;

    /**
     * @brief The fuel efficiency of the truck in liters per 100 kilometers (L/100km).
     */
    double fuelEfficiency;

public:
    /**
     * @brief Constructs a Truck with the specified attributes.
     *
     * @param vin The Vehicle Identification Number (VIN) of the truck.
     * @param model The model name of the truck.
     * @param kilometers The total kilometers driven by the truck.
     * @param brand The brand of the truck.
     * @param loadCapacity The load capacity of the truck in tons.
     * @param fuelEfficiency The fuel efficiency of the truck in L/100km.
     */
    Truck(const int vin, const std::string& model, const int kilometers, const std::string& brand,
          const double loadCapacity, const double fuelEfficiency)
        : Vehicle(vin, model, kilometers, brand),
          loadCapacity(loadCapacity), fuelEfficiency(fuelEfficiency) {}

    /**
     * @brief Copy constructor for Truck.
     *
     * Creates a deep copy of the given Truck object.
     *
     * @param other The Truck object to copy.
     */
    Truck(const Truck& other)
        : Vehicle(other), loadCapacity(other.loadCapacity),
          fuelEfficiency(other.fuelEfficiency) {}

    /**
     * @brief Copy assignment operator for Truck.
     *
     * Performs a deep copy of another Truck object using the copy-and-swap idiom.
     *
     * @param other The Truck object to assign from.
     * @return A reference to the assigned Truck object.
     */
    Truck& operator=(Truck other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Truck objects.
     *
     * Used for implementing the copy-and-swap idiom.
     *
     * @param first The first Truck object.
     * @param second The second Truck object.
     */
    friend void swap(Truck& first, Truck& second) noexcept
    {
        using std::swap;
        first.swapBase(second);
        swap(first.loadCapacity, second.loadCapacity);
        swap(first.fuelEfficiency, second.fuelEfficiency);
    }

    /**
     * @brief Destroys the Truck object.
     */
    ~Truck() override = default;

    /**
     * @brief Displays detailed information about the truck.
     *
     * Overrides the base class method to include truck-specific attributes like
     * load capacity and fuel efficiency.
     */
    void display() const override
    {
        std::cout << "Truck - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Load Capacity: " << loadCapacity
                  << " tons, Fuel Efficiency: " << fuelEfficiency << " L/100km" << std::endl;
    }

    /**
     * @brief Performs maintenance on the truck.
     *
     * Overrides the base class method to include truck-specific maintenance actions.
     */
    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Truck VIN " << vin << std::endl;
        // The implementation will be more complex in future milestones.
    }

    /**
     * @brief Creates a unique pointer to a cloned Truck object.
     *
     * @return A unique pointer to a copy of the Truck.
     */
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Truck>(*this);
    }

    /**
     * @brief Gets the load capacity of the truck.
     *
     * @return The load capacity of the truck in tons.
     */
    [[nodiscard]] double getLoadCapacity() const
    {
        return loadCapacity;
    }

    /**
     * @brief Gets the fuel efficiency of the truck.
     *
     * @return The fuel efficiency of the truck in L/100km.
     */
    [[nodiscard]] double getFuelEfficiency() const
    {
        return fuelEfficiency;
    }
};

#endif
