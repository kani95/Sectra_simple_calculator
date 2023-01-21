#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <vector>

#include "Operations.h"

class Environment
{
    public:
        ~Environment();
        void storeOperation(std::string const& registerName, BaseOperation* newOperation);
        long getRegisterValue(std::string const& registerName);
        long execute(std::string const& registerName);
        bool isRegister(std::string const& registerName);
        
    private:        
        std::unordered_map<std::string, std::vector<BaseOperation*>> registers;
        std::unordered_map<std::string, long> values;
};

#endif