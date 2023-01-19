#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>

class BaseOperation
{
    public:
        virtual ~BaseOperation() = default;
        virtual void execute() = 0;

    private:
        std::string registerName;
       
};

class AddOperation : public BaseOperation
{
    public:
        void execute() override
        {
            
        }
    private:
        long value;

};

class PrintOperation : public BaseOperation
{
    public:
        PrintOperation()
            : BaseOperation{}
        {}

        void execute() override
        {
        }

};


#endif