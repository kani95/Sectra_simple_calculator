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

void AddOperation::execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values)
{
    if (env.find(value) != env.end())
    {
        for (BaseOperation* operation : env.at(value))
        {
            operation -> execute(env, values);
        }
    }
    else
    {
        values[registerName] += std::stol(value);
    }
}

SubtractOperation::SubtractOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

void SubtractOperation::execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values)
{
    if (env.find(value) != env.end())
    {
        for (BaseOperation* operation : env.at(value))
        {
            operation -> execute(env, values);
        }
    }
    else
    {
        values[registerName] -= std::stol(value);
    }
}

MultiplyOperation::MultiplyOperation(std::string const& registerName, std::string const& value)
    : BaseOperation{registerName, value}
{}

void MultiplyOperation::execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values)
{
    if (env.find(value) != env.end())
    {
        for (BaseOperation* operation : env.at(value))
        {
            operation -> execute(env, values);
        }
    }
    else
    {
        values[registerName] *= std::stol(value);
    }
}

PrintOperation::PrintOperation(std::string const& registerName)
    : BaseOperation(registerName, "")
{}

void PrintOperation::execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values)
{
    std::cout << values[registerName] << std::endl;
}

QuitOperation::QuitOperation()
    : BaseOperation("", "")
{}

void QuitOperation::execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values)
{
    exit(0);
}
