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

#### Task 1.1
After reaching the max value of the data type, the number goes to zero.

```
std::cout << "Original number: " << unsigned_small_number << std::endl;
unsigned_small_number++;
std::cout << "Incremented number (1x): " << unsigned_small_number << std::endl;
unsigned_small_number++;
std::cout << "Incremented number (2x): " << unsigned_small_number << std::endl;
```

#### Task 1.2
After reaching the max value of the data type, the number goes to -32768. I think this is because it wraps around to the minimum value of the data type when it reaches the maximum. This is called an overflow. 

```
short int signed_small_number = 32767;
std::cout << "Original number: " << signed_small_number << std::endl;
signed_small_number++;
std::cout << "Incremented number (1x): " << signed_small_number << std::endl;
signed_small_number++;
std::cout << "Incremented number (2x): " << signed_small_number << std::endl;
```

#### Task 1.3
Similar to overflow, it loops around as an underflow.

```
signed_small_number = -32768;
std::cout << "Original number: " << signed_small_number << std::endl;
signed_small_number--;
std::cout << "Decremented number (1x): " << signed_small_number << std::endl;
signed_small_number--;
std::cout << "Decremented number (2x): " << signed_small_number << std::endl;
```

#### Task 1.4
The size of the data types follow a pattern, where the size of the data type is doubled when using a long data type (e.g. long int, long long int, long double). The size of each data type logically increases as the data type can store larger numbers. 

```
std::cout << "Size of an unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
std::cout << "Size of an int: " << sizeof(unsigned_small_number) << " bytes" << std::endl;
std::cout << "Size of a short int: " << sizeof(signed_small_number) << " bytes" << std::endl;
std::cout << "Size of a long int: " << sizeof(long int) << " bytes" << std::endl;
std::cout << "Size of a long long int: " << sizeof(long long int) << " bytes" << std::endl;
std::cout << "Size of a double: " << sizeof(double) << " bytes" << std::endl;
std::cout << "Size of a long double: " << sizeof(long double) << " bytes" << std::endl;
std::cout << "Size of a float: " << sizeof(float) << " bytes" << std::endl;
std::cout << "Size of a char: " << sizeof(char) << " bytes" << std::endl;
```

#### Task 1.5
The maximum and minimum values of the data types are defined in the limits.h header file. The maximum value of a signed data type is always one less than the maximum value of the unsigned data type of the same size. The minimum value of a signed data type is always the negative of the maximum value minus one. 

```
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
```


### Libraries: Using Cmath

#### Task 2.3
Implement a custom csch function that calculates the hyperbolic cosecant of a number. 

```
double csch(double x) {
if (x == 0) {
std::cerr << "Error: Division by zero." << std::endl;
return NAN;
}

double answer = 1 / sinh(x);
return answer;
}
```

#### Task 2.1
Calculate the square root of 9.0, which resulted in 3.

```
std::cout << sqrt(9.0) << std::endl;
```

Calculate the natural logarithm of 1.1, which resulted in 0.0953102.

```
std::cout << log(1.1) << std::endl;
```

Calculate 2.5 raised to the power of 3.0, which resulted in 15.625.

```
std::cout << pow(2.5, 3.0) << std::endl;
```

Calculate the ceiling of 4.1, which resulted in 5.

```
std::cout << ceil(4.1) << std::endl;
```

Calculate (7 + sqrt(7.0)) / 3.0, which resulted in 3.21525.

```
std::cout << (7 + sqrt(7.0)) / 3.0 << std::endl;
```

Calculate the hyperbolic tan of 0.342, which resulted in 0.329262

```
std::cout << tanh(0.342) << std::endl;
```

Calculate the remainder of 11.0 divided by 4.0, which resulted in 3.

```
std::cout << fmod(11.0, 4.0) << std::endl;
```

Calculate the absolute value of -9, which resulted in 9.

```
std::cout << abs(-9) << std::endl;
```

Calculate the (floating) absolute value of -4.5, which resulted in 4.5.

```
std::cout << fabs(-4.5) << std::endl;
```

Calculate the floor of 8.8, which resulted in 8.

```
std::cout << floor(8.8) << std::endl;
```

Calculate the base-10 logarithm of 1.0, which resulted in 0.

```
std::cout << log10(1.0) << std::endl;
```

Calculate the cube root of 10.0, which resulted in 2.15443.

```
std::cout << cbrt(10.0) << std::endl;
```

#### Task 2.2
Perform the complex calculation (resulting in -0.266116): $$ \frac{2}{15} - \frac{\left(\frac{1}{3}-\sin(0.5)\right)}{-\frac{5}{13}} + \frac{\left(\frac{1}{3}-\tanh(0.3)\right)}{-\frac{1}{7}-2} $$ 

```
double calculation_1 = (2.0 / 15.0) -
(((1.0 / 3.0) - (sin(0.5))) / (-5.0 / 13.0)) +
(((1.0 / 3.0) - (tanh(0.3))) / (-(1.0 / 7.0) - (2.0)));
std::cout << calculation_1 << std::endl;
```

Perform the complex calculation (resulting in 6.17943): $$ \left|-9\cdot(-5)^{-2}-1\right|^{\sin(1.0)}\cdot \frac{\left(\left(\frac{4}{2}\right)^{2}+\left(\frac{1}{3}\right)^{-2}-\sqrt[3]{-5}\right)} {\sqrt{\frac{17}{3}}} $$ 

```
double calculation_2 = pow(
abs((-9) * pow((-5), (-2)) - (1)),
sin(1.0)
) * (
(pow((4.0 / 2.0), (2)) + pow((1.0 / 3.0), (-2)) - cbrt(-5)) /
sqrt(17.0 / 3.0)
);
std::cout << calculation_2 << std::endl;
```

#### Task 2.3
Prompt the user for a value of x.

```
double x;
std::cout << "Calculation of the hyperbolic cosecant function..." << std::endl;
std::cout << "Enter a value for x: ";
std::cin >> x;
```

Calculate the hyperbolic cosecant of x using the custom csch function.

```
double y = csch(x);
if (!std::isnan(y)) {
std::cout << "Hyperbolic cosecant of " << x << " is: " << y << std::endl;
} else {
std::cout << "Hyperbolic cosecant is undefined for x = 0." << std::endl;
}
```




### Coursework: Trig Calculator

#### Task 3.0
Start with a verbose number input function to re-use.

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
Implement the main program loop with the atanh and acosh functions.

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
#### Task 3.1
Implement the atanh function, with error checking.

```
double atanh(double x) {
if (x < -1 || x > 1) {
std::cerr << "\nError: The input value must be between -1 and 1." << std::endl;
return NAN;
}
return 0.5 * log((1 + x) / (1 - x));
}
```
#### Task 3.2
Implement the acosh function, with error checking.

```
double acosh(double x) {
if (x < 1) {
std::cerr << "\nError: The input value must be greater than or equal to 1." << std::endl;
return NAN;
}
return log(x + sqrt(x * x - 1));
}
```

