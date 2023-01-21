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
        void execute();

    private:
        void classifyOperation(std::vector<std::string> const& operation);

        std::queue<BaseOperation*> allOperations;
        std::queue<BaseOperation*> operationsExecAtPrint;
        Environment env;
};

#endif