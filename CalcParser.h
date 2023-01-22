#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <fstream>

#include "Environment.h"

class CalcParser
{
    public:
        void parse(std::ifstream & inputFile);
        
    private:
        std::string getOperationType(std::vector<std::string> const& operation) const;
        void createOperationNode(std::string const& registerName, 
                                 std::string const& operationType,
                                 std::string const& value);
        bool checkDependency(std::string const& registerName, std::string const& value) const;

        Environment env;
};

#endif