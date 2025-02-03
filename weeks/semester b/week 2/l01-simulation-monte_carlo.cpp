/**
 * @file l01-simulation-monte_carlo.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Implementation of a Monte Carlo simulation for statistical analysis.
 * @version 0.1.0
 * @date 2025-02-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <random>

/**
 * @brief Approximates the natural logarithm of a given upper limit using the Monte Carlo method.
 *
 * @param upperLimit The upper limit for the natural logarithm calculation.
 * @param iterationCount The number of iterations to perform in the Monte Carlo simulation.
 * @return double The approximate value of the natural logarithm of the upper limit.
 *
 * @details
 * This function uses the Monte Carlo method to approximate the natural logarithm of a given upper
 * limit.
 * The steps involved in the calculation are as follows:
 * 1. Initialise a random number generator and two uniform distributions: one for the x-values in
 * the range [1, upperLimit] and one for the y-values in the range [0, 1].
 * 2. Initialise a counter to keep track of the number of points that fall under the curve
 * \( y = \frac{1}{x} \).
 * 3. For each iteration:
 *    - Generate a random x-value from the distribution [1, upperLimit].
 *    - Generate a random y-value from the distribution [0, 1].
 *    - Check if the random y-value is less than or equal to \( \frac{1}{x} \). If it is, increment
 *      the counter.
 * 4. Calculate the approximate value of the natural logarithm using the formula:
 *    \[
 *    \text{approximateValue} = \frac{\text{underCurveCount} \times (\text{upperLimit} - 1)}
 *    {\text{iterationCount}}
 *    \]
 * 5. Return the approximate value.
 */
double calculate_natural_log_monte_carlo(double upperLimit, int iterationCount)
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<double> distributionY(0.0, 1.0);
    std::uniform_real_distribution<double> distributionX(1.0, upperLimit);

    int underCurveCount = 0;
    for (int iterationNumber = 0; iterationNumber < iterationCount; iterationNumber++)
    {
        double randomX = distributionX(generator);
        double randomY = distributionY(generator);
        if (randomY <= 1.0 / randomX)
        {
            underCurveCount++;
        }
    }

    double approximateValue = static_cast<double>(underCurveCount) * (upperLimit - 1.0) / static_cast<double>(iterationCount);
    return approximateValue;
}

/**
 * @brief Calculates an approximation of the value of pi using the Monte Carlo method.
 *
 * @param iterationCount
 * @return double
 *
 * @details
 * This function uses the Monte Carlo method to approximate the value of pi.
 * The steps involved in the calculation are as follows:
 * 1. Initialise a random number generator and two uniform distributions: one for the x-values in
 * the range [-1, 1] and one for the y-values in the range [-1, 1].
 * 2. Initialise a counter to keep track of the number of points that fall inside the unit circle.
 * 3. For each iteration:
 *   - Generate a random x-value from the distribution [-1, 1].
 *   - Generate a random y-value from the distribution [-1, 1].
 *   - Check if the point (x, y) falls inside the unit circle by calculating the distance from the
 *     origin (0, 0) and comparing it to the radius of the circle (1). If it falls inside, increment the
 *     counter.
 * 4. Calculate the approximate value of pi using the formula:
 *    \[
 *    \text{piApproximation} = \frac{4 \times \text{pointsInsideCircle}}{\text{iterationCount}}
 *    \]
 * 5. Return the approximate value of pi.
 */
double calculate_pi_monte_carlo(int iterationCount)
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    int pointsInsideCircle = 0;
    for (int iterationNumber = 0; iterationNumber < iterationCount; ++iterationNumber)
    {
        double xCoordinate = distribution(generator);
        double yCoordinate = distribution(generator);

        if ((xCoordinate * xCoordinate + yCoordinate * yCoordinate) <= 1.0)
        {
            pointsInsideCircle++;
        }
    }

    double piApproximation = 4.0 * static_cast<double>(pointsInsideCircle) /
                             static_cast<double>(iterationCount);
    return piApproximation;
}

/**
 * @brief Demonstrates the convergence of the pi approximation with increasing iterations.
 *
 * @param maximumIterations The total number of iterations to use for the final approximation.
 * @param steps The number of intermediate approximations to display.
 */
void demonstrate_pi_convergence(int maximumIterations, int steps)
{
    std::cout << "\nConvergence of Pi (Monte Carlo):\n";
    int stepSize = (steps > 0) ? (maximumIterations / steps) : maximumIterations;

    for (int stepIndex = 1; stepIndex <= steps; ++stepIndex)
    {
        int currentIterations = stepIndex * stepSize;
        double approximatePi = calculate_pi_monte_carlo(currentIterations);
        std::cout << "Iterations: " << currentIterations
                  << "  Approx: " << approximatePi
                  << "  Error: " << std::fabs(approximatePi - M_PI)
                  << std::endl;
    }
}

/**
 * @brief Main function to demonstrate the Monte Carlo simulation for natural log and pi.
 *
 * @return int
 */
int main()
{
    double desiredValue;
    int totalIterations;
    std::cout << "Enter a value greater than 1 to approximate its natural log: ";
    std::cin >> desiredValue;
    std::cout << "How many iterations should be used for the log estimation? ";
    std::cin >> totalIterations;

    double approximation = calculate_natural_log_monte_carlo(desiredValue, totalIterations);
    std::cout << "Monte Carlo approximation (log): " << approximation << std::endl;
    std::cout << "C++ log function result: " << std::log(desiredValue) << std::endl;

    std::cout << "\nHow many iterations should be used to approximate pi? ";
    std::cin >> totalIterations;

    double piValue = calculate_pi_monte_carlo(totalIterations);
    std::cout << "Estimated pi value: " << piValue << std::endl;
    std::cout << "Reference M_PI: " << M_PI << std::endl;

    demonstrate_pi_convergence(totalIterations, 10);

    return 0;
}