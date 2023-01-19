#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>

class Environment
{
    public:
        void setRegister(std::string const& name, std::string const& value);
    private:
        std::unordered_map<std::string, double> registers;
};

#endif