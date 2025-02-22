// tests/test.cpp
#include <iostream>
#include <vector>
#include <cassert>
#include "selection_problem.h"

// Test cases
void test_selection_problem() {
    // Test case 1: Basic test with integers
    {
        std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
        int k = 2; // 3rd largest element (0-based index)
        int result = selection_problem(numbers, k);
        assert(result == 5);
        std::cout << "Test case 1 passed!" << std::endl;
    }

    // Test case 2: Test with floating-point numbers
    {
        std::vector<double> numbers = {3.14, 2.71, 1.618, 0.0, -1.0};
        int k = 1; // 2nd largest element
        double result = selection_problem(numbers, k);
        assert(result == 2.71);
        std::cout << "Test case 2 passed!" << std::endl;
    }

    // Test case 3: Test with a single-element array
    {
        std::vector<int> numbers = {42};
        int k = 0; // Only one element
        int result = selection_problem(numbers, k);
        assert(result == 42);
        std::cout << "Test case 3 passed!" << std::endl;
    }

    // Test case 4: Test with k = 0 (largest element)
    {
        std::vector<int> numbers = {10, 20, 30, 40, 50};
        int k = 0; // Largest element
        int result = selection_problem(numbers, k);
        assert(result == 50);
        std::cout << "Test case 4 passed!" << std::endl;
    }

    // Test case 5: Test with k = array.size() - 1 (smallest element)
    {
        std::vector<int> numbers = {10, 20, 30, 40, 50};
        int k = numbers.size() - 1; // Smallest element
        int result = selection_problem(numbers, k);
        assert(result == 10);
        std::cout << "Test case 5 passed!" << std::endl;
    }

    // Test case 6: Test with negative numbers
    {
        std::vector<int> numbers = {-5, -2, -9, -1, -5, -6};
        int k = 2; // 3rd largest element
        int result = selection_problem(numbers, k);
        assert(result == -5);
        std::cout << "Test case 6 passed!" << std::endl;
    }

    // Test case 7: Test with mixed positive and negative numbers
    {
        std::vector<int> numbers = {-5, 2, -9, 1, 5, -6};
        int k = 3; // 4th largest element
        int result = selection_problem(numbers, k);
        assert(result == -5);
        std::cout << "Test case 7 passed!" << std::endl;
    }

    // Test case 8: Test with k greater than array size (should throw an exception)
    {
        std::vector<int> numbers = {1, 2, 3};
        int k = 5; // Invalid k
        try {
            selection_problem(numbers, k);
            assert(false); // Should not reach here
        } catch (const std::out_of_range& e) {
            std::cout << "Test case 8 passed! Exception: " << e.what() << std::endl;
        }
    }

    // Test case 9: Test with non-arithmetic type (should trigger static_assert)
    {
        std::vector<std::string> strings = {"apple", "banana", "cherry"};
        int k = 1; // Invalid type
        // Uncommenting the following line should cause a compile-time error
        // std::string result = selection_problem(strings, k);
        std::cout << "Test case 9: Compile-time error triggered (as expected)." << std::endl;
    }
}

int main() {
    test_selection_problem();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}