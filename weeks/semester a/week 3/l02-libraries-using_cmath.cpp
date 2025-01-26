/**
 * @file l02-libraries-using_cmath.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Experimenting with the cmath library in C++
 * @version 0.1.0
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>


/**
 * @brief Calculate the hyperbolic cosecant of a number.
 * 
 * @param x The number to calculate the hyperbolic cosecant of.
 * @return double The hyperbolic cosecant of x, or NAN if x is zero.
 */
double csch(double x) {
    if (x == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return NAN;
    }

    double answer = 1 / sinh(x);
    return answer;
}
/**
 * ANSWER (Task 2.3):
 * Implement a custom csch function that calculates the hyperbolic cosecant of a number.
 */

/**
 * @brief Experimenting with the cmath library in C++.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
    /* Calculate the square root of 9.0 */
    std::cout << sqrt(9.0) << std::endl;
    /* ANSWER (Task 2.1): Calculate the square root of 9.0, which resulted in 3. */

    std::cout << "---" << std::endl;

    /* Calculate the natural logarithm of 1.1 */
    std::cout << log(1.1) << std::endl;
    /* ANSWER (Task 2.1): Calculate the natural logarithm of 1.1, which resulted in 0.0953102. */

    /* Calculate 2.5 raised to the power of 3.0 */
    std::cout << pow(2.5, 3.0) << std::endl;
    /* ANSWER (Task 2.1): Calculate 2.5 raised to the power of 3.0, which resulted in 15.625. */

    /* Calculate the ceiling of 4.1 */
    std::cout << ceil(4.1) << std::endl;
    /* ANSWER (Task 2.1): Calculate the ceiling of 4.1, which resulted in 5. */

    /* Calculate the expression (7 + sqrt(7.0)) / 3.0 */
    std::cout << (7 + sqrt(7.0)) / 3.0 << std::endl;
    /* ANSWER (Task 2.1): Calculate (7 + sqrt(7.0)) / 3.0, which resulted in 3.21525. */

    /* Calculate the hyperbolic tangent of 0.342 */
    std::cout << tanh(0.342) << std::endl;
    /* ANSWER (Task 2.1): Calculate the hyperbolic tan of 0.342, which resulted in 0.329262 */

    /* Calculate the remainder of 11.0 divided by 4.0 */
    std::cout << fmod(11.0, 4.0) << std::endl;
    /* ANSWER (Task 2.1): Calculate the remainder of 11.0 divided by 4.0, which resulted in 3. */

    /* Calculate the absolute value of -9 */
    std::cout << abs(-9) << std::endl;
    /* ANSWER (Task 2.1): Calculate the absolute value of -9, which resulted in 9. */

    /* Calculate the absolute value of -4.5 */
    std::cout << fabs(-4.5) << std::endl;
    /* ANSWER (Task 2.1): Calculate the (floating) absolute value of -4.5, which resulted in 4.5. */

    /* Calculate the floor of 8.8 */
    std::cout << floor(8.8) << std::endl;
    /* ANSWER (Task 2.1): Calculate the floor of 8.8, which resulted in 8. */

    /* Calculate the base-10 logarithm of 1.0 */
    std::cout << log10(1.0) << std::endl;
    /* ANSWER (Task 2.1): Calculate the base-10 logarithm of 1.0, which resulted in 0. */

    /* Calculate the cube root of 10.0 */
    std::cout << cbrt(10.0) << std::endl;
    /* ANSWER (Task 2.1): Calculate the cube root of 10.0, which resulted in 2.15443. */

    std::cout << "---" << std::endl;

    /* Perform a complex calculation */
    double calculation_1 = (2.0 / 15.0) - 
                    (((1.0 / 3.0) - (sin(0.5))) / (-5.0 / 13.0)) + 
                    (((1.0 / 3.0) - (tanh(0.3))) / (-(1.0 / 7.0) - (2.0)));
    std::cout << calculation_1 << std::endl;
    /**
     * ANSWER (Task 2.2):
     * Perform the complex calculation (resulting in -0.266116):
     * $$
     * \frac{2}{15}
     * - \frac{\left(\frac{1}{3}-\sin(0.5)\right)}{-\frac{5}{13}}
     * + \frac{\left(\frac{1}{3}-\tanh(0.3)\right)}{-\frac{1}{7}-2}
     * $$
     */

    /* Perform another complex calculation */
    double calculation_2 = pow(
        fabs(-9.0 * pow(-5.0, -2.0) - 1.0),
        sin(1.0)
    ) * (
        (pow((4.0 / 2.0), 2.0) + pow((1.0 / 3.0), -2.0) - cbrt(-5.0)) /
        sqrt(17.0 / 3.0)
    );
    std::cout << calculation_2 << std::endl;
    /**
     * ANSWER (Task 2.2):
     * Perform the complex calculation (resulting in 8.00419):
     * $$
     * \left|-9\cdot(-5)^{-2}-1\right|^{\sin(1.0)}\cdot
     * \frac{\left(\left(\frac{4}{2}\right)^{2}+\left(\frac{1}{3}\right)^{-2}-\sqrt[3]{-5}\right)}
     * {\sqrt{\frac{17}{3}}}
     * $$
     */

    std::cout << "---" << std::endl;

    /* Input a value for x */
    double x;
    std::cout << "Calculation of the hyperbolic cosecant function..." << std::endl;
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    /* ANSWER (Task 2.3): Prompt the user for a value of x. */
    
    /* Perform a custom csch function */
    double y = csch(x);
    if (!std::isnan(y)) {
        std::cout << "Hyperbolic cosecant of " << x << " is: " << y << std::endl;
    } else {
        std::cout << "Hyperbolic cosecant is undefined for x = 0." << std::endl;
    }
    /* ANSWER (Task 2.3): Calculate the hyperbolic cosecant of x using the custom csch function. */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}