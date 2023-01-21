#include <iostream>

#include "Operations.h"

BaseOperation::BaseOperation(std::string const& registerName, bool execAtPrint)
    : registerName(registerName), execAtPrint(execAtPrint)
{}

bool BaseOperation::getExecAtPrint() const
{
    return execAtPrint;
}

void BaseOperation::setExecAtPrint(bool execAtPrint)
{
    this->execAtPrint = execAtPrint;
}

AddOperation::AddOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void AddOperation::execute(Environment & env)
{
    if (env.isRegister(value) && !execAtPrint)
    {
        execAtPrint = true;
    }
    else
    {
        if (env.isRegister(value))
        {
            value = std::to_string(env.getRegisterValue(value));
        }

        env.add(registerName, value);
    }
}

SubtractOperation::SubtractOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void SubtractOperation::execute(Environment & env)
{
    if (env.isRegister(value))
    {
        execAtPrint = true;
    }
    else
    {
        if (env.isRegister(value))
        {
            value = std::to_string(env.getRegisterValue(value));
        }

        env.subtraction(registerName, value);
    }
}

MultiplyOperation::MultiplyOperation(std::string const& registerName, std::string const& value)
    : BaseOperation(registerName), value(value)
{}

void MultiplyOperation::execute(Environment & env)
{
    if (env.isRegister(value))
    {
        execAtPrint = true;
    }
    else
    {
        if (env.isRegister(value))
        {
            value = std::to_string(env.getRegisterValue(value));
        }

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