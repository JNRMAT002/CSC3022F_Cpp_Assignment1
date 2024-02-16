#include <iostream>
#include <vector>
#include <sstream>

// Function to remove punctuation and other non-letters and non-digits using stringstream.
std::string wordCleaner(std::string word) {
    std::string cleanWord;
    for (int i = 0; i < word.length(); i++) {
        // If statement check if valid letter = False.
        if ( (word[i] < 'A' || word[i] > 'Z') && (word[i] < 'a' || word[i] > 'z') && (word[i] < '0' || word[i] > '9') ) {
            // std::cout << word[i] << " ";
            continue;
        }
        
        cleanWord += word[i];
    }

    return cleanWord;
}

// Function to count chars in each line using stringstream.
int countChars(std::string input) {
    std::stringstream inputSS(input);
    std::string word;
    int charCount = 0;

    while (inputSS >> word) {
        std::string cleanWord = wordCleaner(word);
        charCount += cleanWord.length();
    }
    
    return charCount;
}

// Function to count words in each line using stringstream.
int countWords(std::string input) {
    std::stringstream inputSS(input);
    std::string word;
    int lineWordCount = 0;

    while (inputSS >> word) {
        std::string cleanWord = wordCleaner(word);
        if (!cleanWord.empty()) { lineWordCount++; }
    }

    return lineWordCount;
}

int main () {
    std::string input;
    int totalCharCount = 0; // Total number of character in the text file
    int totalWordCount = 0; // Total number of words in the text file
    int lineCount = 0; // Number of lines in the text file

    while (getline(std::cin, input)) {
        // if (input[0] == '>') { lineCount++; } // This version of line counting was for the example tests from the given .txt file.
        lineCount++; // This is a more accurate line counter for .txt files without the ">" delimiter starting each line.
        totalWordCount += countWords(input);
        totalCharCount += countChars(input);
    }

    // Printing output to the console
    std::cout << lineCount << " " << totalWordCount << " " << totalCharCount << std::endl;
    
    return 0;
}