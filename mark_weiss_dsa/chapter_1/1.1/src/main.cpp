#include <iostream>
#include "selection_problem.h"

int main() 
{
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    int k = 2; // 3rd largest element (0-based index)

    try {
        int result = selection_problem(numbers, k);
        std::cout << "The " << k + 1 << "-th largest element is: " << result << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}