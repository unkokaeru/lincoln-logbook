/**
 * @file l03-algorithms-babylonian_square_root.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Calculate the square root of a number using the Babylonian method
 * @version 0.1.0
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cmath>


/**
 * @brief Calculate the square root of a number using the Babylonian method
 * 
 * @param number The number to calculate the square root of
 * @param tolerance The tolerance to which the square root should be calculated
 * @return double The square root of the number
 */
double babylonian_square_root(double number, double tolerance = 0.0001) {
    double guess = number / 2;
    double previous_guess = 0;

    while (std::abs(guess - previous_guess) > tolerance) {
        previous_guess = guess;
        guess = (guess + number / guess) / 2;
    }

    return guess;
}


int main() {
    double number = 0;
    std::cout << "Enter a number: ";
    std::cin >> number;

    double square_root = babylonian_square_root(number);
    std::cout << "The square root of " << number << " is " << square_root << std::endl;

    return 0;
}