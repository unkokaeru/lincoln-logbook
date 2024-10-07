/*
* PROGRAM: l03-basic_use-pascals_triangle.cpp
* DESCRIPTION: Pracisting cout and special characters
* AUTHOR: William Fayers
* DATE: 2024-09-30
*/

#include <iostream>

using namespace std;


int main()
{
    /* Print Pascal's Triangle up to n=5 with cout and the tab character to center the numbers */
    cout << "n\t\t\t\t   Pascal's Triangle up to n=5\n";
    cout << "0\t\t\t\t\t\t1\n";
    cout << "1\t\t\t\t\t1\t\t1\n";
    cout << "2\t\t\t\t1\t\t2\t\t1\n";
    cout << "3\t\t\t1\t\t3\t\t3\t\t1\n";
    cout << "4\t\t1\t\t4\t\t6\t\t4\t\t1\n";
    cout << "5\t1\t\t5\t\t10\t\t10\t\t5\t\t1\n";

    cout << "\t\t\t\t      Made by William Fayers\n";
    /**
     * ANSWER (Task 1.1):
     * I used the tab character, `\t` to center the numbers in the Pascal's Triangle, along with
     * `cout` to print the numbers. This ended up with a fairly nice looking Pascal's Triangle:
     * ```
     * n                                  Pascal's Triangle up to n=5
     * 0                                               1
     * 1                                       1               1
     * 2                               1               2               1
     * 3                       1               3               3               1
     * 4               1               4               6               4               1
     * 5       1               5               10              10              5               1
     *                                       Made by William Fayers
     * ```
     */

    return 0;
}