#ifndef WORD_PUZZLE_H
#define WORD_PUZZLE_H

#include<string>
#include<algorithm>
#include<vector>

bool _find_word(const std::vector<char> &array, const std::string &word) {
    int wordLength = word.length();
    if (array.size() < wordLength) {
        return false;
    }

    // Convert the vector to a string for easier searching
    std::string input(array.begin(), array.end());

    // Check if the word exists in the input
    if (input.find(word) != std::string::npos) {
        return true;
    }

    // Check if the reverse of the word exists in the input
    std::string reversedWord(word.rbegin(), word.rend());
    if (input.find(reversedWord) != std::string::npos) {
        return true;
    }

    return false;
}

bool word_puzzle(const std::vector<std::vector<char>> & grid, const std::vector<std::string> & wordList)
{
    if (grid.empty()){
        return false;
    }
    // Checking Column wise
    auto numRows = grid.size();
    auto numCols = grid[0].size();
    for (const auto &word:wordList){
        bool wordFound = false;
        // Iterate through rows
        for (const auto &row:grid){
            wordFound = _find_word(row, word);
            if(wordFound){
                break;
            }
        }
        if (wordFound){
            continue;
        }
        // Iterate through columns
        for (int j = 0; j < numCols; j++)
        {
            std::vector<char> temp;
            for (int i = 0; i < numRows; i++)
            {
                temp.push_back(grid[i][j]);
            }
            wordFound = _find_word(temp, word);
            if (wordFound){
                break;
            }
        }
        if (wordFound){
            continue;
        }
        // Iterate through upper diagonal
        for (int d = 0; d < numRows + numCols - 1; ++d) 
        {
            int row = std::max(0, static_cast<int>(d - numCols + 1));
            int col = std::min(d, static_cast<int>(numCols - 1));
            std::vector<char> temp;
            while (row < numRows && col < numCols) 
            {
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            wordFound = _find_word(temp, word);
            if (wordFound){
                break;
            }
        }
        if (wordFound){
            continue;
        }
        // Iterate through lower diagonal
        for (int d = 0; d < numRows + numCols - 1; ++d) 
        {
            int row = std::min(d, static_cast<int>(numRows - 1));
            int col = std::min(0, static_cast<int>(d - numRows + 1));
            std::vector<char> temp;
            while (row >= 0 && col < numCols) 
            {
                temp.push_back(grid[row][col]);
                row--;
                col++;
            }
            wordFound = _find_word(temp, word);
            if (wordFound){
                break;
            }
        }
        if (!wordFound){
            return wordFound;
        }
    }

    return true;
}

#endif