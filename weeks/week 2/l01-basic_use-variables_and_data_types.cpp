/**
 * @file l01-basic_use-variables_and_data_types.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Declaration and use of integer variables and data types in C++.
 * @version 0.1.0
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>


/**
 * @brief Halloween-themed calculator
 * 
 * @details Calculates the number of candies each person gets when dividing
 * the total number of candies equally among the number of people.
 *
 * @return int 
 */
int main() {
    /* Declare and initialise variables */
    int total_children = 10;
    int candies_per_child = 5;
    int extra_candies = 10;
    /* ANSWER (Task 1.2): Declare and initalise the variables */

    /* Initialise the total number of candies */
    unsigned short int total_candies;
    /**
     * ANSWER (Task 1.2):
     * `unsigned short int` can be broken down into three parts:\n
     * - `unsigned`: This means the variable can only store positive values, which fits the context
     * of candies, as we cannot have a negative number of candies.\n
     * - `short`: This means the variable can store values between 0 and 65,535, which is more than
     * enough for the number of candies we are calculating.\n
     * - `int`: This means the variable is an integer, which is the type of data we are working
     * with.\n
     * Hence, `unsigned short int` is the most appropriate data type for the variable
     * `total_candies`.
     */

    /* Calculate the total number of candies */
    total_candies = total_children * candies_per_child + extra_candies;
    /**
     * ANSWER (Task 1.2):
     * Calculate the total number of candies by multipling the average per child by the total number
     * of children, then adding the extra candies.
     */

    /* Output results */
    std::cout << "HALLOWEEN CANDY CALCULATOR" << std::endl;
    std::cout << "Total Children: " << total_children << std::endl;
    std::cout << "Candies per Child: " << candies_per_child << std::endl;
    std::cout << "Extra Candies: " << extra_candies << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "Total Candies: " << total_candies << std::endl;
    /* ANSWER (Task 1.2): Output the starting values and the total number of candies */

    /* Return 0 to indicate the program ran successfully */
    return 0;
    /* ANSWER (Task 1.2): Return 0 to indicate the program ran successfully */
}