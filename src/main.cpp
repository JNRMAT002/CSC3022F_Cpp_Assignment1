// Main executable file for myWC program (Assignment 1 for CSC3022F, 2024)
// By Matthew January - JNRMAT002

#include "../include/myWC.h"

using namespace JNRMAT002;

int main () {
    std::string input;
    int totalCharCount = 0; // Total number of character in the text file
    int totalWordCount = 0; // Total number of words in the text file
    int lineCount = 0; // Number of lines in the text file
    std::vector<charInfo> charInformation; // Container for charInfo struct variables
    int *wordAndCharCount;
    int charIndex;

    while (getline(std::cin, input)) {
        // if (input[0] == '>') { lineCount++; } // This version of line counting was for the example tests from the given .txt file.
        lineCount++; // This is a more accurate line counter for .txt files without the ">" delimiter starting each line.
        wordAndCharCount = countWordsAndChars(input);
        totalWordCount += *(wordAndCharCount+0);
        totalCharCount += *(wordAndCharCount+1);

        // Mastery work:
        for (int i = 0; i < input.length(); i++) {
            char c;
            c = tolower(input[i]);

            if (!isValidLetter(c)) { continue; }

            charIndex = getCharIndex(c, charInformation);

            if (charIndex == -1){
                charInfo newChar;
                newChar.character = c;
                newChar.count = 1;
                charInformation.push_back(newChar);
            } else {
                charIndex = getCharIndex(c, charInformation);
                charInformation[charIndex].count++;
            }
        }
    }

    // Sort the vector<charInfo> alphabetically (Bubble Sort)
    for (int i = 0; i < charInformation.size(); i++) {
        for (int j = i+1; j < charInformation.size(); j++) {
            if (charInformation[j].character < charInformation[i].character) {
                charInfo temp = charInformation[i];
                charInformation[i] = charInformation[j];
                charInformation[j] = temp;
            }
        }
    }

    // Printing output to the console
    std::cout << lineCount << " " << totalWordCount << " " << totalCharCount << " [";

    for (int i = 0; i < charInformation.size(); i++) {
        if (i == charInformation.size()-1) {
            std::cout << charInformation[i].character << ":" << charInformation[i].count << "]" << std::endl;
        } else {
            std::cout << charInformation[i].character << ":" << charInformation[i].count << " " ;
        }
    }
    
    return 0;
}