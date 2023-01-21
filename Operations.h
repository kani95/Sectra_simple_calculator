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
        std::string getRegisterName() const;
        std::string getValue() const;
        virtual void execute(std::unordered_map<std::string, std::vector<BaseOperation*>>  env, std::unordered_map<std::string, long> values) = 0;

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
        void execute(std::unordered_map<std::string, std::vector<BaseOperation*>>  env, std::unordered_map<std::string, long>  values) override;
};

class PrintOperation : public BaseOperation
{
    public:
        PrintOperation(std::string const& registerName);
        void execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values) override;
};

class SubtractOperation : public BaseOperation
{
    public:
        using BaseOperation::getRegisterName;
        using BaseOperation::getValue;

        SubtractOperation(std::string const& registerName, std::string const& value);
        void execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values) override;
};

class MultiplyOperation : public BaseOperation
{
    public:
        using BaseOperation::getRegisterName;
        using BaseOperation::getValue;

        MultiplyOperation(std::string const& registerName, std::string const& value);
        void execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values) override;
};

class QuitOperation : public BaseOperation
{
    public:
        QuitOperation();
        void execute(std::unordered_map<std::string, std::vector<BaseOperation*>> env, std::unordered_map<std::string, long> values) override;
};

#endif