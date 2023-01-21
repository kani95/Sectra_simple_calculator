#include <iostream>

#include "Operations.h"

BaseOperation::BaseOperation(std::string const& registerName, std::string const& value)
    : registerName{registerName}, value{value}
{}

std::string BaseOperation::getRegisterName() const
{
    return registerName;
}

std::string BaseOperation::getValue() const
{
    return value;
}

AddOperation::AddOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

long AddOperation::execute(long oldValue, long newValue)
{
    return oldValue + newValue;
}

SubtractOperation::SubtractOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

long SubtractOperation::execute(long oldValue, long newValue)
{
    return oldValue - newValue;
}

MultiplyOperation::MultiplyOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

long MultiplyOperation::execute(long oldValue, long newValue)
{
    return oldValue * newValue;
}
