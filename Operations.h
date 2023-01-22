#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>

// To create a new operation, add a new class that inherits from BaseOperation
/*
    for instance a new operation called "divide" can be created by adding the following class:

    class DivideOperation : public BaseOperation
    {
        public:
            DivideOperation(std::string const& registerName, std::string const& value);
            long evaluation(long const oldValue, long const newValue) override;
    };

    And then add a match in CalcParser.cc in method createOperationNode:

    else if (operationType == "divide"s)
    {
        currentOperation = new DivideOperation{registerName, value};
    }
*/

class BaseOperation
{
    public:
        BaseOperation(std::string const& registerName, std::string const& value);
        virtual ~BaseOperation() = default;

        virtual long evaluation(long const oldValue, long const newValue) const = 0 ;
        std::string const& getValue() const;
        std::string const& getRegisterName() const;
    
    protected:
        std::string registerName;
        std::string value;
};

class AddOperation : public BaseOperation
{
    public:
        AddOperation(std::string const& registerName, std::string const& value);
        long evaluation(long const oldValue, long const newValue) const override;
};

class SubtractOperation : public BaseOperation
{
    public:
        SubtractOperation(std::string const& registerName, std::string const& value);
        long evaluation(long const oldValue, long const newValue) const override;
};

class MultiplyOperation : public BaseOperation
{
    public:
        MultiplyOperation(std::string const& registerName, std::string const& value);
        long evaluation(long const oldValue, long const newValue) const override;
};

#endif