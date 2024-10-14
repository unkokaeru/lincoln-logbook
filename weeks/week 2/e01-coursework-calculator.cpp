/**
 * @file e01-coursework-calculator.cpp
 * @author William Fayers (william@fayers.com)
 * @brief A simple calculator program for pre-defined mathematical operations.
 * @version 0.1.0
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <functional>
#include <map>


/**
 * @brief Fetch a number from the user with error checking.
 * 
 * @param number 
 * @param input_message 
 */
void input_number(float& number, const std::string& input_message) {
    while (true) {
        /* Ask the user for a number */
        std::cout << input_message;
        std::cin >> number;

        /* Check if the input is valid */
        if (std::cin.fail() || number == 0) {
            /* Display an error message */
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;

            if (number == 0) {
                std::cerr << "Zero is not a valid input, because of division by zero." << std::endl;
            }

            /* Clear the error flag and ignore the rest of the input */
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            /* Discard any extra characters in the input buffer */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            /* Exit the loop if the input is valid */
            return;
        }
    }
}


/**
 * @brief Add two numbers and output the result.
 */
void perform_addition() {
    /* Input the two numbers */
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    /* Calculate the sum */
    std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl;
}


/**
 * @brief Subtract two numbers and output the result.
 */
void perform_subtraction() {
    /* Input the two numbers */
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    /* Calculate the difference */
    std::cout << number1 << " - " << number2 << " = " << (number1 - number2) << std::endl;
}


/**
 * @brief Multiply two numbers and output the result.
 */
void perform_multiplication() {
    /* Input the two numbers */
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    /* Calculate the product */
    std::cout << number1 << " * " << number2 << " = " << (number1 * number2) << std::endl;
}


/**
 * @brief Calculate the modulo of two numbers and output the result.
 */
void perform_modulo() {
    /* Input the two numbers */
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    /* Calculate the modulo */
    std::cout << number1 << " mod " << number2 << " = "
                << (number1 - (static_cast<int>(number1 / number2) * number2)) << std::endl;
}


/**
 * @brief Calculate the area and circumference of a circle.
 */
void perform_circle_calculations() {
    /* Input the radius of the circle */
    float radius;
    input_number(radius, "Enter the radius of the circle: ");
    /* ANSWER (Task 1.1): Input the radius of the circle. */

    /* Calculate the area and circumference of the circle */
    float area = M_PI * radius * radius;
    float circumference = 2 * M_PI * radius;
    std::cout << "Area of a circle with radius " << radius << " = " << area << std::endl;
    std::cout << "Circumference of a circle with radius " << radius << " = " << circumference
                << std::endl;
    /* ANSWER (Task 1.1): Calculate the area and circumference of the circle. */
}


/**
 * @brief Calculate the simple interest.
 */
void perform_simple_interest() {
    /* Input the principal amount, rate of interest, and time period */
    float principal, rate, time;
    input_number(principal, "Enter the principal amount: ");
    input_number(rate, "Enter the rate of interest (%): ");
    input_number(time, "Enter the time period (years): ");
    /* ANSWER (Task 1.2): Input the principal amount, rate of interest, and time period. */

    /* Calculate the simple interest */
    float simple_interest = (principal * rate * time) / 100;
    std::cout << "Simple Interest on a principal amount of " << principal << " at a rate of "
                << rate << "% for " << time << " years = " << simple_interest << std::endl;
    /* ANSWER (Task 1.2): Calculate the simple interest. */
}


/**
 * @brief Main function to run the program.
 *
 * @details This function displays a menu of operations to the user and performs the selected
 * operation. The program continues to run until the user chooses to exit.
 * 
 * @return int 
 */
int main() {
    /* Map the operation index to the corresponding function */
    std::map<int, std::pair<std::function<void()>, std::string>> operations = {
        {1, {perform_addition, "Addition"}},
        {2, {perform_subtraction, "Subtraction"}},
        {3, {perform_multiplication, "Multiplication"}},
        {4, {perform_modulo, "Modulo"}},
        {5, {perform_circle_calculations, "Area and Circumference of a Circle"}},
        {6, {perform_simple_interest, "Simple Interest"}}
    };

    /* Run the program until the user chooses to exit */
    while (true) {
        /* Display the menu of operations */
        std::cout << "Select an operation to perform:" << std::endl;
        for (const auto& operation : operations) {
            std::cout << operation.first << ". " << operation.second.second << std::endl;
        }
        std::cout << operations.size() + 1 << ". Exit" << std::endl;

        /* Input the operation */
        float operation_input;
        input_number(operation_input, "Enter the operation number: ");
        int operation = static_cast<int>(operation_input);

        /* Exit the program if the user chooses to exit */
        if (operation == static_cast<int>(operations.size() + 1)) {
            break;
        }

        /* Check if the operation is valid */
        if (operations.find(operation) != operations.end()) {
            /* Perform the selected operation */
            operations[operation].first();
        } else {
            /* Display an error message for an invalid operation */
            std::cerr << "Invalid operation. Please select a valid operation." << std::endl;
        }
    }

    /* Return 0 to indicate the program ran successfully */
    return 0;
}