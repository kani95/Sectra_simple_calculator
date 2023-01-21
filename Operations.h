#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <unordered_map>
#include <vector>

class BaseOperation
{
    public:
        BaseOperation(std::string const& registerName, std::string const& value);

        virtual ~BaseOperation() = default;
        virtual long execute(long oldValue, long newValue) = 0;
        
        std::string getRegisterName() const;
        std::string getValue() const;

    protected:
        std::string registerName;
        std::string value;
};

class AddOperation : public BaseOperation
{
    public:
        using BaseOperation::getRegisterName;
        using BaseOperation::getValue;

        AddOperation(std::string const& registerName, std::string const& value);
        long execute(long oldValue, long newValue) override;
};

class SubtractOperation : public BaseOperation
{
    public:
        using BaseOperation::getRegisterName;
        using BaseOperation::getValue;

        SubtractOperation(std::string const& registerName, std::string const& value);
        long execute(long oldValue, long newValue) override;
};

class MultiplyOperation : public BaseOperation
{
    public:
        using BaseOperation::getRegisterName;
        using BaseOperation::getValue;

        MultiplyOperation(std::string const& registerName, std::string const& value);
        long execute(long oldValue, long newValue) override;
};

#endif