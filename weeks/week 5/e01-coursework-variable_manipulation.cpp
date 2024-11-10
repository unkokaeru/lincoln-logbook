/**
 * @file e01-coursework-variable_manipulation.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explaining the manipulation of variables in C++
 * @version 0.1.0
 * @date 2024-11-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>
/* ANSWER (Task 6.0): Include the necessary libraries. */


int main() {
    /* Initalise the variables */
    int x = 25;
    int y = 18;
    double pay_rate = 12.50;
    int first_number = 10;
    int temporary_number = first_number;
    /* ANSWER (Task 6.1): Declare the variables with their respective data types. */

    /* Output the unused variables to avoid warnings */
    std::cout << "The pay rate is: " << pay_rate << std::endl;
    std::cout << "The first number is: " << first_number << std::endl;
    std::cout << "The temporary number is: " << temporary_number << std::endl;

    /* Swap the values of x and y using a temporary variable */
    int temporary_x = x;
    x = y;
    y = temporary_x;
    /* ANSWER (Task 6.2): Swap the values of x and y using a temporary variable. */

    /* Output and evaluate an expression */
    std::cout << "The value of x is: " << x << std::endl;
    std::cout << "The value of y is: " << y << std::endl;
    double evaluated_expression = (x + 12) / (y - 18 + pow(x, 3)); // Unsure if correct expression
    std::cout << "Substituting these values into the expression (x + 12) / (y - 18 + x^3) gives: "
                << evaluated_expression << std::endl;
    /* ANSWER (Task 6.3): Output the values of x and y and evaluate the expression. */

    return 0;
}