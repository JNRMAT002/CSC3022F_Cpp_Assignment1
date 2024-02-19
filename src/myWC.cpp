// Implementation file for myWC program (Assignment 1 for CSC3022F, 2024)
// By Matthew January - JNRMAT002

#include "../include/myWC.h"

// Returns -1 if character does not exist in vector<charInfo>.
// Returns index otherwise.
int JNRMAT002::getCharIndex(char inputChar, std::vector<charInfo> charInformation) {
    if (charInformation.empty()) {
        return -1;
    }

    for (int i = 0; i < charInformation.size(); i++) {
        if (charInformation[i].character == inputChar) {
            return i;
        }
    }

    return -1;
}

// ---------------------------------------------------------------------------------------------

// Function to return false if inputChar is not in 'A..Z', 'a..z', or '0..9'
bool JNRMAT002::isValidLetter(char inputChar) {
     // If statement checks if valid letter = False.
    if ( (inputChar < 'A' || inputChar > 'Z') && (inputChar < 'a' || inputChar > 'z') && (inputChar < '0' || inputChar > '9') ) {
        return false;
    }
    
    return true;
}

// Function to remove punctuation and other non-letters and non-digits using stringstream.
std::string JNRMAT002::wordCleaner(std::string word) {
    std::string cleanWord;
        for (int i = 0; i < word.length(); i++) {
            if ( isValidLetter(word[i]) ) {
                cleanWord += word[i];
            }
        }

    return cleanWord;
}

// Function to return both word count and char count by returning of a pointer to static array.
int * JNRMAT002::countWordsAndChars(std::string input) {
    static int wordAndCharCount[2] = {0, 0};
    int lineWordCount = 0;
    int charCount = 0;
    std::stringstream inputSS(input);
    std::string word;

    while (inputSS >> word) {
        std::string cleanWord = wordCleaner(word);
        charCount += cleanWord.length();
        if (!cleanWord.empty()) { lineWordCount++; }
    }
    wordAndCharCount[0] = lineWordCount;
    wordAndCharCount[1] = charCount;

    return wordAndCharCount;
}