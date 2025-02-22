#include <cassert>
#include <iostream>
#include "word_puzzle.h"

void test_word_puzzle() {
    // Test case 1: All words are present
    {
        std::vector<std::vector<char>> grid = {
            {'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l'},
            {'m', 'n', 'o', 'p'}
        };
        std::vector<std::string> wordList = {"abc", "pon", "mnop"};
        assert(word_puzzle(grid, wordList) == true);
    }

    // Test case 2: Some words are missing
    {
        std::vector<std::vector<char>> grid = {
            {'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l'},
            {'m', 'n', 'o', 'p'}
        };
        std::vector<std::string> wordList = {"abc", "xyz", "fjk", "pon"};
        assert(word_puzzle(grid, wordList) == false);
    }

    // Test case 3: Empty grid
    {
        std::vector<std::vector<char>> grid = {};
        std::vector<std::string> wordList = {"abc", "def"};
        assert(word_puzzle(grid, wordList) == false);
    }

    // Test case 4: Single-row grid
    {
        std::vector<std::vector<char>> grid = {
            {'a', 'b', 'c', 'd'}
        };
        std::vector<std::string> wordList = {"abc", "dcb"};
        assert(word_puzzle(grid, wordList) == true);
    }

    // Test case 5: Single-column grid
    {
        std::vector<std::vector<char>> grid = {
            {'a'},
            {'b'},
            {'c'},
            {'d'}
        };
        std::vector<std::string> wordList = {"abcd", "dcba"};
        assert(word_puzzle(grid, wordList) == true);
    }

    // Test case 6: Words in diagonals
    {
        std::vector<std::vector<char>> grid = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'}
        };
        std::vector<std::string> wordList = {"aei", "gec"};
        assert(word_puzzle(grid, wordList) == true);
    }

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_word_puzzle();
    return 0;
}