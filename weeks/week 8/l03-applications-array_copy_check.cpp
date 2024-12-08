/**
 * @file l03-applications-array_copy_check.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Duplicate an array and check if the copy is correct.
 * @version 0.1.0
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

/**
 * @brief Function to duplicate an array using std::copy.
 *
 * @param arr Array to duplicate.
 * @return std::vector<int> Duplicated array.
 */
std::vector<int> duplicate_array(const std::vector<int> &arr)
{
    std::vector<int> copy(arr.size());
    std::copy(arr.begin(), arr.end(), copy.begin());
    return copy;
}

/**
 * @brief Function to check if two arrays are equal.
 *
 * @param arr1 First array.
 * @param arr2 Second array.
 * @return bool True if arrays are equal, False otherwise.
 */
bool arrays_equal(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    return arr1 == arr2;
}

/**
 * @brief Main function to duplicate an array and check if the copy is correct.
 *
 * @return int
 */
int main()
{
    std::vector<int> original_array = {1, 2, 3, 4, 5};
    std::vector<int> copied_array = duplicate_array(original_array);

    // Display the original and copied arrays
    std::cout << "Original Array: ";
    std::copy(original_array.begin(), original_array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::cout << "Copied Array: ";
    std::copy(copied_array.begin(), copied_array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // Check if the arrays are equal
    if (arrays_equal(original_array, copied_array))
    {
        std::cout << "The copied array is correct." << std::endl;
    }
    else
    {
        std::cout << "The copied array is incorrect." << std::endl;
    }

    return 0;
}