#include <iostream>
#include "word_puzzle.h"

int main() {
    // Example grid
    std::vector<std::vector<char>> grid = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };

    // Example word list
    // std::vector<std::string> wordList = {"abc", "fjk", "pon", "mnop", "xyz"};
    std::vector<std::string> wordList = {"abc", "pon", "mnop", "dgjm"};

    // Check if all words in the list are present in the grid
    bool result = word_puzzle(grid, wordList);

    // Output the result
    if (result) {
        std::cout << "All words are present in the grid!" << std::endl;
    } else {
        std::cout << "Not all words are present in the grid." << std::endl;
    }

    return 0;
}