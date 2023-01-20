#include "Operations.h"

BaseOperation::BaseOperation(std::string const& registerName, bool executedAtPrint)
    : registerName(registerName), executedAtPrint(executedAtPrint)
{}

bool BaseOperation::getExecutedAtPrint() const
{
    return executedAtPrint;
}

AddOperation::AddOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void AddOperation::execute(Environment & env)
{
    if (env.shouldExecAtPrint(value))
    {
        executedAtPrint = true;
    }
    else
    {
        env.add(registerName, value);
    }
}

SubtractOperation::SubtractOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void SubtractOperation::execute(Environment & env)
{
    if (env.shouldExecAtPrint(value))
    {
        executedAtPrint = true;
    }
    else
    {
        env.subtraction(registerName, value);
    }
}

MultiplyOperation::MultiplyOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void MultiplyOperation::execute(Environment & env)
{
    if (env.shouldExecAtPrint(value))
    {
        executedAtPrint = true;
    }
    else
    {
        env.multiply(registerName, value);
    }
}

PrintOperation::PrintOperation(std::string const& registerName)
    : BaseOperation(registerName)
{}

void PrintOperation::execute(Environment & env)
{
    env.print(registerName);
}

QuitOperation::QuitOperation()
    : BaseOperation("")
{}

void QuitOperation::execute(Environment & env)
{
    env.quit();
}