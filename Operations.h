#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>

#include "Environment.h"

class BaseOperation
{
    public:
        BaseOperation(std::string const& registerName, bool execAtPrint = false);
        virtual ~BaseOperation() = default;
        bool getExecAtPrint() const;
        void setExecAtPrint(bool execAtPrint);
        virtual void execute(Environment & env) = 0;

    protected:
        std::string registerName;
        bool execAtPrint;
};

class AddOperation : public BaseOperation
{
    public:
        using BaseOperation::getExecAtPrint;
        using BaseOperation::setExecAtPrint;

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
        using BaseOperation::getExecAtPrint;
        using BaseOperation::setExecAtPrint;

        SubtractOperation(std::string const& registerName, std::string const& value);
        void execute(Environment & env) override;
    private:
        std::string value;
};

class MultiplyOperation : public BaseOperation
{
    public:
        using BaseOperation::getExecAtPrint;
        using BaseOperation::setExecAtPrint;

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