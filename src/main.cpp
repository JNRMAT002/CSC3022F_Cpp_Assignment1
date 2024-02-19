#include <iostream>
#include <vector>
#include <sstream>

// Mastery work:
struct charInfo {
    char character;
    long count;
};

bool charInfoCharExists(char inputChar, std::vector<charInfo> charInformation) {
    if (charInformation.empty()) {
        return false;
    }
    
    for (int i = 0; i < charInformation.size(); i++) {
        if (charInformation[i].character == inputChar) {
            return true;
        }
    }

    return false;
}

int charInfoCharCount(char inputChar, std::vector<charInfo> charInformation) {
    for (int i = 0; i < charInformation.size(); i++) {
        if (charInformation[i].character == inputChar) {
            return i;
        }
    }

    return -1;
}

// ---------------------------------------------------------------------------------------------

bool isValidLetter(char inputChar) {
     // If statement checks if valid letter = False.
    if ( (inputChar < 'A' || inputChar > 'Z') && (inputChar < 'a' || inputChar > 'z') && (inputChar < '0' || inputChar > '9') ) {
        return false;
    }
    
    return true;
}

// Function to remove punctuation and other non-letters and non-digits using stringstream.
std::string wordCleaner(std::string word) {
    std::string cleanWord;
        for (int i = 0; i < word.length(); i++) {
            if ( isValidLetter(word[i]) ) {
                // std::cout << word[i] << " ";
                cleanWord += word[i];
            }
        }
    
    // std::cout << cleanWord;

    return cleanWord;
}

// Function to return both word count and char count by returning of a pointer to static array.
int * countWordsAndChars(std::string input) {
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

            if ( isValidLetter(c) ) {
                if (charInfoCharExists(c, charInformation)) {
                    // charInfoCharCount(c, charInformation);
                    charIndex = charInfoCharCount(c, charInformation);
                    charInformation[charIndex].count++;
                } else {
                    charInfo newChar;
                    newChar.character = c;
                    newChar.count = 1;
                    charInformation.push_back(newChar);
                }
            }
        }
    }

    for (int i = 0; i < charInformation.size(); i++) {
        for (int j = 0; j < charInformation.size(); j++) {
            if (charInformation[i].character < charInformation[j].character) {
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