#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

/**
 * @class Motorcycle
 * @brief Represents a motorcycle, derived from the Vehicle class.
 *
 * The Motorcycle class extends the Vehicle class by adding specific attributes such as
 * engine displacement and the presence of a sidecar. It overrides the base class methods
 * to provide motorcycle-specific functionality.
 */
class Motorcycle : public Vehicle
{
private:
    /**
     * @brief The engine displacement of the motorcycle in cubic centimeters (cc).
     */
    double engineDisplacement;

    /**
     * @brief Indicates whether the motorcycle has a sidecar.
     */
    bool hasSidecar;

public:
    /**
     * @brief Constructs a Motorcycle with the specified attributes.
     *
     * @param vin The Vehicle Identification Number (VIN) of the motorcycle.
     * @param model The model name of the motorcycle.
     * @param kilometers The total kilometers driven by the motorcycle.
     * @param brand The brand of the motorcycle.
     * @param engineDisplacement The engine displacement of the motorcycle in cc.
     * @param hasSidecar A boolean indicating whether the motorcycle has a sidecar.
     */
    Motorcycle(int vin, const std::string& model, int kilometers, const std::string& brand,
               double engineDisplacement, bool hasSidecar)
        : Vehicle(vin, model, kilometers, brand),
          engineDisplacement(engineDisplacement), hasSidecar(hasSidecar) {}

    /**
     * @brief Copy constructor for Motorcycle.
     *
     * Creates a deep copy of the given Motorcycle object.
     *
     * @param other The Motorcycle object to copy.
     */
    Motorcycle(const Motorcycle& other)
        : Vehicle(other), engineDisplacement(other.engineDisplacement),
          hasSidecar(other.hasSidecar) {}

    /**
     * @brief Copy assignment operator for Motorcycle.
     *
     * Performs a deep copy of another Motorcycle object using the copy-and-swap idiom.
     *
     * @param other The Motorcycle object to assign from.
     * @return A reference to the assigned Motorcycle object.
     */
    Motorcycle& operator=(Motorcycle other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Swaps the contents of two Motorcycle objects.
     *
     * Used for implementing the copy-and-swap idiom.
     *
     * @param first The first Motorcycle object.
     * @param second The second Motorcycle object.
     */
    friend void swap(Motorcycle& first, Motorcycle& second) noexcept
    {
        using std::swap;
        first.swapBase(second);
        swap(first.engineDisplacement, second.engineDisplacement);
        swap(first.hasSidecar, second.hasSidecar);
    }

    /**
     * @brief Destroys the Motorcycle object.
     */
    ~Motorcycle() override = default;

    /**
     * @brief Displays detailed information about the motorcycle.
     *
     * Overrides the base class method to include motorcycle-specific attributes like
     * engine displacement and sidecar presence.
     */
    void display() const override
    {
        std::cout << "Motorcycle - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Engine Displacement: " << engineDisplacement
                  << "cc, Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }

    /**
     * @brief Performs maintenance on the motorcycle.
     *
     * Overrides the base class method to include motorcycle-specific maintenance actions.
     */
    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Motorcycle VIN " << vin << std::endl;
        // The implementation will be more complex in future milestones.
    }

    /**
     * @brief Creates a unique pointer to a cloned Motorcycle object.
     *
     * @return A unique pointer to a copy of the Motorcycle.
     */
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Motorcycle>(*this);
    }

    /**
     * @brief Gets the engine displacement of the motorcycle.
     *
     * @return The engine displacement of the motorcycle in cubic centimeters (cc).
     */
    [[nodiscard]] double getEngineDisplacement() const
    {
        return engineDisplacement;
    }

    /**
     * @brief Checks if the motorcycle has a sidecar.
     *
     * @return True if the motorcycle has a sidecar, false otherwise.
     */
    [[nodiscard]] bool getHasSidecar() const
    {
        return hasSidecar;
    }
};

#endif
