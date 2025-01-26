/**
 * @file l03-basic_use-pascals_triangle.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Exploring cout and special characters to print Pascal's Triangle.
 * @version 0.1.0
 * @date 2024-09-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;


/**
 * @brief Main function to run the program.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
    /* Print Pascal's Triangle up to n=5 with cout and the tab character to center the numbers */
    cout << "n\t\t\t\t   Pascal's Triangle up to n=5\n";
    cout << "0\t\t\t\t\t\t1\n";
    cout << "1\t\t\t\t\t1\t\t1\n";
    cout << "2\t\t\t\t1\t\t2\t\t1\n";
    cout << "3\t\t\t1\t\t3\t\t3\t\t1\n";
    cout << "4\t\t1\t\t4\t\t6\t\t4\t\t1\n";
    cout << "5\t1\t\t5\t\t10\t\t10\t\t5\t\t1\n";

    cout << "\t\t\t\t      Made by William Fayers\n";
    /**
     * ANSWER (Task 3.1):
     * I used the tab character, `\t` to center the numbers in the Pascal's Triangle, along with
     * `cout` to print the numbers. This ended up with a fairly nice looking Pascal's Triangle.
     */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}