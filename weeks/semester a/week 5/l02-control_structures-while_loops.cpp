/**
 * @file l02-control_structures-while_loops.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explore while loops in C++
 * @version 0.1.0
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>
#include <iomanip>


/**
 * @brief Explore while loops in C++ by finding the statistical properties of a set of numbers.
 * 
 */
void find_statistical_properties() {
    /* Declare inital variables */
    double sum = 0;
    double sum_of_squares = 0;
    double min = 1e10;
    double max = -1e10;
    /**
     * ANSWER (Task 2.1):
     * Initial variables are declared, including the new max variable and
     * sum of squares variable.
     */

    /* Set precision */
    std::setprecision(10);
    /* ANSWER (Task 2.1): The precision is set to 10 decimal places. */

    /* Input/sum loop */
    std::cout << "Enter six numbers, separted by a single space: ";
    int count = 0;
    while (count < 6) {
        double number;
        std::cin >> number;

        sum += number;
        sum_of_squares += number * number;

        if (number < min) {
            min = number;
        }

        if (number > max) {
            max = number;
        }

        count++;
    }
    std::cout << std::endl;
    /**
     * ANSWER (Task 2.1)
     * The while loop loops over six inputted numbers, finding both their sum and the new
     * sum of sqaures, whilst keeping track of the minimum value and new maximum value.
     */

    /* Calculate mean */
    double mean = sum / 6;
    /* ANSWER (Task 2.1): The mean is calculated by dividing the sum by the number of values. */

    /* Calculate standard deviation using the Naive algorithm */
    double variance = ((sum_of_squares / 6) - (mean * mean)) * 6 / 5;
    double standard_deviation = std::sqrt(variance);
    /* ANSWER (Task 2.1): Calculate the variance and hence standard deviation. */

    /* Output results */
    std::cout << "The minimum value is: " << min << std::endl;
    std::cout << "The maximum value is: " << max << std::endl;
    std::cout << "The mean value is: " << mean << std::endl;
    std::cout << "The standard deviation is: " << standard_deviation << std::endl;
    /* ANSWER (Task 2.1): The calculated values are then outputted to the console. */
}


void find_factorial() {
    /* Declare initial variables */
    int current_number = 1;
    long long factorial_result = 1;
    /**
     * ANSWER (Task 2.2):
     * Initial variables are declared, although slightly renamed to be more descriptive,
     * and the factorial result is set to a long long to handle larger numbers (I did this
     * slightly earlier than asked in the tasks, should be part of 2.3), although this
     * is still only valid up to 20!.
     */

    /* Input the number to calculate the factorial of */
    std::cout << "Enter a positive integer to calculate its factorial: ";
    int input_number;
    std::cin >> input_number;
    if (input_number < 0) {
        std::cerr << "Factorial is not defined for negative numbers." << std::endl;
        return;
    }
    /**
     * ANSWER (Task 2.3):
     * The user is prompted to input a positive integer, and if the input is negative,
     * an error message is outputted and the program exits.
     */

    /* Calculate the factorial */
    do {
        factorial_result *= current_number;
        current_number++;
    } while (current_number <= input_number);
    /* ANSWER (Task 2.2): The factorial is calculated using a do-while loop. */

    /* Output the result */
    std::cout << "The factorial of " << input_number << " is: " << factorial_result << std::endl;
    /* ANSWER (Task 2.2): The calculated factorial is outputted to the console. */
}


/**
 * @brief The main function to run the program.
 * 
 * @return int Success or failure (0 or 1).
 */
int main () {
    // find_statistical_properties();

    find_factorial();

    /* Return 0 to indicate the program ran successfully */
    return 0;
}