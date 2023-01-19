#include <sstream>

#include "CalcParser.h"
#include "Environment.h"
#include "Operations.h"

CalcParser::~CalcParser()
{
    for (auto & operation : operations)
    {
        delete operation;
    }
}

void CalcParser::parse(std::ifstream & inputFile)
{
    std::string line{};
    std::vector<std::string> extractedLine{};

    while(std::getline(inputFile, line))
    {
        std::stringstream ss{line};
        std::string word{};
       
        while (ss >> word)
        {
            extractedLine.push_back(word);
        }

        classifyOperation(extractedLine, env);

        extractedLine.clear();
    }
}

void CalcParser::classifyOperation(std::vector<std::string> const& operation, Environment & env)
{
    using namespace std::string_literals;

    if (operation.size() == 2 && operation[0] == "print"s)
    {
        std::string registeraName = operation[1];
        operations.push_back(new PrintOperation{});
    }
}