#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "CalcParser.h"
#include "Operations.h"

CalcParser::~CalcParser()
{}

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

        BaseOperation* operation {classifyOperation(extractedLine)};
        
        if (dynamic_cast<PrintOperation*>(operation))
        {
            env.execute(operation -> getRegisterName());
            operation -> execute(env.getRegisters(), env.getValues());
        }
        else if (dynamic_cast<QuitOperation*>(operation))
        {
            exit(true);
        }
        
        extractedLine.clear();
        ss.clear();
    }
}

BaseOperation* CalcParser::classifyOperation(std::vector<std::string> const& operation)
{

    using namespace std::string_literals;

    size_t nrOfArgs = operation.size();
    std::string operationType;
    std::string operationValue;
    std::string registerName;

    if (nrOfArgs == 0)
    {
        return nullptr;
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
        return nullptr;
    }

    BaseOperation* currentOperation;

    if (operationType == "print"s)
    {
        std::string registerName = operation[1];
        return new PrintOperation{registerName};
    }
    if (operationType == "add"s)
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        currentOperation  = new AddOperation{registerName, value};
        env.storeOperation(registerName, currentOperation);

        return currentOperation; 
        
        //allOperations.push_back(addOperation);
    }
    else if (operationType == "subtract")
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        currentOperation = new SubtractOperation{registerName, value};
        env.storeOperation(registerName, currentOperation);
        return currentOperation;
        //env.initRegister(registerName);
        //allOperations.push_back(subtractOperation);
    }
    else if (operationType == "multiply")
    {
        std::string registerName = operation[0];
        std::string value = operation[2];
        currentOperation = new MultiplyOperation{registerName, value};
        env.storeOperation(registerName, currentOperation);
        return currentOperation;
        //env.initRegister(registerName);
        //allOperations.push_back(multiplyOperation);
    }
    else if (operationType == "quit")
    {
        return new QuitOperation{};
    }
    else
    {
        std::cerr << "Error, cannot classify operation: ";
        std::copy(operation.begin(), operation.end(), std::ostream_iterator<std::string>(std::cerr, " "));
        std::cerr << std::endl;
        return nullptr;
    }
}

void CalcParser::execute()
{   
    
}
