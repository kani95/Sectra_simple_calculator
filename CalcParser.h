#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <fstream>
#include <queue>

#include "Environment.h"
#include "Operations.h"

class CalcParser
{
    public:
        ~CalcParser();
        void parse(std::ifstream & inputFile);
        void getValue(BaseOperation* & registerName);
        void execute();

    private:
        BaseOperation* classifyOperation(std::vector<std::string> const& operation);

        std::vector<BaseOperation*> allOperations;
        Environment env;
};

#endif