/**
 * @file l01-control_structures-switch_statements.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explore the switch statement in C++
 * @version 0.1.0
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>


/**
 * @brief Example of a switch statement in C++
 * 
 */
void example_switch_function() {
    unsigned int incrementor = 3;
    unsigned int number;

    switch (incrementor) {
        case 1:
            number = 1;
            break;
        case 2:
            number = 1;
            break;
        case 3:
            number = 2;
            break;
        case 4:
            number = 6;
            break;
        case 5:
            number = 24;
            break;
        default:
            number = 0;
            break;
    }

    std::cout << "The number is: " << number << std::endl;
}
/* ANSWER (Task 1.1): Example switch statement.*/


int main() {
    /* Call the example_switch_function() function */
    // example_switch_function(); // uncomment this line to run the example
    /* ANSWER (Task 1.1): Call the example switch function.*/

    const double small_number = 10e-12;
    double x, y;
    int selection;

    std::cout << "FUNCTION LIST" << std::endl;
    std::cout << "1. csch(x)" << std::endl;
    std::cout << "2. sech(x)" << std::endl;
    std::cout << "3. coth(x)" << std::endl;
    
    std::cout << "Select a function (1-3): ";
    std::cin >> selection;
    if (selection > 0 && selection < 4) {
        std::cout << "Enter a value for x: ";
        std::cin >> x;
        std::cout << "For x = " << x << ", ";
    }

    switch (selection) {
        case 1:
            if (std::abs(x) < small_number) {
                std::cout << "csch(x) is undefined for x = 0." << std::endl;
                return 1;
            }
            y = 1/sinh(x);
            std::cout << "csch(x) ";
            break;
        case 2:
            y = 1/cosh(x);
            std::cout << "sech(x) ";
            break;
        case 3:
            if (std::abs(x) < small_number) {
                std::cout << "coth(x) is undefined for x = 0." << std::endl;
                return 1;
            }
            y = 1/tanh(x);
            std::cout << "coth(x) ";
            break;
        default:
            std::cout << "Invalid selection." << std::endl;
            return 1;
    }

    std::cout << "= " << y << std::endl;

    return 0;
}