/**
 * @file l02-control_structures-input_validation.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explores the use of input validation in C++
 * @version 0.1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>


/**
 * @brief Main function to run the program.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
    /* Constants */
    const double banned_number = 2.0;
    const double small_number = 10e-12;
    /* ANSWER (Task 2.0): Initalises the constant variables. */
    
    /* Input */
    double x;
    std::cout << "Enter a value for x (other than 2.0): ";
    std::cin >> x;
    /* ANSWER (Task 2.0): Fetch input from the user. */

    /* Validate */
    if (std::fabs(x - banned_number) < small_number) {
        std::cerr << "Error: x cannot be " << banned_number << std::endl;
        return 1;
    }
    /**
     * ANSWER (Task 2.1):
     * Check if the input is close to the banned number, allowing for floating point errors.
     */

    /* Output */
    cout << "When x = " << x << ", the function y = 1/(x^2 - 2) is equal to ";
    double y = 1 / (std::pow(x, 2.0) - 2.0);
    cout << y << endl;
    /* ANSWER (Task 2.0): Calculate the function and output the result. */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}