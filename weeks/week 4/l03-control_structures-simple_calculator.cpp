/**
 * @file l03-control_structures-simple_calculator.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Uses control structures to create a simple calculator
 * @version 0.1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <iostream>
#include <limits>


/**
 * @brief Input a number from the user, avoiding a banned number and checking for errors.
 * 
 * @param input_message 
 * @param number 
 * @param banned_number 
 */
void input_number(const std::string &input_message, double &number, const double &banned_number){
    const double float_error_resolution = 10e-12;
    
    while (true){
        std::cout << input_message;
        std::cin >> number;

        if (std::cin.fail()){
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (std::fabs(number - banned_number) < float_error_resolution){
            std::cerr << "Error: x cannot be " << banned_number << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
}
/* ANSWER (Task 3.0): Create a function to input a number, avoiding a banned number. */


int main(){
    while (true) {
        std::cout << "List of functions:" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. csch(x)" << std::endl;

        int choice;
        std::cout << "Enter the number of the function you would like to use: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "---" << std::endl;

        double x, y;
        switch (choice){
            case 0:
                std::cout << "Exiting..." << std::endl;
                return 0;
            case 1:
                input_number("Enter x: ", x, 0.0);
                std::cout << "csch(" << x << ") = ";
                y = 1.0 / std::sinh(x);
                break;
            default:
                std::cerr << "Invalid choice. Please enter a valid number." << std::endl;
                y = NAN;
                break;
        }

        if (!std::isnan(y)){
            std::cout << y << std::endl;
        }
    }

    return 0;
}