#include <iostream>

#include "Environment.h"

// ****** Destructor ******
Environment::~Environment()
{
    for (auto& [registerName, operationsToExecute] : registers)
    {
        while (!operationsToExecute.empty())
        {
            delete operationsToExecute.front();
            operationsToExecute.pop();
        }
    }
}

// Store a new operation in the environment for a given register
void Environment::storeOperation(std::string const& registerName, BaseOperation* newOperation)
{
    registers[registerName].push(newOperation);

    if (values.find(registerName) == values.end())
    {
        values[registerName] = 0;
    }
}

// Get the value of a register as a long
long Environment::getRegisterValue(std::string const& registerName) const
{
    return values.at(registerName);
}

// Check if a register exists in the environment
bool Environment::isRegister(std::string const& registerName) const
{
    return registers.find(registerName) != registers.end();
}

bool Environment::registerNameIsAlpha(std::string const& registerName) const
{
    for (char c : registerName)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
    }

    return true;
}

// Evaluate the value of a register by evaluating all the operations stored in the environment
long Environment::evaluation(std::string const& registerName, long value)
{
    if (registers.at(registerName).empty())
    {
        value = values.at(registerName);
    }
    else
    {
        while (!registers.at(registerName).empty())
        {
            BaseOperation* operation{registers.at(registerName).front()};
        
            // if the value is a register, then evaluate its operations to retrieve its value
            if (isRegister(operation -> getValue()))
            {
                value = operation -> evaluation(value, evaluation(operation -> getValue()));
            }
            // else, the value is a number, so we can convert it to a long
            else
            {
                try {
                    value = operation -> evaluation(value, std::stol(operation -> getValue()));
                }
                catch (std::invalid_argument const& e)
                {
                    std::cerr << "Cannot evaluate operation with register: " << registerName 
                              << " and value: " <<  operation -> getValue() << std::endl;
                }
            }

            delete operation;
            registers.at(registerName).pop();
        }

        values[registerName] = value;
    }

    return value;
}
