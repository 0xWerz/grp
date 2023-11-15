#pragma once
#include <string>

class PasswordGenerator {
   public:
    PasswordGenerator();

    std::string generatePassword(int length, bool useUppercase, bool useLowercase, bool useNumbers, bool useSymbols);

   private:
    std::string uppercaseChars;
    std::string lowercaseChars;
    std::string numberChars;
    std::string symbolChars;

    void initializeCharSets();
};