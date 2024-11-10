---
title: "**📖 MTH2008** Scientific Computing Logbook"
author: "School of Engineering and Physical Sciences, University of Lincoln"
date: "Semester A, 2024"
geometry: margin=1in
---

*"I confirm that this logbook is entirely my own work and that all references and quotations, from both primary and secondary sources, have been fully identified and properly acknowledged."* - William Fayers (27378661).

---

## 📚 Table of Contents

| **Section**                                                                 | **Page** |
|-----------------------------------------------------------------------------|----------|
| **Disclaimer**                                                              | 1        | 
| [**Week 1** – 2024-09-30 to 2024-10-07 ](#week-1-2024-09-30-to-2024-10-07) | 2        | 
| &nbsp;&nbsp;&nbsp;&nbsp;1.1 [Basic Use: Using Cout](#basic-use-using-cout) | 2        | 
| &nbsp;&nbsp;&nbsp;&nbsp;1.2 [Basic Use: Special Characters](#basic-use-special-characters) | 3        | 
| &nbsp;&nbsp;&nbsp;&nbsp;1.3 [Basic Use: Pascals Triangle](#basic-use-pascals-triangle) | 4        | 
| &nbsp;&nbsp;&nbsp;&nbsp;*1.4 [Pascal Triangle: Extended Project](#pascal-triangle-extended-project)* | 5        | 
| [**Week 2** – 2024-10-07 to 2024-10-14 ](#week-2-2024-10-07-to-2024-10-14) | 6        | 
| &nbsp;&nbsp;&nbsp;&nbsp;2.1 [Basic Use: Variables And Data Types](#basic-use-variables-and-data-types) | 6        | 
| &nbsp;&nbsp;&nbsp;&nbsp;2.2 [Basic Use: Input And Math](#basic-use-input-and-math) | 7        | 
| &nbsp;&nbsp;&nbsp;&nbsp;*2.3 [Coursework: Calculator](#coursework-calculator)* | 8        | 
| [**Week 3** – 2024-10-14 to 2024-10-21 ](#week-3-2024-10-14-to-2024-10-21) | 9        | 
| &nbsp;&nbsp;&nbsp;&nbsp;3.1 [Basic Use: Data Size](#basic-use-data-size) | 9        | 
| &nbsp;&nbsp;&nbsp;&nbsp;3.2 [Libraries: Using Cmath](#libraries-using-cmath) | 10        | 
| &nbsp;&nbsp;&nbsp;&nbsp;*3.3 [Coursework: Trig Calculator](#coursework-trig-calculator)* | 11        | 
| [**Week 4** – 2024-10-21 to 2024-10-28 ](#week-4-2024-10-21-to-2024-10-28) | 12        | 
| &nbsp;&nbsp;&nbsp;&nbsp;4.1 [Control Structures: If Else Statements](#control-structures-if-else-statements) | 12        | 
| &nbsp;&nbsp;&nbsp;&nbsp;4.2 [Control Structures: Input Validation](#control-structures-input-validation) | 13        | 
| &nbsp;&nbsp;&nbsp;&nbsp;4.3 [Control Structures: Simple Calculator](#control-structures-simple-calculator) | 14        | 
| &nbsp;&nbsp;&nbsp;&nbsp;*4.4 [Coursework: Quadratic Calculator](#coursework-quadratic-calculator)* | 15        | 
| [**Week 5** – 2024-10-28 to 2024-11-04 ](#week-5-2024-10-28-to-2024-11-04) | 16        | 
| &nbsp;&nbsp;&nbsp;&nbsp;5.1 [Control Structures: Switch Statements](#control-structures-switch-statements) | 16        | 
| &nbsp;&nbsp;&nbsp;&nbsp;5.2 [Control Structures: While Loops](#control-structures-while-loops) | 17        | 
| &nbsp;&nbsp;&nbsp;&nbsp;5.3 [Algorithms: Babylonian Square Root](#algorithms-babylonian-square-root) | 18        | 
| &nbsp;&nbsp;&nbsp;&nbsp;*5.4 [Coursework: Variable Manipulation](#coursework-variable-manipulation)* | 19        |
| **[References](#references)**                                                   | 20        |
\newpage
## **Week 1** – 2024-09-30 to 2024-10-07

**What did you learn in the lab tasks this week?**

In the lab session this week we focused on outputting to a data stream and handling special characters. In order to output to a data stream, I learned we use `cout` to declare console output and insert data into this with the insertion operator, `<<` - this differs from Python's `print` function, but is essentially how it works. This is because C++ is a lower level language, just above assembly code, and is thus more lightweight and efficient, e.g. you don't need input/output capabilities with all programs, as not all programs need a command-line interface, hence we include the line `#include <iostream>`to access these stream commands.

Additionally, we explored special characters (`\n`, `\a`, `\b`, `\f`, `\r`, and `\t`), escape sequences (`\\`, `\'`, `\"`, and `\?`), and the line terminator (`endl`). The special characters and escape sequences are similar to those used in Python, but the line terminator was completely new for me. Functionally, it seems to act the same as a newline character, but works by ending the data stream started by `cout`.

**How well did I learn it?**

I learned everything pretty quickly, making parallels with Python quite often. It's been really fun learning a completely new, more low-level language and deepening my understanding of programming in general. I did some extra work outside of my lab session, too, which definitely helped me reinforce any new knowledge and understand C++ even quicker.

**How does my solution compare with the official solution?**

There aren't any official solutions right now, so I'll write this next week if they get released.

**How can I extend the concepts used in the tasks to form a new project**

In my extra work this week, I've extended the concepts used to make Pascal's triangle by changing the logic to a more loop-based system so that I can use render any number of rows. I also tried an alternative to using the tab characters, `setd::setw`. Not only this, but I decided to take this number of rows as a user input with `std::cin` and validated the input, throwing an exception if invalid.

I also researched C++ best practices and styling guidelines, referencing documents like Google Style Guides [[1]](#references) and Doxygen [[2]](#references). The main points are learned from this were: consistent comment style (I opted for /* and /**), function return rationale (i.e. when to use `void`), explicitly returning 0 in a main function (to tell the console it ran correctly), docstring placement (before a function, contrasting with Python), and function declaration (placing the opening curly bracket on the same line).

Finally, with the project I already explained, I explored functions, for loops, conditional statements, exception handling, and some basic libraries: `cmath`, `stdexcept`, and `iomanip`.

**Lesson Review Question Answers**

1. Facilitates complex simulations; differs by enabling exploration beyond physical limits.
2. Climate modeling, drug discovery, astrophysics simulations.
3. First computer-assisted proof; raises questions about proof validity.
4. Cost/feasibility issues; safety concerns.
5. From serial to parallel computing; enhances computational power for complex problems.
6. Serial: sequential processing; Parallel: simultaneous processing.
7. Physical limits in miniaturization; heat dissipation, quantum effects.
8. FLOPS: Floating Point Operations Per Second; measures computational performance.
9. Binary: two digits (0, 1); used for electronic circuitry efficiency.
10. Encapsulation, inheritance, polymorphism.

Multiple choice: BCCBCCBBBA

### Basic Use: Using Cout

#### Task Task.1
5

```
cout << "Welcome to C++ Programming\n";
```


### Basic Use: Special Characters

#### Task Task.2
3

```
cout << "With bell character: Welcome to C++ Programming\a" << "---\n";
```

3

```
cout << "With backspace character: Welcome to C++ Programming\b" << "---\n";
```

3

```
cout << "With return character: Welcome to C++ Programming\r" << "---\n";
```

3

```
cout << "With tab character: Welcome to C++ Programming\t" << "---\n";
```

4

```
cout << "Escaped characters: Is the symbol \\n called \' Newline \' \? \n";
```

5

```
cout << "A rose by any other name would smell as sweet";
cout << endl;
```


### Basic Use: Pascals Triangle




```
/**
 * @file l03-basic_use-pascals_triangle.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Exploring cout and special characters to print Pascal's Triangle.
 * @version 0.1.0
 * @date 2024-09-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;


/**
 * @brief Main function to run the program.
 * 
 * @return int Success or failure (0 or 1).
 */
int main() {
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
     * ANSWER (Task 3.1):
     * I used the tab character, `\t` to center the numbers in the Pascal's Triangle, along with
     * `cout` to print the numbers. This ended up with a fairly nice looking Pascal's Triangle.
     */

    /* Return 0 to indicate the program ran successfully */
    return 0;
}
```



### Pascal Triangle: Extended Project




```
/**
 * @file e01-pascal_triangle-extended_project.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Outputs Pascal's triangle to the console, extending the concepts from lab 1.
 * @version 0.1.0
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream> /* For std::cout, std::cin */
#include <cmath> /* For std::ceil, std::pow */
#include <stdexcept> /* For std::invalid_argument */
#include <iomanip> /* For std::setw */


const int MAX_ROWS = 29;
const std::string ERROR_MESSAGE = "Error: rows must be between 0 and "
                                    + std::to_string(MAX_ROWS) + "!";

/**
 * @brief Outputs Pascal's triangle to the console.
 * 
 * @details Calculates Pascal's triangle iteratively using the formula:
 * \f[
 * C(n, k+1) = C(n, k) \times \frac{n - k}{k + 1}
 * \f]
 * where \f$C(n, k)\f$ is the coefficient at row \f$n\f$ and column \f$k\f$.
 * Ensures the triangle is centered in the console by calculating the maximum
 * width of the triangle and the maximum width of the coefficients, using the
 * power of 2 to estimate the width of the largest coefficient.
 * 
 * @note Designed to test the use of output streams, loops, error handling, libraries,
 * and functions in C++. Extends the concepts from lab 1, exploring new concepts
 * like using the `std::setw` function to set the width of the output instead of
 * using the tab character.
 * 
 * @param rows The number of rows to output in Pascal's triangle. Must be non-negative
 * and less than or equal to MAX_ROWS.
 *
 * @throw std::invalid_argument Throws an error if rows is less than 0 or greater than MAX_ROWS.
 *
 * @warning Since the coefficients in Pascal's triangle can grow very large, this
 * function may not work as expected for rows greater than 29.
 *
 * @example
 * \code{.cpp}
 * output_pascals_triangle(4);
 * \endcode
 *
 * Expected Output:
 * \code{.plaintext}
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 * \endcode
 */
void output_pascals_triangle(int rows) {
    /* Throw an error if rows is less than 0 or greater than MAX_ROWS. */
    if (rows < 0 || rows > MAX_ROWS) {
        throw std::invalid_argument(ERROR_MESSAGE);
    }

    /* Estimate the width of the largest coefficient using the power of 2 */
    int estimated_max_coefficient = std::ceil(std::pow(2, rows));
    int max_coefficient_width = std::to_string(estimated_max_coefficient).length() + 1;

    /* Calculate the maximum width of the triangle. */
    int max_triangle_width = max_coefficient_width * (rows + 1);

    /* Loop through each row in Pascal's triangle. */
    for (int row = 0; row <= rows; row++) {
        /* Set the first coefficient to 1 */
        int coefficient = 1;

        /* Add leading spaces to center the triangle. */
        int leading_spaces = (max_triangle_width - (max_coefficient_width * (row + 1))) / 2;
        std::cout << std::string(leading_spaces, ' ');

        /* Loop through each column in the current row. */
        for (int column = 0; column <= row; column++) {
            /* Output the current coefficient. */
            std::cout << std::setw(max_coefficient_width) << coefficient;

            /* Calculate the next coefficient. */
            coefficient = coefficient * (row - column) / (column + 1);
        }

        /* Move to the next row. */
        std::cout << std::endl;
    }
}

/**
 * @brief Main function to run the program.
 *
 * @details This function prompts the user for the number of rows to output
 * in Pascal's triangle and calls the output_pascals_triangle function.
 *
 * @return Returns 0 to indicate the program has run successfully.
 */
int main() {
    /* Prompt the user for the number of rows to output. */
    std::cout << "Please enter the number of rows you would like to output (0 to "
                << MAX_ROWS << "): ";
    int rows;
    std::cin >> rows;

    /* Output Pascal's triangle to the console. */
    try {
        output_pascals_triangle(rows);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    /* Output a goodbye message to the user. */
    std::cout << "Made by William Fayers :)" << std::endl;

    /* Return 0 to indicate the function has run successfully. */
    return 0;
}
```


\newpage
## **Week 2** – 2024-10-07 to 2024-10-14

**What did you learn in the lab tasks this week?**

...

**How well did I learn it?**

...

**How does my solution compare with the official solution?**

...

**How can I extend the concepts used in the tasks to form a new project**

...

**Coursework Question Answers**

1. False, they're stored as binary numbers.
2. Device.
3. `.cpp` extension.
4. Translate source code into machine readable code (or exectuable program) that the computer can run.
5. 8 bits.
6. Hexadecimal (base 16).
7. $15 * 16^5 + 10 * 16^4 + 12 * 16^3 + 10 * 16^2 + 13 * 16^1 + 14 * 16^0 = 16435934$.
8. True.
9. `cout` is used without the namespace `std`, and line 5 is missing a semicolon at the end of the line.
10. Missing the insertion operator on line 8, correct line is `cin >> num1 >> num2;`

### Basic Use: Variables And Data Types

#### Task Task.1
2

```
int total_children = 10;
int candies_per_child = 5;
int extra_candies = 10;
```

2

```
std::cout << "HALLOWEEN CANDY CALCULATOR" << std::endl;
std::cout << "Total Children: " << total_children << std::endl;
std::cout << "Candies per Child: " << candies_per_child << std::endl;
std::cout << "Extra Candies: " << extra_candies << std::endl;
std::cout << "---" << std::endl;
std::cout << "Total Candies: " << total_candies << std::endl;
```

2

```
return 0;
```


### Basic Use: Input And Math

#### Task Task.2
3

```
float mass1, mass2, distance;
```

3

```
std::cout << "Enter the mass of the first object (kg): ";
std::cin >> mass1;
std::cout << "Enter the mass of the second object (kg): ";
std::cin >> mass2;
std::cout << "Enter the distance between the objects (m): ";
std::cin >> distance;
```

3

```
try {
float force = calculate_gravitational_force(mass1, mass2, distance);
std::cout << "Gravitational Force: " << force << " N" << std::endl;
} catch (std::invalid_argument& error) {
std::cerr << "Error: " << error.what() << std::endl;
}
```




### Coursework: Calculator

#### Task Task.1
1

```
float radius;
input_number(radius, "Enter the radius of the circle: ");
```
1

```
float area = M_PI * radius * radius;
float circumference = 2 * M_PI * radius;
std::cout << "Area of a circle with radius " << radius << " = " << area << std::endl;
std::cout << "Circumference of a circle with radius " << radius << " = " << circumference
<< std::endl;
```
2

```
float principal, rate, time;
input_number(principal, "Enter the principal amount: ");
input_number(rate, "Enter the rate of interest (%): ");
input_number(time, "Enter the time period (years): ");
```
2

```
float simple_interest = (principal * rate * time) / 100;
std::cout << "Simple Interest on a principal amount of " << principal << " at a rate of "
<< rate << "% for " << time << " years = " << simple_interest << std::endl;
```


\newpage
## **Week 3** – 2024-10-14 to 2024-10-21

**What did you learn in the lab tasks this week?**

...

**How well did I learn it?**

...

**How does my solution compare with the official solution?**

...

**How can I extend the concepts used in the tasks to form a new project**

...

**Coursework Question Answers**

Multiple choice: bba.
True or false: TTTT (note for the third statement, technically the return statement can be implicit, but it's always required even if it's implicitly there).

### Basic Use: Data Size

#### Task Task.1
1

```
std::cout << "Original number: " << unsigned_small_number << std::endl;
unsigned_small_number++;
std::cout << "Incremented number (1x): " << unsigned_small_number << std::endl;
unsigned_small_number++;
std::cout << "Incremented number (2x): " << unsigned_small_number << std::endl;
```

3

```
signed_small_number = -32768;
std::cout << "Original number: " << signed_small_number << std::endl;
signed_small_number--;
std::cout << "Decremented number (1x): " << signed_small_number << std::endl;
signed_small_number--;
std::cout << "Decremented number (2x): " << signed_small_number << std::endl;
```


### Libraries: Using Cmath

#### Task Task.2
1

```
std::cout << sqrt(9.0) << std::endl;
```

1

```
std::cout << log(1.1) << std::endl;
```

1

```
std::cout << pow(2.5, 3.0) << std::endl;
```

1

```
std::cout << ceil(4.1) << std::endl;
```

1

```
std::cout << (7 + sqrt(7.0)) / 3.0 << std::endl;
```

1

```
std::cout << tanh(0.342) << std::endl;
```

1

```
std::cout << fmod(11.0, 4.0) << std::endl;
```

1

```
std::cout << abs(-9) << std::endl;
```

1

```
std::cout << fabs(-4.5) << std::endl;
```

1

```
std::cout << floor(8.8) << std::endl;
```

1

```
std::cout << log10(1.0) << std::endl;
```

1

```
std::cout << cbrt(10.0) << std::endl;
```

3

```
double x;
std::cout << "Calculation of the hyperbolic cosecant function..." << std::endl;
std::cout << "Enter a value for x: ";
std::cin >> x;
```

3

```
double y = csch(x);
if (!std::isnan(y)) {
std::cout << "Hyperbolic cosecant of " << x << " is: " << y << std::endl;
} else {
std::cout << "Hyperbolic cosecant is undefined for x = 0." << std::endl;
}
```




### Coursework: Trig Calculator

#### Task Task.3
0

```
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
```
1

```
double atanh(double x) {
if (x < -1 || x > 1) {
std::cerr << "\nError: The input value must be between -1 and 1." << std::endl;
return NAN;
}
return 0.5 * log((1 + x) / (1 - x));
}
```
2

```
double acosh(double x) {
if (x < 1) {
std::cerr << "\nError: The input value must be greater than or equal to 1." << std::endl;
return NAN;
}
return log(x + sqrt(x * x - 1));
}
```
0

```
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
```


\newpage
## **Week 4** – 2024-10-21 to 2024-10-28

**What did you learn in the lab tasks this week?**

...

**How well did I learn it?**

...

**How does my solution compare with the official solution?**

...

**How can I extend the concepts used in the tasks to form a new project**

...

### Control Structures: If Else Statements

#### Task Task.1
1

```
std::tuple<double, double> evaluate_function1(double x, double &y) {
if (x >= 2) {
std::cout << "x is greater than or equal to 2, so \n";
std::cout << "y = x^3 + sqrt(x) = ";
y = pow(x, 3) + sqrt(x);
} else if (x > 0.5 && x < 2) {
std::cout << "x is between 0.5 and 2, so \n";
std::cout << "y = 1 - exp(x) = ";
y = 1 - exp(x);
} else {
std::cout << "x is less than or equal to 0.5, so \n";
std::cout << "y = |x + 5| = ";
y = fabs(x + 5);
}

return std::make_tuple(x, y);
}
```

3

```
std::tuple<double, double> evaluate_function2(double x, double &y) {
if (x < -M_PI/2) {
std::cout << "x is less than -pi/2, so \n";
std::cout << "y = -1 - pi/2 = ";
y = -1 - M_PI/2;
} else if (x >= -M_PI/2 && x <= 0) {
std::cout << "x is between -pi/2 and 0, so \n";
std::cout << "y = sin(x) + x = ";
y = sin(x) + x;
} else {
std::cout << "x is greater than 0, so \n";
std::cout << "y = x = ";
y = x;
}

return std::make_tuple(x, y);
}
```


### Control Structures: Input Validation

#### Task Task.2
0

```
const double banned_number = 2.0;
const double small_number = 10e-12;
```

0

```
double x;
std::cout << "Enter a value for x (other than 2.0): ";
std::cin >> x;
```

0

```
cout << "When x = " << x << ", the function y = 1/(x^2 - 2) is equal to ";
double y = 1 / (std::pow(x, 2.0) - 2.0);
cout << y << endl;
```


### Control Structures: Simple Calculator

#### Task Task.3
0

```
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
```

0

```
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
```




### Coursework: Quadratic Calculator

#### Task Task.5
0

```
#include <cmath>
#include <iostream>
#include <limits>
#include <tuple>
```
0

```
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
```
0

```
std::tuple<double, double> solve_quadratic(const double a, const double b, const double c) {
double discriminant = pow(b, 2) - 4 * a * c;
if (discriminant < 0) {
return std::make_tuple(NAN, NAN);
}

double x1 = (-b + sqrt(discriminant)) / (2 * a);
double x2 = (-b - sqrt(discriminant)) / (2 * a);

return std::make_tuple(x1, x2);
}
```
0

```
int main() {
while (true) {
double a, b, c;
input_number(a, "Enter the coefficient of x^2: ");
input_number(b, "Enter the coefficient of x: ");
input_number(c, "Enter the constant term: ");

std::tuple<double, double> x = solve_quadratic(a, b, c);

std::cout << "The quadratic equation " << a << "x^2 + " << b << "x + " << c << " = 0 has ";

if (std::isnan(std::get<0>(x))) {
std::cout << "no real solutions." << std::endl;
} else if (std::get<0>(x) == std::get<1>(x)) {
std::cout << "one solution: x = " << std::get<0>(x)
<< std::endl;
} else {
std::cout << "two solutions: x = " << std::get<0>(x)
<< " and x = " << std::get<1>(x) << std::endl;
}

char response;
std::cout << "Would you like to solve another quadratic equation? (y/n): ";
std::cin >> response;

if (response != 'y') {
break;
}
}

return 0;
}
```


\newpage
## **Week 5** – 2024-10-28 to 2024-11-04

**What did you learn in the lab tasks this week?**

...

**How well did I learn it?**

...

**How does my solution compare with the official solution?**

...

**How can I extend the concepts used in the tasks to form a new project**

...

### Control Structures: Switch Statements

#### Task Task.1
1

```
void example_switch_function() {
unsigned int incrementor = 3;
unsigned int number;

switch (incrementor) {
case 1:
number = 1;
break;
case 2:
number = 1;
break;
case 3:
number = 2;
break;
case 4:
number = 6;
break;
case 5:
number = 24;
break;
default:
number = 0;
break;
}

std::cout << "The number is: " << number << std::endl;
}
```

1

```
// example_switch_function(); // uncomment this line to run the example
```

2

```

const double small_number = 10e-12;
double x, y;
int selection;

std::cout << "FUNCTION LIST" << std::endl;
std::cout << "1. csch(x)" << std::endl;
std::cout << "2. sech(x)" << std::endl;
std::cout << "3. coth(x)" << std::endl;

std::cout << "Select a function (1-3): ";
std::cin >> selection;
if (selection > 0 && selection < 4) {
std::cout << "Enter a value for x: ";
std::cin >> x;
std::cout << "For x = " << x << ", ";
}

switch (selection) {
case 1:
if (std::abs(x) < small_number) {
std::cout << "csch(x) is undefined for x = 0." << std::endl;
return 1;
}
y = 1/sinh(x);
std::cout << "csch(x) ";
break;
case 2:
y = 1/cosh(x);
std::cout << "sech(x) ";
break;
case 3:
if (std::abs(x) < small_number) {
std::cout << "coth(x) is undefined for x = 0." << std::endl;
return 1;
}
y = 1/tanh(x);
std::cout << "coth(x) ";
break;
default:
std::cout << "Invalid selection." << std::endl;
return 1;
}

std::cout << "= " << y << std::endl;
```


### Control Structures: While Loops

#### Task Task.2
1

```
std::setprecision(10);
```

1

```
double mean = sum / 6;
```

1

```
double variance = ((sum_of_squares / 6) - (mean * mean)) * 6 / 5;
double standard_deviation = std::sqrt(variance);
```

1

```
std::cout << "The minimum value is: " << min << std::endl;
std::cout << "The maximum value is: " << max << std::endl;
std::cout << "The mean value is: " << mean << std::endl;
std::cout << "The standard deviation is: " << standard_deviation << std::endl;
```

2

```
do {
factorial_result *= current_number;
current_number++;
} while (current_number <= input_number);
```

2

```
std::cout << "The factorial of " << input_number << " is: " << factorial_result << std::endl;
```


### Algorithms: Babylonian Square Root

#### Task Task.3
1

```
double number = 0;
std::cout << "Enter a number: ";
std::cin >> number;
```

1

```
double square_root = babylonian_square_root(number);
std::cout << "The square root of " << number << " is " << square_root << std::endl;
```




### Coursework: Variable Manipulation

#### Task Task.6
0

```
#include <cmath>
#include <iostream>
```
1

```
int x = 25;
int y = 18;
double pay_rate = 12.50;
int first_number = 10;
int temporary_number = first_number;
```
2

```
int temporary_x = x;
x = y;
y = temporary_x;
```
3

```
std::cout << "The value of x is: " << x << std::endl;
std::cout << "The value of y is: " << y << std::endl;
double evaluated_expression = (x + 12) / (y - 18 + pow(x, 3)); // Unsure if correct expression
std::cout << "Substituting these values into the expression (x + 12) / (y - 18 + x^3) gives: "
<< evaluated_expression << std::endl;
```


\newpage
## 📓 References



[1] "A comprehensive guide to C++ coding standards and best practices," *C++ Style Guide*, 2024. [Online] Available: https://google.github.io/styleguide/cppguide.html (accessed 2024-10-05).

[2] "Official documentation for Doxygen's documentation blocks and usage," *Doxygen Manual - Documentation Blocks*, 2024. [Online] Available: https://www.doxygen.nl/manual/docblocks.html (accessed 2024-10-05).
