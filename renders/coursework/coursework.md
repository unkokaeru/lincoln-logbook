## **calculator**


### Task Task 1

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



## **trig_calculator**


### Task Task 3

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



## **quadratic_calculator**


### Task Task 5

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



