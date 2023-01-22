#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <fstream>

#include "Environment.h"

class CalcParser
{
    public:
        void parse(std::ifstream & inputFile);
        
    private:
        std::string getOperationType(std::vector<std::string> const& operation);
        void createOperationNode(std::string const& registerName, 
                                 std::string const& operationType,
                                 std::string const& value);

        Environment env;
};

#endif