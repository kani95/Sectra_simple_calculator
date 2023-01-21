#include <iostream>

#include "Environment.h"

Environment::~Environment()
{
    for (auto& registerPair : registers)
    {
        for (BaseOperation* operation : registerPair.second)
        {
            delete operation;
        }
    }
}

void Environment::storeOperation(std::string const& registerName, BaseOperation* newOperation)
{
    registers[registerName].push_back(newOperation);

    values[registerName] = 0;
}

long Environment::getRegisterValue(std::string const& registerName)
{
    return values.at(registerName);
}

bool Environment::isRegister(std::string const& registerName)
{
    return registers.find(registerName) != registers.end();
}

long Environment::execute(std::string const& registerName)
{
    long value{};

    for (BaseOperation* operation : registers.at(registerName))
    {
        if (isRegister(operation -> getValue()))
        {
            value = operation -> execute(value, execute(operation -> getValue()));
        }
        else
        {
            value = operation -> execute(value, std::stol(operation -> getValue()));
        }
    }

    values[registerName] = value;

    return value;
}
