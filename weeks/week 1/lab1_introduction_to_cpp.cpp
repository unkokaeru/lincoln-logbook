#include <iostream> /* For std::cout, std::cin */
#include <cmath> /* For std::ceil, std::pow */
#include <stdexcept> /* For std::invalid_argument */
#include <iomanip> /* For std::setw */

/**
 * @file lab1_introduction_to_cpp.cpp
 * @brief Contains the first lab session of the scientific computing module.
 * @details This lab is designed to explain the basics of C++ programming,
 * hence excessive comments are provided to explain the code.
 */

const int MAX_ROWS = 29;
const std::string ERROR_MESSAGE = "Error: rows must be between 0 and " + std::to_string(MAX_ROWS) + "!";

/**
 * @brief Outputs Pascal's triangle to the console.
 * 
 * @details Calculates Pascal's triangle iteratively using the formula:
 * \f[
 * C(n, k+1) = C(n, k) \times \frac{n - k}{k + 1}
 * \f]
 * where \f$C(n, k)\f$ is the coefficient at row \f$n\f$ and column \f$k\f$.
 * Ensures the triangle is centered in the console by calculating the maximum
 * width of the triangle and the maximum width of the coefficients, using the
 * power of 2 to estimate the width of the largest coefficient.
 * 
 * @note Designed to test the use of output streams, loops, error handling, libraries,
 * and functions in C++.
 * 
 * @param rows The number of rows to output in Pascal's triangle. Must be non-negative
 * and less than or equal to MAX_ROWS.
 *
 * @throw std::invalid_argument Throws an error if rows is less than 0 or greater than MAX_ROWS.
 *
 * @warning Since the coefficients in Pascal's triangle can grow very large, this
 * function may not work as expected for rows greater than 29.
 *
 * @example
 * \code{.cpp}
 * output_pascals_triangle(4);
 * \endcode
 *
 * Expected Output:
 * \code{.plaintext}
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 * \endcode
 */
void output_pascals_triangle(int rows) {
    /* Throw an error if rows is less than 0 or greater than MAX_ROWS. */
    if (rows < 0 || rows > MAX_ROWS) {
        throw std::invalid_argument(ERROR_MESSAGE);
    }

    /* Estimate the width of the largest coefficient using the power of 2 */
    int estimated_max_coefficient = std::ceil(std::pow(2, rows));
    int max_coefficient_width = std::to_string(estimated_max_coefficient).length() + 1;

    /* Calculate the maximum width of the triangle. */
    int max_triangle_width = max_coefficient_width * (rows + 1);

    /* Loop through each row in Pascal's triangle. */
    for (int row = 0; row <= rows; row++) {
        /* Set the first coefficient to 1 */
        int coefficient = 1;

        /* Add leading spaces to center the triangle. */
        int leading_spaces = (max_triangle_width - (max_coefficient_width * (row + 1))) / 2;
        std::cout << std::string(leading_spaces, ' ');

        /* Loop through each column in the current row. */
        for (int column = 0; column <= row; column++) {
            /* Output the current coefficient. */
            std::cout << std::setw(max_coefficient_width) << coefficient;

            /* Calculate the next coefficient. */
            coefficient = coefficient * (row - column) / (column + 1);
        }

        /* Move to the next row. */
        std::cout << std::endl;
    }
}

/**
 * @brief Main function to run the program.
 *
 * @details This function prompts the user for the number of rows to output
 * in Pascal's triangle and calls the output_pascals_triangle function.
 *
 * @return Returns 0 to indicate the program has run successfully.
 */
int main() {
    /* Prompt the user for the number of rows to output. */
    std::cout << "Please enter the number of rows you would like to output (0 to " << MAX_ROWS << "): ";
    int rows;
    std::cin >> rows;

    /* Output Pascal's triangle to the console. */
    try {
        output_pascals_triangle(rows);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    /* Output a goodbye message to the user. */
    std::cout << "Made by William Fayers :)" << std::endl;

    /* Return 0 to indicate the function has run successfully. */
    return 0;
}