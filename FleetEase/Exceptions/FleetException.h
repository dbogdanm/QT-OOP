#ifndef FLEETEXCEPTION_H
#define FLEETEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

/**
 * @class FleetException
 * @brief Base class for all exceptions related to fleet management.
 *
 * The FleetException class extends the standard std::exception class
 * and provides a mechanism to include a custom error message for fleet-related exceptions.
 */
class FleetException : public std::exception
{
protected:
    /**
     * @brief Custom error message for the exception.
     */
    std::string message;

public:
    /**
     * @brief Constructs a FleetException with a given error message.
     *
     * @param msg A string containing the error message to be associated with the exception.
     */
    explicit FleetException(std::string msg) : message(std::move(msg)) {}

    /**
     * @brief Retrieves the error message associated with the exception.
     *
     * @return A C-style string containing the error message.
     *
     * This function overrides the `what()` method from std::exception to
     * provide a custom error message.
     */
    [[nodiscard]] const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif
