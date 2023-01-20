#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>

#include "Environment.h"

class BaseOperation
{
    public:
        BaseOperation(std::string const& registerName, bool executedAtPrint = false);
        virtual ~BaseOperation() = default;
        virtual void execute(Environment & env) = 0;
        bool getExecutedAtPrint() const;

    protected:
        std::string registerName;
        bool executedAtPrint;
};

class AddOperation : public BaseOperation
{
    public:
        using BaseOperation::getExecutedAtPrint;

        AddOperation(std::string const& registerName, std::string const& value);
        void execute(Environment & env) override;
    private:
        std::string value;
};

class PrintOperation : public BaseOperation
{
    public:
        PrintOperation(std::string const& registerName);
        void execute(Environment & env) override;
};

class SubtractOperation : public BaseOperation
{
    public:
        using BaseOperation::getExecutedAtPrint;

        SubtractOperation(std::string const& registerName, std::string const& value);
        void execute(Environment & env) override;
    private:
        std::string value;
};

class MultiplyOperation : public BaseOperation
{
    public:
        using BaseOperation::getExecutedAtPrint;

        MultiplyOperation(std::string const& registerName, std::string const& value);
        void execute(Environment & env) override;
    private:
        std::string value;
};

class QuitOperation : public BaseOperation
{
    public:
        QuitOperation();
        void execute(Environment & env) override;
};

#endif