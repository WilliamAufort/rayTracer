#include "../include/parseError.hpp"

MessageException::MessageException(std::string message) noexcept : msg(message) {}

MessageException::~MessageException() noexcept {}

std::string MessageException::getMessage() const
{
    return msg;
}
