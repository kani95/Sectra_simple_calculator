#include "Environment.h"

void Environment::setRegister(std::string const& name, std::string const& value)
{
    if (registers.find(name) == registers.end())
    {
        registers[name] = std::stod(value);
    }
    else
    {
        registers[name] = std::stod(value);
    }
}


