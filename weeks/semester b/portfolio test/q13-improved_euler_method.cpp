/**
 * @file q13-improved_euler_method.cpp
 * @author William Fayers (27378661)
 * @brief Improved Euler's Method to solve dy/dx = x + y with y(0) = 1 over the interval [0, 1]
 * @version 0.1.0
 * @date 2025-04-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <cmath>
#include <iomanip>
#include <iostream>

/**
 * @brief Exact solution of the differential equation dy/dx = x + y
 * @param x The value at which to evaluate the exact solution
 * @return The exact solution at x
 */
float exact_solution(float x)
{
    return 2 * exp(x) - x - 1;
}

/**
 * @brief Improved Euler's Method to solve dy/dx = x + y
 * @param initial_x_value Initial value of x
 * @param initial_y_value Initial value of y
 * @param step_size Step size
 * @param number_of_iterations Number of iterations
 * @return The approximate value of y after n iterations
 */
float improved_euler_method(
    float initial_x_value,
    float initial_y_value,
    float step_size,
    int number_of_iterations)
{
    for (int iteration = 0; iteration < number_of_iterations; ++iteration)
    {
        float y_predictor = initial_y_value + step_size * (initial_x_value + initial_y_value);
        float y_corrector = initial_y_value + (step_size / 2) * ((initial_x_value + initial_y_value) + (initial_x_value + step_size + y_predictor));
        initial_x_value += step_size;
        initial_y_value = y_corrector;
    }

    return initial_y_value;
}

/**
 * @brief Main function to run the improved Euler's method and print results
 * @return int
 */
int main()
{
    float number_of_iterations, error_tolerance, initial_x_value, initial_y_value;

    std::cout << "How many iterations would you like to perform (e.g. 20)? ";
    std::cin >> number_of_iterations;
    std::cout << "What is the error tolerance (e.g. 1e-4)? ";
    std::cin >> error_tolerance;
    std::cout << "What is the initial x value (e.g. 0.0)? ";
    std::cin >> initial_x_value;
    std::cout << "What is the initial y value (e.g. 1.0)? ";
    std::cin >> initial_y_value;
    float step_size = 1.0f / number_of_iterations; // Step size calculation (arbitrary calculation)

    std::cout << std::fixed << std::setprecision(4); // Set precision for output

    std::cout << "Iteration\tX_n\t\tY_n Approximation" << std::endl;
    for (int iterations = 0; iterations <= number_of_iterations; ++iterations)
    {
        float x_n = initial_x_value + iterations * step_size;
        float y_n = improved_euler_method(initial_x_value, initial_y_value, step_size, iterations);
        std::cout << iterations << "\t\t" << x_n << "\t\t" << y_n << std::endl;
    }

    float final_approximation = improved_euler_method(initial_x_value, initial_y_value, step_size, number_of_iterations);
    float exact_value = exact_solution(initial_x_value + number_of_iterations * step_size);
    float absolute_error = fabs(final_approximation - exact_value);

    std::cout << "Final approximation of y(x): " << final_approximation << std::endl;
    std::cout << "Exact solution: " << exact_value << std::endl;
    std::cout << "Absolute error: " << absolute_error << std::endl;

    if (absolute_error < 1e-4)
    {
        std::cout << "Error is within tolerance." << std::endl;
    }
    else
    {
        std::cout << "Error is not within tolerance." << std::endl;
    }

    return 0;
}

// Output:
// How many iterations would you like to perform (e.g. 20)? 20
// What is the error tolerance (e.g. 1e-4)? 1e-4
// What is the initial x value (e.g. 0.0)? 0.0
// What is the initial y value (e.g. 1.0)? 1.0
// Iteration       X_n             Y_n Approximation
// 0               0.0000          1.0000
// 1               0.0500          1.0525
// 2               0.1000          1.1103
// 3               0.1500          1.1735
// 4               0.2000          1.2426
// 5               0.2500          1.3178
// 6               0.3000          1.3994
// 7               0.3500          1.4877
// 8               0.4000          1.5832
// 9               0.4500          1.6861
// 10              0.5000          1.7968
// 11              0.5500          1.9157
// 12              0.6000          2.0434
// 13              0.6500          2.1801
// 14              0.7000          2.3264
// 15              0.7500          2.4827
// 16              0.8000          2.6497
// 17              0.8500          2.8277
// 18              0.9000          3.0174
// 19              0.9500          3.2194
// 20              1.0000          3.4344
// Final approximation of y(x): 3.4344
// Exact solution: 3.4366
// Absolute error: 0.0022
// Error is not within tolerance.