#include <iostream>  // For input and output
#include <cstdlib>   // For rand(), srand(), and RAND_MAX
#include <ctime>     // For time()
using namespace std;

int main()
{
    int b, c;                 // Loop variables
    int range[10] = {0};      // Array to count how many numbers fall into each range (initialized to 0)
    double num[100];          // Array to store 100 random numbers
    double dx, dx1, dx2;      // Variables for defining range divisions
    int size;                 // Number of random numbers
    int dr = 10;              // Number of divisions (ranges) for categorization

    size = 100;               // Number of random numbers to generate
    dx = 1.0 / dr;            // Step size for each range (0.1 if dr = 10)

    // Seed the random number generator with the current time
    //srand(static_cast<unsigned int>(time(0)));

    // Initialization of the array with random numbers between 0 and 1
    for (c = 0; c < size; c++) {
        num[c] = ((double)rand() / RAND_MAX); // Generates random double values in [0, 1]
    }

    // Categorize numbers into ranges
    for (b = 1; b <= dr; b++) {
        dx1 = (b - 1) * dx;    // Start of the range (lower bound)
        dx2 = b * dx;          // End of the range (upper bound)

        for (c = 0; c < size; c++) {
            // Check if the number falls into the current range [dx1, dx2)
            if (num[c] < dx2 && num[c] >= dx1) {
                range[b - 1]++;  // Increment the count for the current range
            }
        }
    }

    // Display the range counts
    for (b = 0; b < dr; b++) {
        cout << "range[" << b << "] = " << range[b] << endl;  // Print the count for each range
    }

    return 0;  // End of the program
}
