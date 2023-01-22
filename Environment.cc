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
                // If the value is not a number, then we cannot evaluate the operation
                try 
                {
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

// Check if a register is dependent on another register
bool Environment::isCircularDependent(std::string const& registerName, std::string const& value) const
{
    if (registers.at(value).empty())
    {
        return false;
    }
    else
    {
        std::queue<BaseOperation*> operationsToExecute{registers.at(value)};
        while (!operationsToExecute.empty())
        {
            BaseOperation* operation{operationsToExecute.front()};
            if (operation -> getValue() == registerName && operation -> getRegisterName() == value)
            {
                return true;
            }
            operationsToExecute.pop();
        }
    }

    return false;  
}
