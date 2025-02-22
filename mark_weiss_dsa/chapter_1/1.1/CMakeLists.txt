cmake_minimum_required(VERSION 3.10)
project(SelectionProblem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Add main executable
add_executable(main_app src/main.cpp)

# Add test executable
add_executable(test_app tests/test.cpp)

# Enable testing
enable_testing()
add_test(NAME SelectionProblemTests COMMAND test_app)