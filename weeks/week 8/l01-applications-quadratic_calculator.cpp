/**
 * @file l01-applications-quadratic_calculator.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Applying C++ to solve quadratic equations
 * @version 0.1.0
 * @date 2024-12-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <limits>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

/**
 * @brief Class representing a quadratic equation.
 *
 */
class QuadraticEquation
{
private:
    long double a;
    long double b;
    long double c;

public:
    // Constructor
    QuadraticEquation(long double coeff_a, long double coeff_b, long double coeff_c)
    {
        if (std::isnan(coeff_a) || std::isnan(coeff_b) || std::isnan(coeff_c))
        {
            throw std::invalid_argument("Coefficients must be valid numbers.");
        }
        a = coeff_a;
        b = coeff_b;
        c = coeff_c;
    }

    /**
     * @brief Solves the equation, which could be quadratic or linear.
     *
     * @return std::pair<std::complex<long double>, std::complex<long double>> Pair of roots.
     * If linear, returns one root and NaN for the second.
     * If infinitely many solutions, both roots are represented as NaN.
     */
    std::pair<std::complex<long double>, std::complex<long double>> solve() const
    {
        if (a != 0.0L)
        {
            // Quadratic case
            long double discriminant = b * b - 4.0L * a * c;

            // Check for potential overflow/underflow
            if (std::isinf(discriminant))
            {
                throw std::overflow_error("Discriminant is too large, causing overflow.");
            }

            // Using complex numbers to handle real and complex roots
            std::complex<long double> sqrt_discriminant = std::sqrt(std::complex<long double>(discriminant, 0));

            // Calculate two roots
            std::complex<long double> two_a = 2.0L * a;
            std::complex<long double> root1 = (-b + sqrt_discriminant) / two_a;
            std::complex<long double> root2 = (-b - sqrt_discriminant) / two_a;

            return std::make_pair(root1, root2);
        }
        else if (b != 0.0L)
        {
            // Linear case: bx + c = 0 => x = -c / b
            std::complex<long double> root = -c / b;
            return std::make_pair(root, std::complex<long double>(NAN, NAN));
        }
        else
        {
            if (c == 0.0L)
            {
                // Infinite solutions: 0 = 0
                return std::make_pair(std::complex<long double>(INFINITY, 0.0L),
                                      std::complex<long double>(INFINITY, 0.0L));
            }
            else
            {
                // No solution: c = 0 where c != 0
                return std::make_pair(std::complex<long double>(NAN, NAN),
                                      std::complex<long double>(NAN, NAN));
            }
        }
    }

    /**
     * @brief Formats the equation as a string.
     *
     * @return std::string Representation of the equation.
     */
    std::string to_string() const
    {
        std::ostringstream equation;
        bool first = true;

        // Format a*x^2
        if (a != 0.0L)
        {
            equation << a << "x^2 ";
            first = false;
        }

        // Format b*x
        if (b != 0.0L)
        {
            if (!first && b > 0)
            {
                equation << "+ ";
            }
            else if (b < 0)
            {
                equation << "- ";
            }
            equation << std::abs(b) << "x ";
            first = false;
        }

        // Format c
        if (c != 0.0L || first)
        { // Display '0' if all coefficients are zero
            if (!first && c > 0)
            {
                equation << "+ ";
            }
            else if (c < 0)
            {
                equation << "- ";
            }
            equation << std::abs(c) << " ";
        }

        equation << "= 0";
        return equation.str();
    }
};

/**
 * @brief Safely reads a number from the user with validation and limited attempts.
 *
 * @param prompt Prompt to display to the user.
 * @param number Reference to store the validated number.
 * @param max_attempts Maximum number of invalid attempts allowed (default is 5).
 * @return bool True if a valid number was read, False otherwise.
 */
bool read_number(const std::string &prompt, long double &number, int max_attempts = 5)
{
    int attempts = 0;
    while (attempts < max_attempts)
    {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> number;

        // Check if entire input was consumed and was a valid number
        if (!ss.fail() && ss.eof())
        {
            return true;
        }
        else
        {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            attempts++;
        }
    }
    std::cerr << "Maximum invalid attempts reached. Exiting input process." << std::endl;
    return false;
}

/**
 * @brief Formats a complex number as a string in the form "a + bi".
 *
 * @param num The complex number to format.
 * @return std::string The formatted string.
 */
std::string format_complex(const std::complex<long double> &num)
{
    if (std::isnan(num.real()) && std::isnan(num.imag()))
    {
        return "No Solution.";
    }
    if (std::isinf(num.real()) && std::isinf(num.imag()))
    {
        return "Infinite Solutions.";
    }

    std::ostringstream oss;
    oss << num.real();

    if (num.imag() >= 0.0L)
    {
        oss << " + " << num.imag() << "i";
    }
    else
    {
        oss << " - " << std::abs(num.imag()) << "i";
    }

    return oss.str();
}

/**
 * @brief Main function to run the Quadratic Solver.
 *
 * @return int
 */
int main()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "          Quadratic Solver           " << std::endl;
    std::cout << "=====================================" << std::endl;

    std::vector<std::string> equation_log; // To keep track of all solved equations
    char continue_calculating = 'y';

    while (std::tolower(continue_calculating) == 'y')
    {
        try
        {
            long double a, b, c;

            // Read coefficients with validation
            if (!read_number("Enter coefficient a (a can be 0 for linear equations): ", a))
            {
                throw std::runtime_error("Failed to read coefficient 'a'.");
            }
            if (!read_number("Enter coefficient b: ", b))
            {
                throw std::runtime_error("Failed to read coefficient 'b'.");
            }
            if (!read_number("Enter coefficient c: ", c))
            {
                throw std::runtime_error("Failed to read coefficient 'c'.");
            }

            // Create a QuadraticEquation object
            QuadraticEquation equation(a, b, c);

            // Display the equation
            std::cout << "\nSolving the equation: " << equation.to_string() << std::endl;

            // Solve the equation
            auto roots = equation.solve();

            // Prepare solution string
            std::string solution;
            if (a != 0.0L)
            {
                // Quadratic case
                long double discriminant = b * b - 4.0L * a * c;
                if (discriminant > 0.0L)
                {
                    // Two distinct real roots
                    solution = "x1 = " + format_complex(roots.first) + ", x2 = " + format_complex(roots.second);
                }
                else if (discriminant == 0.0L)
                {
                    // One repeated real root
                    solution = "x = " + format_complex(roots.first);
                }
                else
                {
                    // Complex roots
                    solution = "x1 = " + format_complex(roots.first) + ", x2 = " + format_complex(roots.second);
                }
            }
            else
            {
                // Linear or no/infinite solutions
                if (b != 0.0L)
                {
                    solution = "x = " + format_complex(roots.first);
                }
                else
                {
                    if (c == 0.0L)
                    {
                        solution = "Infinite solutions.";
                    }
                    else
                    {
                        solution = "No solution.";
                    }
                }
            }

            // Display the roots
            std::cout << "Solution: " << solution << "\n"
                      << std::endl;

            // Log the equation and solution
            equation_log.push_back("Equation: " + equation.to_string() + " | Solution: " + solution);
        }
        catch (const std::exception &ex)
        {
            std::cerr << "An error occurred: " << ex.what() << "\n"
                      << std::endl;
        }

        // Continuation prompt with validation
        while (true)
        {
            std::cout << "Would you like to solve another equation? (y/n): ";
            std::cin >> continue_calculating;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

            continue_calculating = std::tolower(continue_calculating);
            if (continue_calculating == 'y' || continue_calculating == 'n')
            {
                break;
            }
            else
            {
                std::cerr << "Invalid response. Please enter 'y' for yes or 'n' for no." << std::endl;
            }
        }

        std::cout << std::endl;
    }

    // Optionally, display the log of all equations solved
    if (!equation_log.empty())
    {
        std::cout << "=====================================" << std::endl;
        std::cout << "          Solved Equations           " << std::endl;
        std::cout << "=====================================" << std::endl;
        for (size_t i = 0; i < equation_log.size(); ++i)
        {
            std::cout << i + 1 << ". " << equation_log[i] << std::endl;
        }
        std::cout << "=====================================" << std::endl;
    }

    std::cout << "Thank you for using the Quadratic Solver." << std::endl;
    return 0;
}