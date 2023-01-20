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
        void execute();

    private:
        void classifyOperation(std::vector<std::string> const& operation);

        std::vector<BaseOperation*> operationsExecAtOccurrence;
        std::vector<BaseOperation*> operationsExecAtPrint;
        Environment env;
};

#endif