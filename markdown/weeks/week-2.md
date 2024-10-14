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

1. True.
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

#### Task 1.2
Declare and initalise the variables

```
int total_children = 10;
int candies_per_child = 5;
int extra_candies = 10;
```

Output the starting values and the total number of candies

```
std::cout << "HALLOWEEN CANDY CALCULATOR" << std::endl;
std::cout << "Total Children: " << total_children << std::endl;
std::cout << "Candies per Child: " << candies_per_child << std::endl;
std::cout << "Extra Candies: " << extra_candies << std::endl;
std::cout << "---" << std::endl;
std::cout << "Total Candies: " << total_candies << std::endl;
```

Return 0 to indicate the program ran successfully

```
return 0;
```

#### Task 1.2
`unsigned short int` can be broken down into three parts:\n - `unsigned`: This means the variable can only store positive values, which fits the context of candies, as we cannot have a negative number of candies.\n - `short`: This means the variable can store values between 0 and 65,535, which is more than enough for the number of candies we are calculating.\n - `int`: This means the variable is an integer, which is the type of data we are working with.\n Hence, `unsigned short int` is the most appropriate data type for the variable `total_candies`. 

```
unsigned short int total_candies;
```

Calculate the total number of candies by multipling the average per child by the total number of children, then adding the extra candies. 

```
total_candies = total_children * candies_per_child + extra_candies;
```


### Basic Use: Input And Math

#### Task 2.2
To calculate the remainder of two floats without using any library functions, we can cast the result of the division to an integer, multiply it by the second number, and subtract it from the first number. This will give us the remainder of the division. If we used the `fmod` function from the `cmath` library, we could calculate the remainder directly without the need for casting. I only found this out after writing the code, though. 

```
result = number1 - (static_cast<int>(number1 / number2) * number2);
std::cout << "Remainder: " << result << std::endl;
```

#### Task 2.3
We can create a function called `calculate_gravitational_force` that takes the masses of two objects and the distance between them as input parameters. The function calculates the gravitational force between the two objects using the formula:\n $F = \frac{G * m_{1} * m_{2}}{d^{2}}$ 

```
float calculate_gravitational_force(float mass1, float mass2, float distance) {
const float G = 6.67430e-11;
if (distance == 0) {
throw std::invalid_argument("Distance cannot be zero.");
}
return (G * mass1 * mass2) / (distance * distance);
}
```

#### Task 2.3
Declare variables to store the masses and distance.

```
float mass1, mass2, distance;
```

We then input the masses and distance.

```
std::cout << "Enter the mass of the first object (kg): ";
std::cin >> mass1;
std::cout << "Enter the mass of the second object (kg): ";
std::cin >> mass2;
std::cout << "Enter the distance between the objects (m): ";
std::cin >> distance;
```

And finally we call the function, catching any exceptions that occur.

```
try {
float force = calculate_gravitational_force(mass1, mass2, distance);
std::cout << "Gravitational Force: " << force << " N" << std::endl;
} catch (std::invalid_argument& error) {
std::cerr << "Error: " << error.what() << std::endl;
}
```




### Coursework: Calculator

#### Task 1.1
Input the radius of the circle.

```
float radius;
input_number(radius, "Enter the radius of the circle: ");
```
Calculate the area and circumference of the circle.

```
float area = M_PI * radius * radius;
float circumference = 2 * M_PI * radius;
std::cout << "Area of a circle with radius " << radius << " = " << area << std::endl;
std::cout << "Circumference of a circle with radius " << radius << " = " << circumference
<< std::endl;
```
#### Task 1.2
Input the principal amount, rate of interest, and time period.

```
float principal, rate, time;
input_number(principal, "Enter the principal amount: ");
input_number(rate, "Enter the rate of interest (%): ");
input_number(time, "Enter the time period (years): ");
```
Calculate the simple interest.

```
float simple_interest = (principal * rate * time) / 100;
std::cout << "Simple Interest on a principal amount of " << principal << " at a rate of "
<< rate << "% for " << time << " years = " << simple_interest << std::endl;
```

