#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "CalcParser.h"
#include "Operations.h"

void CalcParser::parse(std::ifstream & inputFile)
{
    using namespace std::string_literals;

    std::string line{};
    std::stringstream ss{};
    std::vector<std::string> extractedLine{};

    while(std::getline(inputFile, line))
    {
        ss << line;
        std::string word{};
       
        while (ss >> word)
        {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            extractedLine.push_back(word);
        }

        std::string operationsType {getOperationType(extractedLine)};

        if (operationsType.size() == 0)
        {
            continue;
        }

        if (operationsType == "print"s)
        {
            std::string registerName = extractedLine[1];
            env.execute(registerName);
            std::cout << env.getRegisterValue(registerName) << std::endl;
        }
        else if (operationsType == "quit"s)
        {
            exit(1);
        }
        else
        {
            std::string registerName = extractedLine[0];
            std::string value = extractedLine[2];
            createOperationNode(registerName, operationsType, value); 
        }
        
        extractedLine.clear();
        ss.clear();
    }
}

std::string CalcParser::getOperationType(std::vector<std::string> const& operation)
{
    size_t nrOfArgs = operation.size();
    std::string operationType;

    if (nrOfArgs == 0)
    {
        return "";
    }
    else if (nrOfArgs < 3)
    {
        operationType = operation[0];
    }
    else if (nrOfArgs == 3)
    {
        operationType = operation[1];
    }
    else
    {
        std::cerr << "Error, cannot classify operation: ";
        std::copy(operation.begin(), operation.end(), std::ostream_iterator<std::string>(std::cerr, " "));
        std::cerr << std::endl;
        return "";
    }
    
    return operationType;
}

void CalcParser::createOperationNode(std::string const& registerName, std::string const& operationType, std::string const& value)
{
    using namespace std::string_literals;

    BaseOperation* currentOperation;

    if (operationType == "add"s)
    {
        currentOperation = new AddOperation{registerName, value};
    }
    else if (operationType == "subtract"s)
    {
        currentOperation = new SubtractOperation{registerName, value};
    }
    else if (operationType == "multiply"s)
    {
        currentOperation = new MultiplyOperation{registerName, value};
    }
    else
    {
        std::cerr << "Error, cannot classify operation: " << registerName << " " << operationType << " " << value << std::endl;
    }

    env.storeOperation(registerName, currentOperation); 
}

void CalcParser::execute()
{   
    
}
