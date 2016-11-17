#include "../include/parseError.hpp"

/**
* Constructor
**/

MessageException::MessageException(std::string message) noexcept : msg(message) {}

/**
* Destructor
**/

MessageException::~MessageException() noexcept {}

/**
* Return the error message
**/

std::string MessageException::getMessage() const
{
    return msg;
}
