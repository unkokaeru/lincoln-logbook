/**
 * @file l02-applications-maclaurin.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Calculating the Maclaurin series of functions using C++
 * @version 0.1.0
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

// Function 1: \frac{1}{\pi + x}
// Function 2: \ln(3 + x)

/**
 * @brief Function to calculate the Maclaurin series of \frac{1}{\pi + x}.
 *
 * @param x Value of x.
 * @param terms_to_calculate Number of terms to calculate.
 * @return double Maclaurin series value.
 */
double maclaurin_series_1(double x, int terms_to_calculate)
{
    double sum = 0.0;
    for (int term = 0; term < terms_to_calculate; ++term)
    {
        sum += std::pow(-1, term) * std::pow(x / M_PI, term) / M_PI;
    }
    return sum;
}

/**
 * @brief Function to calculate the Maclaurin series of \ln(3 + x).
 *
 * @param x Value of x.
 * @param terms_to_calculate Number of terms to calculate.
 * @return double Maclaurin series value.
 */
double maclaurin_series_2(double x, int terms_to_calculate)
{
    double sum = std::log(3.0);
    for (int term = 1; term <= terms_to_calculate; ++term)
    {
        sum += std::pow(-1, term + 1) * std::pow(x / 3.0, term) / term;
    }
    return sum;
}

/**
 * @brief Function to display the Maclaurin series of a function.
 *
 * @param x Value of x.
 * @param terms_to_calculate Number of terms to calculate.
 */
void display_maclaurin_series(double x, int terms_to_calculate)
{
    std::cout << "Calculating the Maclaurin series of 1/(pi + x) at x = " << x
              << " with " << terms_to_calculate << " terms." << std::endl;
    std::cout << "Result: " << maclaurin_series_1(x, terms_to_calculate) << std::endl;
    std::cout << "Expected: " << 1.0 / (M_PI + x) << std::endl;

    std::cout << "Calculating the Maclaurin series of ln(3 + x) at x = " << x
              << " with " << terms_to_calculate << " terms." << std::endl;
    std::cout << "Result: " << maclaurin_series_2(x, terms_to_calculate) << std::endl;
    std::cout << "Expected: " << std::log(3 + x) << std::endl;
}

/**
 * @brief Main function to run the Maclaurin series calculator.
 *
 * @return int
 */
int main()
{
    display_maclaurin_series(0.5, 100);
}