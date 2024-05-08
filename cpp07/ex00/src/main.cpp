#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
    {   int a = 42;
        int b = 84;
        std::cout << ::max(a, b) << std::endl;
        std::cout << ::min(a, b) << std::endl;
        ::swap(a, b);
        std::cout << "a:" << a << " b:" << b << std::endl;
    }
    {   bool a = false;
        bool b = true;
        std::cout << std::boolalpha << ::max(a, b) << std::endl;
        std::cout << std::boolalpha << ::min(a, b) << std::endl;
        ::swap(a, b);
        std::cout << std::boolalpha <<  "a:" << a << " b:" << b << std::endl;
    }
}