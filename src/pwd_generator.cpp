#include "pwd_generator.h"
#include <cstdlib>
#include <ctime>

PasswordGenerator::PasswordGenerator() {
    initializeCharSets();

    std::srand(std::time(0));
}

void PasswordGenerator::initializeCharSets() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        uppercaseChars += c;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        lowercaseChars += c;
    }

    for (char c = '0'; c <= '9'; ++c) {
        numberChars += c;
    }

    symbolChars = "!@#$%^&*()-=_+[]{}|;:'\",.<>?/";
}

std::string PasswordGenerator::generatePassword(int length, bool useUppercase, bool useLowercase, bool useNumbers, bool useSymbols) {
    std::string allChars;

    if (useUppercase) allChars += uppercaseChars;
    if (useLowercase) allChars += lowercaseChars;
    if (useNumbers) allChars += numberChars;
    if (useSymbols) allChars += symbolChars;

    if (allChars.empty()) {
        allChars = uppercaseChars + lowercaseChars + numberChars + symbolChars;
    }

    std::string password;

    for (int i = 0; i < length; ++i) {
        char randomChar = allChars[std::rand() % allChars.length()];
        password += randomChar;
    }

    return password;
}