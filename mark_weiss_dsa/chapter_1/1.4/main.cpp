#include <fstream>
#include <string>
#include <iostream>
#include "numbers.txt"

void processFile(std::string fileName)
{
    std::ifstream f(fileName);
    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;

    while (std::getline(f, s))
        std::cout<<s<<std::endl;
    f.close();
    return 0;
}

int main()
{
    auto exit = processFile(numbers);
    return exit;
}