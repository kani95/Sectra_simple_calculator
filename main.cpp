#include <iostream>
#include <string>

#include "CalcParser.h"

/*
    step 1: set all registers to 0. (loop through operation_list) until print operation
    step 2: Loop through operation_list and check if the operation has a register as value or contains letters.
        step 2.1: if yes, then save to separate operations_list that is executed before print operation
        step 2.2: if no, then store in original operations_list
*/

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Error, no filename entered.\nPlease execute the program in the following format: ./a.out [FILENAME]" << std::endl;
        return 1;
    }
    std::string filename = argv[1];

    std::ifstream inputFile{filename};
    if (!inputFile) 
    {
        std::cerr << "Error, file \"" << filename <<"\" not found. Please enter a valid filename." << std::endl;
        return 1;
    }

    CalcParser calcParser{};
    calcParser.parse(inputFile);
    calcParser.execute();

    return 0;
}