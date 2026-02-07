#include <iostream>
#include "calculator.h"

int main() {
    std::cout << "5 + 3 = " << add(5, 3) << "\n";
    std::cout << "5 - 3 = " << sub(5, 3) << "\n";
    std::cout << "5 * 3 = " << mul(5, 3) << "\n";
    std::cout << "10 / 2 = " << divide(10, 2) << "\n";

    return 0;
}