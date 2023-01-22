#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "CalcParser.h"
#include "Operations.h"

// Parse the input file line for line to create the operations and store them in the environment object
void CalcParser::parse(std::ifstream & inputFile)
{
    using namespace std::string_literals;

    std::string line{};
    std::stringstream ss{};
    std::vector<std::string> extractedLine{};

    // For each line in the input file
    while(std::getline(inputFile, line))
    {
        ss << line;
        std::string word{};
       
        // Extract the words from the line
        while (ss >> word)
        {
            // Convert the word to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            extractedLine.push_back(word);
        }

        std::string const operationsType {getOperationType(extractedLine)};
        std::string registerName{};

        // The line is filled with spaces or has more than 3 words
        if (operationsType.size() == 0)
        {
            continue;
        }
        
        if (operationsType == "print")
        {
            registerName = extractedLine[1];
            
            // Check if the register exists
            if (!env.isRegister(registerName))
            {
                std::cerr << "Cannot print register \"" << registerName << "\", it does not exist." << std::endl;
            }
            else
            {
                // Print the value of the register by starting the evaluation
                long currentValue = env.getRegisterValue(registerName);
                std::cout << env.evaluation(registerName, currentValue) << std::endl;
            }
        }
        else if (operationsType == "quit"s)
        {
            // Exit parsing and return to main.cpp
            return;
        }
        else
        {
            // Create an operation node and add it to the environment
            registerName = extractedLine[0];
            std::string const value = extractedLine[2];
            createOperationNode(registerName, operationsType, value); 
        }
        
        extractedLine.clear();
        ss.clear();
    }
}

// Get the type of operation from the line, which depends on the number of arguments the operation has
std::string CalcParser::getOperationType(std::vector<std::string> const& operation) const
{
    size_t const nrOfArgs = operation.size();
    std::string operationType{};

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
        std::cerr << "Error, cannot get operation type from operation: ";
        std::copy(operation.begin(), operation.end(), std::ostream_iterator<std::string>(std::cerr, " "));
        std::cerr << std::endl;
        return "";
    }
    
    return operationType;
}

// Create the operation node and store it in the environment
void CalcParser::createOperationNode(std::string const& registerName, 
                                     std::string const& operationType,
                                     std::string const& value)
{
    using namespace std::string_literals;
    
    bool const isCircularDependent{checkDependency(registerName, value)};

    if (!isCircularDependent)
    {
        std::cerr << "Error, circular dependency detected: " << registerName 
                  << " " << operationType << " " << value << std::endl;
        return;
    }

    BaseOperation* currentOperation{nullptr};

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
        std::cerr << "Error, cannot create operation: " << registerName 
                  << " " << operationType << " " << value << std::endl;
    }

    if (currentOperation != nullptr)
    {
        env.storeOperation(registerName, currentOperation);
    }
}

// Check if the register is dependent on itself or on another register that is dependent on it
bool CalcParser::checkDependency(std::string const& registerName, std::string const& value) const
{
    bool result{true};

    if (registerName == value)
    {
        result = false;
    }
    else if (env.isRegister(value))
    {
        if (env.isCircularDependent(registerName, value))
        {
            result = false;
        }
    }

    return result;
}
