#include <cmath>
#include <iostream>
#include <limits>

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

double atanh(double x) {
    if (x < -1 || x > 1) {
        std::cerr << "\nError: The input value must be between -1 and 1." << std::endl;
        return NAN;
    }
    return 0.5 * log((1 + x) / (1 - x));
}

double acosh(double x) {
    if (x < 1) {
        std::cerr << "\nError: The input value must be greater than or equal to 1." << std::endl;
        return NAN;
    }
    return log(x + sqrt(x * x - 1));
}

int main() {
    while (true) {
        double choice;
        std::cout << "Select an operation:\n1. Inverse Hyperbolic Tangent\n"
                    << "2. Inverse Hyperbolic Cosine\n0. Exit\n";
        input_number(choice, "Enter your choice: ");

        if (choice == 0) {
            break;
        }

        double x;
        switch (static_cast<int>(choice)) {
            case 1:
                input_number(x, "Enter a value for x (between -1 and 1): ");
                std::cout << "The inverse hyperbolic tangent of " << x << " is " << atanh(x)
                            << std::endl;
                break;
            case 2:
                input_number(x, "Enter a value for x (greater than or equal to 1): ");
                std::cout << "The inverse hyperbolic cosine of " << x << " is " << acosh(x)
                            << std::endl;
                break;
            default:
                std::cerr << "Error: Invalid operation number." << std::endl;
                break;
        }
    }

    return 0;
}

