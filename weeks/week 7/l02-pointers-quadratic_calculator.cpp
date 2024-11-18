/**
 * @file l02-pointers-quadratic_calculator.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Quadratic calculator using pointers in C++
 * @version 0.1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cmath>

bool solve_quadratic(float a, float b, float c, float* x1, float* x2) {
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        *x1 = -b / (2 * a); // Real part
        *x2 = sqrt(-discriminant) / (2 * a); // Imaginary part
        return false; // No real roots
    }

    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);
    return true; // Real roots
}

int main() {
    float a, b, c;
    std::cout << "Enter a, b, and c: ";
    std::cin >> a >> b >> c;

    std::cout << "Solving " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

    float x1, x2;
    if (solve_quadratic(a, b, c, &x1, &x2)) {
        if (x1 == x2) {
            std::cout << "Root of the auxillary equation: " << x1 << std::endl;
            std::cout << "Solution of the homogenous equation: y = C1 * e^(" << x1
                        << "x) + C2 * x * e^(" << x1 << "x)" << std::endl;
        } else {
            std::cout << "Roots of the auxillary equation: " << x1 << ", " << x2 << std::endl;
            std::cout << "Solution of the homogenous equation: y = C1 * e^(" << x1
                        << "x) + C2 * e^(" << x2 << "x)" << std::endl;
        }
    } else {
        std::cout << "Roots of the auxillary equation: " << x1 << " + " << x2 << "i, " << x1
                    << " - " << x2 << "i" << std::endl;
        std::cout << "Solution of the homogenous equation: y = C1 * e^(" << x1
                    << "x) * cos(" << x2 << "x) + C2 * e^(" << x1 << "x) * sin(" << x2 << "x)" << std::endl;
    }

    return 0;
}