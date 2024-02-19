// Header file for myWC program (Assignment 1 for CSC3022F, 2024)
// By Matthew January - JNRMAT002

#ifndef myWC_H
#define myWC_H

#include <iostream>
#include <vector>
#include <sstream>

namespace JNRMAT002 {
    struct charInfo { char character; long count; };
    int getCharIndex(char inputChar, std::vector<charInfo> charInformation);
    bool isValidLetter(char inputChar);
    std::string wordCleaner(std::string word);
    int * countWordsAndChars(std::string input);
}

#endif