#include <iostream>
#include <string>

#include "CalcParser.h"

bool hasFilename(int const argc);
bool fileExists(std::string const& filename);

int main(int argc, char *argv[]) 
{
    if (!hasFilename(argc))
    {
        return 1;
    }

    std::string filename = argv[1];

    if (!fileExists(filename))
    {
        return 1;
    }

    std::ifstream inputFile{filename};

    CalcParser calcParser{};

    calcParser.parse(inputFile);

    return 0;
}

// Check if the user has entered a filename as second command line argument
bool hasFilename(int const argc)
{
    bool result{true};

    if (argc != 2)
    {
        std::cerr << "Error, no filename entered.\nPlease execute the program "
                  << "in the following format: ./a.out [FILENAME]" 
                  << std::endl;

        result = false;
    }

    return result;
}

// Check if the file exists and is readable locally
bool fileExists(std::string const& filename)
{
    bool result{true};

    std::ifstream const inputFile{filename};
    if (!inputFile) 
    {
        std::cerr << "Error, file \"" 
                  << filename 
                  << "\" not found. Please enter a valid filename." 
                  << std::endl;
        
        result = false;
    }
    
    return result;
}