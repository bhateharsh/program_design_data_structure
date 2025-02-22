#ifndef SELECTION_PROBLEM_H
#define SELECTION_PROBLEM_H

#include <iostream>
#include <algorithm>
#include <type_traits> 
#include <vector>

template <typename number>
const number selection_problem(std::vector <number> & array, int k)
{
    static_assert(std::is_arithmetic<number>::value, "Accepts only arithmetic types");
    // Runtime check for k
    if (k >= array.size() || k < 0) {
        throw std::out_of_range("Error: k is out of range");
    }
    std::sort(array.begin(), array.end(), std::greater<number>());
    return array[k];
}

#endif