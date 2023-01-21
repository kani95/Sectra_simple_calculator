#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <vector>

#include "Operations.h"

class Environment
{
    public:
        bool isRegister(std::string const& name);
        void storeOperation(std::string const& registerName, BaseOperation* newOperation);
        std::vector<BaseOperation*> getRegisterValue(std::string const& name) const;
        std::unordered_map<std::string, long> getValues() const;
        std::unordered_map<std::string, std::vector<BaseOperation*>> getRegisters() const;
        long execute(std::string const& registerName);
        void add(std::string const& name, std::string value);
        void subtraction(std::string const& name, std::string value);
        void multiply(std::string const& name, std::string value);
        void print(std::string const& name);
        void quit();

    private:        
        std::unordered_map<std::string, std::vector<BaseOperation*>> registers;
        std::unordered_map<std::string, long> values;
};

#endif