#include <iostream>
#include "print_double.h"
#include<vector>
int main() {
    // Test cases:
    std::vector<int> tests{0, -1, 2, 1782, -82347, 23, -23};

    for (const auto & num:tests){
        std::cout<<std::endl<<"Test number::: "<<num<<std::endl<<"Output:::";
        printOut(num);
    }
    std::cout<<std::endl<<"End of program"<<std::endl;
    return 0;
}