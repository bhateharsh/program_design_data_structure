#ifndef PRINT_DOUBLE_H
#define PRINT_DOUBLE_H

#include <iostream>
#include <cstdlib>
#include <type_traits>

void printDigit(int n)
{
    std::cout<<n;
}

void printOut(int n)
{
    if (n > -10 && n < 0)
    {
        printDigit(n);
        return;
    }
    if (n < -10)
    {
        n = -n;
        int reverse = 0;
        while (n != 0){
            reverse = reverse*10 + n%10;
            n = n/10;
        }
        printDigit(-(reverse%10));
        reverse = reverse/10;
        while (reverse > 10)
        {
            printDigit(reverse%10);
            reverse = reverse/10;
        }
        printDigit(reverse);
        return;
    }
    if (n >= 10)
    {
        printOut(n/10);
    }
    printDigit(n%10);
}

#endif