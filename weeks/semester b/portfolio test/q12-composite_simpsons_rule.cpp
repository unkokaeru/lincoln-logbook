/**
 * @file q12-composite_simpsons_rule.cpp
 * @author William Fayers (27378661)
 * @brief Composite Simpson's Rule to approximate \int_{0}^{2}(2x^{4}-x^{3}+3x^{2}+x+1)dx
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
 * @brief The polynomial f(x)=2x^{4}-x^{3}+3x^{2}+x+1
 * @param x The value to evaluate the polynomial at
 * @return The value of the polynomial at x
 */
float function(float x)
{
    return 2 * pow(x, 4) - pow(x, 3) + 3 * pow(x, 2) + x + 1;
}

/**
 * @brief Composite Simpson's Rule to approximate \int_{a}^{b}f(x)dx
 * @param lower_limit The lower limit of integration
 * @param upper_limit The upper limit of integration
 * @param number_of_intervals The number of sub-intervals (must be even)
 * @return The approximate value of the integral
 */
float composite_simpsons_rule(float lower_limit, float upper_limit, int number_of_intervals)
{
    if (number_of_intervals % 2 != 0)
    {
        std::cerr << "Number of intervals must be even." << std::endl;
        return 0.0f;
    }

    float interval_width = (upper_limit - lower_limit) / number_of_intervals;
    float sum = function(lower_limit) + function(upper_limit);

    for (int interval = 1; interval < number_of_intervals; ++interval)
    {
        float current_position = lower_limit + interval * interval_width;
        if (interval % 2 == 0)
        {
            sum += 2 * function(current_position);
        }
        else
        {
            sum += 4 * function(current_position);
        }
    }

    return (interval_width / 3) * sum;
}

/**
 * @brief Main function to run the composite Simpson's rule and print results
 * @return int
 */
int main()
{
    float lower_limit = 0.0f;
    float upper_limit = 2.0f;
    int number_of_intervals = 2;
    float previous_estimate = 0.0f;
    float current_estimate = composite_simpsons_rule(lower_limit, upper_limit, number_of_intervals);
    float relative_error = 1.0f; // Initialise to a value greater than the tolerance

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "N\tEstimate\tRelative Error\n";
    std::cout << "-------------------------------------\n";

    while (relative_error > 1e-5)
    {
        std::cout << number_of_intervals << "\t" << current_estimate << "\t" << relative_error << "\n";
        previous_estimate = current_estimate;
        number_of_intervals += 2; // Increment by 2 to keep it even
        current_estimate = composite_simpsons_rule(lower_limit, upper_limit, number_of_intervals);
        relative_error = fabs((current_estimate - previous_estimate) / current_estimate);
    }

    std::cout << "The tolerance of 1e-5 has been reached with " << number_of_intervals << " sub-intervals!" << std::endl;
    std::cout << "Final estimate: " << current_estimate << std::endl;

    return 0;
}

// Output:
// N	Estimate	Relative Error
// -------------------------------------
// N       Estimate        Relative Error
// -------------------------------------
// 2       21.33333        1.00000
// 4       20.83333        0.02400
// 6       20.80659        0.00129
// 8       20.80208        0.00022
// 10      20.80086        0.00006
// 12      20.80041        0.00002
// The tolerance of 1e-5 has been reached with 14 sub-intervals!
// Final estimate: 20.80022