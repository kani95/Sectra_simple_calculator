#include <iostream>

#include "Environment.h"

void Environment::storeOperation(std::string const& registerName, BaseOperation* newOperation)
{
    registers[registerName].push_back(newOperation);
    values[registerName] = 0;
}


bool Environment::isRegister(std::string const& name)
{
    return registers.find(name) != registers.end();
}

long Environment::execute(std::string const& registerName)
{
    long value{};
    for (BaseOperation* operation : registers.at(registerName))
    {
        if (registers.find(operation -> getValue()) != registers.end())
        {
            //execute(operation -> getValue());
            if (dynamic_cast<AddOperation*>(operation))
            {
                value += execute(operation -> getValue());
            }
            else if (dynamic_cast<SubtractOperation*>(operation))
            {
                value -= execute(operation -> getValue());
            }
            else if (dynamic_cast<MultiplyOperation*>(operation))
            {
                value *= execute(operation -> getValue());
            }
        }
        else
        {
            if (dynamic_cast<AddOperation*>(operation))
            {
                value += std::stol(operation -> getValue());
            }
            else if (dynamic_cast<SubtractOperation*>(operation))
            {
                value -= std::stol(operation -> getValue());
            }
            else if (dynamic_cast<MultiplyOperation*>(operation))
            {
                value *= std::stol(operation -> getValue());
            }
        }
       
    }

    values[registerName] = value;
    return value;
}

std::vector<BaseOperation*> Environment::getRegisterValue(std::string const& name) const
{
    return registers.at(name);
}

std::unordered_map<std::string, long> Environment::getValues() const
{
    return values;
}

std::unordered_map<std::string, std::vector<BaseOperation*>> Environment::getRegisters() const
{
    return registers;
}


// void Environment::add(std::string const& name, std::string value)
// {
//     registers[name] += std::stol(value);
// }

// void Environment::subtraction(std::string const& name, std::string value)
// {
//     registers[name] -= std::stol(value);
// }

// void Environment::multiply(std::string const& name, std::string value)
// {
//     registers[name] *= std::stol(value);
// }

// void Environment::print(std::string const& name)
// {
//     std::cout << registers[name] << std::endl;
// }

void Environment::quit()
{
    exit(0);
}
