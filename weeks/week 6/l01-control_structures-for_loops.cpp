/**
 * @file l01-control_structures-for_loops.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Explore the for loop in C++
 * @version 0.1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

void even_odd_printer(int count_limit) {
    for (int count = 0; count < count_limit; count++) {
        if (count % 2 == 0) {
            std::cout << count << " is even" << std::endl;
        } else {
            std::cout << count << " is odd" << std::endl;
        }
    }
}

void geometric_progression(int count_limit) {
    for (int count = 0; count < count_limit; count++) {
        std::cout << "2^" << count << " = " << (1 << count) << std::endl;
    }
}

void sum_of_cubes(int count_limit) {
    int sum = 0;
    for (int count = 0; count < count_limit; count++) {
        sum += count * count * count;
    }
    std::cout << "The sum of the cubes of the first " << count_limit << " numbers is " << sum << std::endl;
}

void fibonacci(int count_limit) {
    int number_1 = 0;
    int number_2 = 1;
    for (int count = 0; count < count_limit; count++) {
        std::cout << number_1 << std::endl;

        // Swap the numbers to get the next number in the sequence
        int temp = number_1;
        number_1 = number_2;
        number_2 += temp;
    }
}

int main() {
    // even_odd_printer(10);
    // geometric_progression(10);
    // sum_of_cubes(10);
    fibonacci(10);
    return 0;
}