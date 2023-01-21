#include "Environment.h"

#include <iostream>

void Environment::initRegister(std::string const& name)
{
    if (registers.find(name) == registers.end())
    {
        registers[name] = 0;
    }
}

bool Environment::isRegister(std::string const& name)
{
    return registers.find(name) != registers.end();
}

long Environment::getRegisterValue(std::string const& name) const
{
    return registers.at(name);
}

void Environment::add(std::string const& name, std::string value)
{
    registers[name] += std::stol(value);
}

void Environment::subtraction(std::string const& name, std::string value)
{
    registers[name] -= std::stol(value);
}

void Environment::multiply(std::string const& name, std::string value)
{
    registers[name] *= std::stol(value);
}

void Environment::print(std::string const& name)
{
    std::cout << registers[name] << std::endl;
}

void Environment::quit()
{
    exit(0);
}
