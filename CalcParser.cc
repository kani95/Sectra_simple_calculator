#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "CalcParser.h"
#include "Operations.h"

CalcParser::~CalcParser()
{
    while (!allOperations.empty())
    {
        delete allOperations.front();
        allOperations.pop();
    }

    while (!operationsExecAtPrint.empty())
    {
        delete operationsExecAtPrint.front();
        operationsExecAtPrint.pop();
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
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            // TODO create the class here and add it to the vector
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

    if (operationType == "print"s)
    {
        std::string registerName = operation[1];
        allOperations.push(new PrintOperation{registerName});
    }
    else if (operationType == "add"s)
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        BaseOperation* addOperation = new AddOperation{registerName, value};
        env.initRegister(registerName);
        allOperations.push(addOperation);
    }
    else if (operationType == "subtract")
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        BaseOperation* subtractOperation = new SubtractOperation{registerName, value};
        env.initRegister(registerName);
        allOperations.push(subtractOperation);
    }
    else if (operationType == "multiply")
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        BaseOperation* multiplyOperation = new MultiplyOperation{registerName, value};
        env.initRegister(registerName);
        allOperations.push(multiplyOperation);
    }
    else if (operationType == "quit")
    {
        allOperations.push(new QuitOperation{});
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
    while (!allOperations.empty())
    {
        BaseOperation* operation = allOperations.front();

        if (dynamic_cast<PrintOperation*>(operation))
        {
            while (!operationsExecAtPrint.empty())
            {
                BaseOperation* innerOperation = operationsExecAtPrint.front();
                innerOperation -> setExecAtPrint(false);
                innerOperation -> execute(env);

                delete innerOperation;
                operationsExecAtPrint.pop();
            }
        }

        operation -> execute(env);
           
        if (operation -> getExecAtPrint())
        {
            operationsExecAtPrint.push(operation);
        }
        else
        {
            delete operation;
        }

        allOperations.pop();
    }
}
