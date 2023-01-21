#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>

class Environment
{
    public:
        void initRegister(std::string const& name);
        bool isRegister(std::string const& name);
        long getRegisterValue(std::string const& name) const;
        void add(std::string const& name, std::string value);
        void subtraction(std::string const& name, std::string value);
        void multiply(std::string const& name, std::string value);
        void print(std::string const& name);
        void quit();

    private:        
        std::unordered_map<std::string, long> registers;
};

#endif