#include <iostream>
#include <string>

#include "CalcParser.h"

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

    return 0;
}