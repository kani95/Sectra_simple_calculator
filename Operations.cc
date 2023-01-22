#include "Operations.h"

// ****** Constructors ******

BaseOperation::BaseOperation(std::string const& registerName, std::string const& value)
    : registerName{registerName}, value{value}
{}

AddOperation::AddOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

SubtractOperation::SubtractOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

MultiplyOperation::MultiplyOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

// ******* Getters ********

std::string const& BaseOperation::getValue() const
{
    return value;
}

// ****** Evaluation ******

long AddOperation::evaluation(long const oldValue, long const newValue)
{
    return oldValue + newValue;
}

long SubtractOperation::evaluation(long const oldValue, long const newValue)
{
    return oldValue - newValue;
}

long MultiplyOperation::evaluation(long const oldValue, long const newValue)
{
    return oldValue * newValue;
}
