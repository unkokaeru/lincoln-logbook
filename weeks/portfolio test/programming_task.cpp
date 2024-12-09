/**
 * @file programming_task.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Calculate the sum of a given series
 * @version 0.2.0
 * @date 2024-12-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <cstdlib>
#include <stdexcept>
#include <functional>


/**
 * @brief Input any data type number with error handling and buffer clearing,
 * allowing max 3 attempts subject to a given condition
 *
 * @tparam T The data type of the number to input
 * @tparam T The data type of the number to input
 * @param prompt The prompt to display to the user
 * @param condition The condition that the number must satisfy
 * @return T The number input by the user
 */
template <typename T>
T input_number(std::string prompt, std::function<bool(T)> condition) {
    /* Loop to allow 3 attempts */
    for (int attempt = 0; attempt < 3; attempt++) {
        /* Output the prompt */
        std::cout << prompt;

        /* Attempt to read a number */
        T number;
        if (std::cin >> number && condition(number)) {
            /* If successful, return the number */
            return number;
        } else {
            /* If unsuccessful, clear the buffer and output an error message */
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    /* If too many invalid inputs, output an error message and exit */
    std::cerr << "Too many invalid inputs. Exiting..." << std::endl;
    exit(1);
}

/**
 * @brief Calculate the sum of a given series
 * The series is $S = \sum\limits_{r=0}^{N} \frac{\sqrt{a}(1-r^{b})}{1+r^{2}}$,
 * where a, b are two parameters and N is the number of terms in the series.
 * 
 * @return int
 */
int main() {
    /* Input the parameters a, b and the number of terms N */
    double parameter_a = input_number<double>(
        "Enter parameter a: ",
        [](double a) { return a >= 0; });
    double parameter_b = input_number<double>(
        "Enter parameter b: ",
        [](double) { return true; });
    int number_of_terms = input_number<int>(
        "Enter number of terms: ",
        [](int N) { return N >= 0; });

    /* Loop to calculate sum, starting with term 0 */
    double sum = 0;
    for (int term_number = 0; term_number <= number_of_terms; term_number++) {
        /* Calculate the numerator sqrt(a) * (1 - r^b) and the denominator 1 + r^2 */
        double numerator = std::sqrt(parameter_a) * (1 - std::pow(term_number, parameter_b));
        double denominator = 1 + std::pow(term_number, 2);

        /* Calculate the term and add it to the sum */
        double term = numerator / denominator;
        sum += term;

        /* If the term is NaN or infinite, output an error message and exit */
        if (std::isnan(term) || std::isinf(term)) {
            std::cerr << "Error: Term is NaN or infinite. Exiting..." << std::endl;
            exit(1);
        }

        /* Output the term and cumulative sum */
        std::cout << "Term " << term_number << ": " << term
                << ", Cumulative Sum: " << sum << std::endl;
    }

    /* Output the final sum */
    std::cout << "Final Sum: " << sum << std::endl;

    /* Return 0 to indicate successful completion */
    return 0;
}