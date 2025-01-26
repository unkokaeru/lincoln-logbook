/**
 * @file l01-basic_use-data_size.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Experimenting with the size of data types in C++
 * @version 0.1.0
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <climits>
#include <iostream>


/**
 * @brief Experimenting with the size of data types in C++.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
    unsigned short int unsigned_small_number = 65535;

    /* Experiment with the size of the data type */
    std::cout << "Original number: " << unsigned_small_number << std::endl;
    unsigned_small_number++;
    std::cout << "Incremented number (1x): " << unsigned_small_number << std::endl;
    unsigned_small_number++;
    std::cout << "Incremented number (2x): " << unsigned_small_number << std::endl;
    /* ANSWER (Task 1.1): After reaching the max value of the data type, the number goes to zero. */

    std::cout << "---" << std::endl;

    /* Trying with a signed short int */
    short int signed_small_number = 32767;
    std::cout << "Original number: " << signed_small_number << std::endl;
    signed_small_number++;
    std::cout << "Incremented number (1x): " << signed_small_number << std::endl;
    signed_small_number++;
    std::cout << "Incremented number (2x): " << signed_small_number << std::endl;
    /**
     * ANSWER (Task 1.2):
     * After reaching the max value of the data type, the number goes to -32768. I think this is
     * because it wraps around to the minimum value of the data type when it reaches the maximum.
     * This is called an overflow.
     */

    std::cout << "---" << std::endl;

    /* Trying with a negative number */
    signed_small_number = -32768;
    std::cout << "Original number: " << signed_small_number << std::endl;
    signed_small_number--;
    std::cout << "Decremented number (1x): " << signed_small_number << std::endl;
    signed_small_number--;
    std::cout << "Decremented number (2x): " << signed_small_number << std::endl;
    /* ANSWER (Task 1.3): Similar to overflow, it loops around as an underflow. */

    std::cout << "---" << std::endl;

    /* Display the size of the data types */
    std::cout << "Size of an unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of an int: " << sizeof(unsigned_small_number) << " bytes" << std::endl;
    std::cout << "Size of a short int: " << sizeof(signed_small_number) << " bytes" << std::endl;
    std::cout << "Size of a long int: " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "Size of a long long int: " << sizeof(long long int) << " bytes" << std::endl;
    std::cout << "Size of a double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of a long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of a float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of a char: " << sizeof(char) << " bytes" << std::endl;
    /**
     * ANSWER (Task 1.4):
     * The size of the data types follow a pattern, where the size of the data type is doubled
     * when using a long data type (e.g. long int, long long int, long double). The size of each
     * data type logically increases as the data type can store larger numbers.
     */

    std::cout << "---" << std::endl;

    /* Display the maximum and minimum values of the data types */
    std::cout << "Maximum value of a short int: " << SHRT_MAX << std::endl;
    std::cout << "Minimum value of a short int: " << SHRT_MIN << std::endl;
    std::cout << "Maximum value of an unsigned short int: " << USHRT_MAX << std::endl;
    std::cout << "Minimum value of an unsigned short int: " << 0 << std::endl;
    std::cout << "Maximum value of an int: " << INT_MAX << std::endl;
    std::cout << "Minimum value of an int: " << INT_MIN << std::endl;
    std::cout << "Maximum value of an unsigned int: " << UINT_MAX << std::endl;
    std::cout << "Minimum value of an unsigned int: " << 0 << std::endl;
    std::cout << "Maximum value of a long int: " << LONG_MAX << std::endl;
    std::cout << "Minimum value of a long int: " << LONG_MIN << std::endl;
    /**
     * ANSWER (Task 1.5):
     * The maximum and minimum values of the data types are defined in the limits.h header file.
     * The maximum value of a signed data type is always one less than the maximum value of the
     * unsigned data type of the same size. The minimum value of a signed data type is always the
     * negative of the maximum value minus one.
     */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}