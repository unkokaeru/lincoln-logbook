/*
* PROGRAM: l02-basic_use-special_characters.cpp
* DESCRIPTION: Use of special characters
* AUTHOR: William Fayers
* DATE: 2024-09-30
*/

#include <iostream>

using namespace std;


int main()
{
    /* Starting string (for comparison) */
    cout << "Starting string: Welcome to C++ Programming\n" << "---\n";

    /* Without newline */
    cout << "Without newline: Welcome to C++ Programming" << "---\n";
    /**
     * ANSWER (Task 1.1):
     * Removing `/n` causes the output to not start a new line after the string.
     */

    /* With bell character */
    cout << "With bell character: Welcome to C++ Programming\a" << "---\n";
    /* ANSWER (Task 1.3): The bell character `\a` makes a sound in some environments. */

    /* With backspace character */
    cout << "With backspace character: Welcome to C++ Programming\b" << "---\n";
    /* ANSWER (Task 1.3): The backspace character \b removes the last character. */

    /* With formfeed character */
    cout << "With formfeed character: Welcome to C++ Programming\f" << "---\n";
    /**
     * ANSWER (Task 1.3):
     * The formfeed character \f displays a `♀` character, representing a page break.
     */

    /* With return character */
    cout << "With return character: Welcome to C++ Programming\r" << "---\n";
    /* ANSWER (Task 1.3): The return character \r returns to the start of the line. */

    /* With tab character */
    cout << "With tab character: Welcome to C++ Programming\t" << "---\n";
    /* ANSWER (Task 1.3): The tab character \t adds a tab space. */

    /* Escaped characters demonstration */
    cout << "Escaped characters: Is the symbol \\n called \' Newline \' \? \n";
    /* ANSWER (Task 1.4): Removing the backslash before the single quote causes a syntax error. */

    /* Line terminator */
    cout << "A rose by any other name would smell as sweet";
    cout << endl;
    /* ANSWER (Task 2.1): The line terminator `endl` starts a new line. */

    /* Line terminator insertion */
    cout << "A rose by any other name would smell as sweet" << endl;
    /**
     * ANSWER (Task 2.2):
     * There's no change in output if `endl` is inserted at the end of the string.
     */

    return 0;
}