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

    int *wordAndCharCount;

    while (getline(std::cin, input)) {
        // if (input[0] == '>') { lineCount++; } // This version of line counting was for the example tests from the given .txt file.
        lineCount++; // This is a more accurate line counter for .txt files without the ">" delimiter starting each line.
        wordAndCharCount = countWordsAndChars(input);
        totalWordCount += *(wordAndCharCount+0);
        totalCharCount += *(wordAndCharCount+1);
    }

    // Printing output to the console
    std::cout << lineCount << " " << totalWordCount << " " << totalCharCount << std::endl;
    
    return 0;
}