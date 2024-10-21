/**
 * @file l01-control_structures-if_else_statements.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explores the use of if-else statements in C++
 * @version 0.1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cmath>
#include <math.h>
#include <tuple>


/**
 * @brief Evaluate the first piecewise function.
 * 
 * @param x 
 * @param y 
 * @return std::tuple<double, double> 
 */
std::tuple<double, double> evaluate_function1(double x, double &y) {
    if (x >= 2) {
        std::cout << "x is greater than or equal to 2, so \n";
        std::cout << "y = x^3 + sqrt(x) = ";
        y = pow(x, 3) + sqrt(x);
    } else if (x > 0.5 && x < 2) {
        std::cout << "x is between 0.5 and 2, so \n";
        std::cout << "y = 1 - exp(x) = ";
        y = 1 - exp(x);
    } else {
        std::cout << "x is less than or equal to 0.5, so \n";
        std::cout << "y = |x + 5| = ";
        y = fabs(x + 5);
    }

    return std::make_tuple(x, y);
}
/* ANSWER (Task 1.1): Copy the function to calculate the first piecewise function. */


/**
 * @brief Evaluate the second piecewise function.
 * 
 * @param x 
 * @param y 
 * @return std::tuple<double, double> 
 */
std::tuple<double, double> evaluate_function2(double x, double &y) {
    if (x < -M_PI/2) {
        std::cout << "x is less than -pi/2, so \n";
        std::cout << "y = -1 - pi/2 = ";
        y = -1 - M_PI/2;
    } else if (x >= -M_PI/2 && x <= 0) {
        std::cout << "x is between -pi/2 and 0, so \n";
        std::cout << "y = sin(x) + x = ";
        y = sin(x) + x;
    } else {
        std::cout << "x is greater than 0, so \n";
        std::cout << "y = x = ";
        y = x;
    }

    return std::make_tuple(x, y);
}
/* ANSWER (Task 1.3): Evaluate the second piecewise function. */


/**
 * @brief The main function of the program.
 * 
 * @return int 
 */
int main() {
    double x, y;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    /* Evaluate the first piecewise function */
    // evaluate_function1(x, y);  // uncomment to evalate the first piecewise function
    /**
     * ANSWER (Task 1.2)
     * The first piecewise function is defined as:
     * $$
     * y = \begin{cases}
     * x^{3} + \sqrt{x} & \text{if } x \geq 2 \\
     * 1 - \exp(x) & \text{if } 0.5 < x < 2 \\
     * |x + 5| & \text{if } x \leq 0.5
     * \end{cases}
     * $$
     */

    /* Evaluate the second piecewise function */
    evaluate_function2(x, y);
    /**
     * ANSWER (Task 1.3)
     * The second piecewise function is defined as:
     * $$
     * y = \begin{cases}
     * -1 - \frac{\pi}{2} & \text{if } x \lt -\frac{\pi}{2} \\
     * \sin(x) + x &  \text{if } -\frac{\pi}{2} \leq x \leq 0 \\
     * x & x \gt 0
     * \end{cases}
     * $$
     */

    std::cout << y << std::endl;

    return 0;
}