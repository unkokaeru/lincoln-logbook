/**
 * @file e01-coursework-quadratic_calculator.cpp
 * @author William Fayers (william@fayers.com)
 * @brief A simple calculator program for quadratic equations.
 * @version 0.1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cmath>
#include <iostream>
#include <limits>
#include <tuple>
/* ANSWER (Task 5.0): Include the necessary libraries. */


/**
 * @brief Fetch a number from the user with error checking.
 * 
 * @param number 
 * @param input_message 
 */
void input_number(double& number, const std::string& input_message) {
    while (true) {
        std::cout << input_message;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
}
/* ANSWER (Task 5.0): Start with a verbose number input function to re-use. */


/**
 * @brief Solve a quadratic equation.
 * 
 * @param a The coefficient of x^2.
 * @param b The coefficient of x.
 * @param c The constant term.
 * @return std::tuple<double, double> The solutions to the quadratic equation.
 */
std::tuple<double, double> solve_quadratic(const double a, const double b, const double c) {
    double discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        return std::make_tuple(NAN, NAN);
    }

    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);

    return std::make_tuple(x1, x2);
}
/* ANSWER (Task 5.0): Calculate the quadratic's solution. */


/**
 * @brief The main function to run the program.
 * 
 * @return int 
 */
int main() {
    while (true) {
        double a, b, c;
        input_number(a, "Enter the coefficient of x^2: ");
        input_number(b, "Enter the coefficient of x: ");
        input_number(c, "Enter the constant term: ");

        std::tuple<double, double> x = solve_quadratic(a, b, c);

        std::cout << "The quadratic equation " << a << "x^2 + " << b << "x + " << c << " = 0 has ";

        if (std::isnan(std::get<0>(x))) {
            std::cout << "no real solutions." << std::endl;
        } else if (std::get<0>(x) == std::get<1>(x)) {
            std::cout << "one solution: x = " << std::get<0>(x)
                << std::endl;
        } else {
            std::cout << "two solutions: x = " << std::get<0>(x) 
                << " and x = " << std::get<1>(x) << std::endl;
        }

        char response;
        std::cout << "Would you like to solve another quadratic equation? (y/n): ";
        std::cin >> response;

        if (response != 'y') {
            break;
        }
    }

    return 0;
}
/* ANSWER (Task 5.0): Implement the main program loop. */