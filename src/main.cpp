#include <cstring>
#include <iostream>
#include "pwd_generator.h"

void help() {
    std::cout << "Usage: pwd_generator [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -l <length>    Length of the password (default: 8)" << std::endl;
    std::cout << "  -e <options>   Character sets to include in the password (default: ulns)" << std::endl;
    std::cout << "                 u - uppercase characters" << std::endl;
    std::cout << "                 l - lowercase characters" << std::endl;
    std::cout << "                 n - numbers" << std::endl;
    std::cout << "                 s - symbols" << std::endl;
    std::cout << "  -h             Display this help message" << std::endl;
    std::cout << "Examples:" << std::endl;
    std::cout << "grp -l 12 -e uln" << std::endl;
    std::cout << "grp -l 16 -e ulns" << std::endl;
    std::cout << "grp -l 20 -e u" << std::endl;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-h") == 0 || std::strcmp(argv[i], "--help") == 0) {
            help();
            return 0;
        }
    }
    PasswordGenerator passwordGenerator;

    int length = 8;
    bool useUppercase = true;
    bool useLowercase = true;
    bool useNumbers = true;
    bool useSymbols = true;

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-l") == 0 && i + 1 < argc) {
            length = std::stoi(argv[i + 1]);
            ++i;
        } else if (std::strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            std::string options = argv[i + 1];
            useUppercase = (options.find('u') != std::string::npos);
            useLowercase = (options.find('l') != std::string::npos);
            useNumbers = (options.find('n') != std::string::npos);
            useSymbols = (options.find('s') != std::string::npos);
            ++i;
        }
    }

    std::string generatedPassword = passwordGenerator.generatePassword(length, useUppercase, useLowercase, useNumbers, useSymbols);

    std::cout << "Generated Password: " << generatedPassword << std::endl;

    return 0;
}