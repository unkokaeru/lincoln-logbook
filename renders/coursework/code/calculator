#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <string>


void input_number(float& number, const std::string& input_message) {
    while (true) {
        std::cout << input_message;
        std::cin >> number;

        if (std::cin.fail() || number == 0) {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;

            if (number == 0) {
                std::cerr << "Zero is not a valid input, because of division by zero." << std::endl;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return;
        }
    }
}


void perform_addition() {
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl;
}


void perform_subtraction() {
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    std::cout << number1 << " - " << number2 << " = " << (number1 - number2) << std::endl;
}


void perform_multiplication() {
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    std::cout << number1 << " * " << number2 << " = " << (number1 * number2) << std::endl;
}


void perform_modulo() {
    float number1, number2;
    input_number(number1, "Enter the first number: ");
    input_number(number2, "Enter the second number: ");

    std::cout << number1 << " mod " << number2 << " = "
                << (number1 - (static_cast<int>(number1 / number2) * number2)) << std::endl;
}


void perform_circle_calculations() {
    float radius;
    input_number(radius, "Enter the radius of the circle: ");

    float area = M_PI * radius * radius;
    float circumference = 2 * M_PI * radius;
    std::cout << "Area of a circle with radius " << radius << " = " << area << std::endl;
    std::cout << "Circumference of a circle with radius " << radius << " = " << circumference
                << std::endl;
}


void perform_simple_interest() {
    float principal, rate, time;
    input_number(principal, "Enter the principal amount: ");
    input_number(rate, "Enter the rate of interest (%): ");
    input_number(time, "Enter the time period (years): ");

    float simple_interest = (principal * rate * time) / 100;
    std::cout << "Simple Interest on a principal amount of " << principal << " at a rate of "
                << rate << "% for " << time << " years = " << simple_interest << std::endl;
}


int main() {
    std::map<int, std::pair<std::function<void()>, std::string>> operations = {
        {1, {perform_addition, "Addition"}},
        {2, {perform_subtraction, "Subtraction"}},
        {3, {perform_multiplication, "Multiplication"}},
        {4, {perform_modulo, "Modulo"}},
        {5, {perform_circle_calculations, "Area and Circumference of a Circle"}},
        {6, {perform_simple_interest, "Simple Interest"}}
    };

    while (true) {
        std::cout << "Select an operation to perform:" << std::endl;
        for (const auto& operation : operations) {
            std::cout << operation.first << ". " << operation.second.second << std::endl;
        }
        std::cout << operations.size() + 1 << ". Exit" << std::endl;

        float operation_input;
        input_number(operation_input, "Enter the operation number: ");
        int operation = static_cast<int>(operation_input);

        if (operation == static_cast<int>(operations.size() + 1)) {
            break;
        }

        if (operations.find(operation) != operations.end()) {
            operations[operation].first();
        } else {
            std::cerr << "Invalid operation. Please select a valid operation." << std::endl;
        }
    }

    return 0;
}

