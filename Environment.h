#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <queue>

#include "Operations.h"

class Environment
{
    public:
        ~Environment();
    
        void storeOperation(std::string const& registerName, BaseOperation* newOperation);
        long getRegisterValue(std::string const& registerName) const;
        long evaluation(std::string const& registerName, long value = 0);
        bool isRegister(std::string const& registerName) const;
        bool isCircularDependent(std::string const& registerName, std::string const& value) const;
        
    private:        
        std::unordered_map<std::string, std::queue<BaseOperation*>> registers;
        std::unordered_map<std::string, long> values;
};

#endif