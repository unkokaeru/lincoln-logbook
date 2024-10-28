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
    example_switch_function();

    return 0;
}