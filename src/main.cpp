#include <iostream>
#include <vector>

int main () {
    // std::vector<std::string> files;
    std::string input;

    while (std::cin) {
        getline(std::cin, input);
        std::cout << input << std::endl;
    }
    
    return 0;
}