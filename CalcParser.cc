#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "CalcParser.h"
#include "Operations.h"

CalcParser::~CalcParser()
{
    for (BaseOperation* & operation : operationsExecAtOccurrence)
    {
        delete operation;
    }

    for (BaseOperation* & operation : operationsExecAtPrint)
    {
        delete operation;
    }
}

void CalcParser::parse(std::ifstream & inputFile)
{
    std::string line{};
    std::stringstream ss{};
    std::vector<std::string> extractedLine{};

    while(std::getline(inputFile, line))
    {
        ss << line;
        std::string word{};
       
        while (ss >> word)
        {
            extractedLine.push_back(word);
        }

        classifyOperation(extractedLine);

        extractedLine.clear();
        ss.clear();
    }
}

void CalcParser::classifyOperation(std::vector<std::string> const& operation)
{
    using namespace std::string_literals;

    size_t nrOfArgs = operation.size();
    std::string operationType;

    if (nrOfArgs == 0)
    {
        return;
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
        return;
    }

    std::transform(operationType.begin(), operationType.end(), operationType.begin(), ::tolower);

    if (operationType == "print"s)
    {
        std::string registerName = operation[1];
        std::transform(registerName.begin(), registerName.end(), registerName.begin(), ::tolower);
        operationsExecAtOccurrence.push_back(new PrintOperation{registerName});
    }
    else if (operationType == "add"s)
    {
        std::string registerName = operation[0];
        std::transform(registerName.begin(), registerName.end(), registerName.begin(), ::tolower);
        std::string value = operation[2];
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        BaseOperation* addOperation = new AddOperation{registerName, value};
        std::cout << "addOperation: " << addOperation -> getExecutedAtPrint() << std::endl;
        if (addOperation -> getExecutedAtPrint())
        {
            operationsExecAtPrint.push_back(addOperation);
        }
        else
        {
            operationsExecAtOccurrence.push_back(addOperation);
        }
    }
    else if (operationType == "subtract")
    {
        std::string registerName = operation[0];
        std::transform(registerName.begin(), registerName.end(), registerName.begin(), ::tolower);
        std::string value = operation[2];
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        BaseOperation* subtractOperation = new SubtractOperation{registerName, value};

        if (subtractOperation -> getExecutedAtPrint())
        {
            operationsExecAtPrint.push_back(subtractOperation);
        }
        else
        {
            operationsExecAtOccurrence.push_back(subtractOperation);
        }
    }
    else if (operationType == "multiply")
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        BaseOperation* multiplyOperation = new MultiplyOperation{registerName, value};
        
        if (multiplyOperation -> getExecutedAtPrint())
        {
            operationsExecAtPrint.push_back(multiplyOperation);
        }
        else
        {
            operationsExecAtOccurrence.push_back(multiplyOperation);
        }
    }
    else if (operationType == "quit")
    {
        operationsExecAtOccurrence.push_back(new QuitOperation{});
    }
    else
    {
        std::cerr << "Error, cannot classify operation: ";
        std::copy(operation.begin(), operation.end(), std::ostream_iterator<std::string>(std::cerr, " "));
        std::cerr << std::endl;
        return;
    }
}

void CalcParser::execute()
{
    for (BaseOperation* & operation : operationsExecAtOccurrence)
    {
        if (dynamic_cast<PrintOperation*>(operation))
        {
            std::cout << "size: " << operationsExecAtPrint.size() << std::endl;
            for (BaseOperation* & operation : operationsExecAtPrint)
            {
                operation -> execute(env);

                delete operation;
            }
        }

        operation -> execute(env);

        delete operation;
    }
}
