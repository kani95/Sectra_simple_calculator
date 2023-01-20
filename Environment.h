#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>

class Environment
{
    public:
        bool shouldExecAtPrint(std::string const& name);
        void add(std::string const& name, std::string value);
        void subtraction(std::string const& name, std::string value);
        void multiply(std::string const& name, std::string value);
        void print(std::string const& name);
        void quit();

    private:
        void initRegister(std::string const& name);
        
        std::unordered_map<std::string, double> registers;
};

#endif