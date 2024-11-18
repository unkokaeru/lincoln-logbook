/**
 * @file l01-pointers-introduction.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Introduction to pointers in C++
 * @version 0.1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

void pointer_example1() {
    // Declare two integers
    int number_1 = 8, number_2 = 16;

    // Declare two pointers to integers
    int* p_number_1 = &number_1;
    int* p_number_2 = &number_2;

    // Output addresses of the two integers
    std::cout << "Address of number_1: " << &number_1 << std::endl;
    std::cout << "Address of number_2: " << &number_2 << std::endl;

    // Output stored addresses of the two pointers
    std::cout << "Address stored in p_number_1: " << p_number_1 << std::endl;
    std::cout << "Address stored in p_number_2: " << p_number_2 << std::endl;

    // Output values stored at the addresses stored in the pointers
    std::cout << "Value stored at address stored in p_number_1: " << *p_number_1 << std::endl;
    std::cout << "Value stored at address stored in p_number_2: " << *p_number_2 << std::endl;
}

void write_output(int* value) {
    std::cout << "Value stored at address: " << *value << std::endl;
}

void compute_triple(int* value) {
    *value *= 3;
}

void pointer_example2() {
    int number = 5;
    int* p_number = &number;
    
    write_output(p_number);
    *p_number += 15;
    write_output(p_number);
    compute_triple(p_number);
    write_output(p_number);
}

int main() {
    // pointer_example1();
    pointer_example2();

    return 0;
}