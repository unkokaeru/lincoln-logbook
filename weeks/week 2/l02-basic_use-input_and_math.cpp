/**
 * @file l02-basic_use-input_and_math.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Demonstrating basic input and math operations in C++
 * @version 0.1.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>
#include <stdexcept>


/**
 * @brief Basic calculator
 * 
 * @details Calculates the sum, difference, product, and remainder of two inputted numbers.
 */
void basic_calculator() {
    /* Declare variables */
    float number1, number2, result;

    /* Input the numbers */
    std::cout << "Enter the first number: ";
    std::cin >> number1;
    std::cout << "Enter the second number: ";
    std::cin >> number2;

    /* Separate the input and output */
    std::cout << "---" << std::endl;

    /* Calculate the sum */
    result = number1 + number2;
    std::cout << "Sum: " << result << std::endl;

    /* Calculate the difference */
    result = number1 - number2;
    std::cout << "Difference: " << result << std::endl;

    /* Calculate the product */
    result = number1 * number2;
    std::cout << "Product: " << result << std::endl;

    /* Calculate the quotient */
    result = number1 / number2;
    std::cout << "Quotient: " << result << std::endl;
    /* ANSWER (Task 2.1): Calculate the quotient on top of the given code for completion. */

    /* Calculate the remainder */
    result = fmod(number1, number2);
    std::cout << "Remainder: " << result << std::endl;
    /**
     * ANSWER (Task 2.2):
     * Calculate the remainder using the cmath library function fmod instead of `%` so
     * that we can handle floating-point numbers. To avoid using an external library, we
     * could cast the numbers to integers and use the `%` operator, or even evaluate the
     * remainder manually using the formula:
     * `remainder = number1 - number2 * floor(number1 / number2)`.
     */
}


/**
 * @brief Calculate the gravitational force between two masses.
 * 
 * @param mass1 Mass of the first object in kg.
 * @param mass2 Mass of the second object in kg.
 * @param distance Distance between the two objects in meters.
 * @return Gravitational force in Newtons.
 * 
 * @throw std::invalid_argument Throws an error if the distance is zero.
 */
float calculate_gravitational_force(float mass1, float mass2, float distance) {
    const float G = 6.67430e-11;
    if (distance == 0) {
        throw std::invalid_argument("Distance cannot be zero.");
    }
    return (G * mass1 * mass2) / (distance * distance);
}
/**
 * ANSWER (Task 2.3):
 * We can create a function called `calculate_gravitational_force` that takes the masses of two
 * objects and the distance between them as input parameters. The function calculates the
 * gravitational force between the two objects using the formula:\n
 * $F = \frac{G * m_{1} * m_{2}}{d^{2}}$
 */


/**
 * @brief Main function to run the program.
 * 
 * @details Controls the flow of the program, calling the basic_calculator function and
 * calculating the gravitational force between two objects.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
    /* Call the basic_calculator function */
    basic_calculator();

    /* Separate the two tasks */
    std::cout << "---" << std::endl;

    /* Declare variables */
    float mass1, mass2, distance;
    /* ANSWER (Task 2.3): Declare variables to store the masses and distance. */

    /* Input the masses and distance */
    std::cout << "Enter the mass of the first object (kg): ";
    std::cin >> mass1;
    std::cout << "Enter the mass of the second object (kg): ";
    std::cin >> mass2;
    std::cout << "Enter the distance between the objects (m): ";
    std::cin >> distance;
    /* ANSWER (Task 2.3): We then input the masses and distance. */

    /* Calculate and output the gravitational force */
    try {
        float force = calculate_gravitational_force(mass1, mass2, distance);
        std::cout << "Gravitational Force: " << force << " N" << std::endl;
    } catch (std::invalid_argument& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    /* ANSWER (Task 2.3): And finally we call the function, catching any exceptions that occur. */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}