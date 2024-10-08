## **Week 2** – 2024-10-07 to 2024-10-14

**What did you learn in the lab tasks this week?**

...

**How well did I learn it?**

...

**How does my solution compare with the official solution?**

...

**How can I extend the concepts used in the tasks to form a new project**

...

**Lesson Review Question Answers**

...

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
To calculate the remainder of two floats without using any library functions, we can cast the result of the division to an integer, multiply it by the second number, and subtract it from the first number. This will give us the remainder of the division. 

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




