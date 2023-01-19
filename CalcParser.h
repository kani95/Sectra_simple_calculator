#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <fstream>
#include <vector>

#include "Environment.h"
#include "Operations.h"

class CalcParser
{
    public:
        ~CalcParser();
        void parse(std::ifstream & inputFile);
        void classifyOperation(std::vector<std::string> const& operation, Environment & env);
    private:
        std::vector<BaseOperation*> operations;
        Environment env;
};

#endif