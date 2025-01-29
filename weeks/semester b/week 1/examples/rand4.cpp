#include <iostream>
#include <cstdlib>  // Needed for rand() and srand()
#include <ctime>    // Needed for time()
#include <random>   // Modern random number generation
using namespace std;

int main()
{
    int b, c;
    double num[10];  // Declaration of the array for 10 numbers
    double a;
    int size;

    size = 10; // Number of elements to sort out
    
    // Seed the random number generator with the current time
    //  srand(static_cast<unsigned int>(time(0))); 
    ////////////////////////////////
    // Modern random number generator
    random_device rd;                            // Random device for seeding
    mt19937 gen(rd());                           // Mersenne Twister engine
    uniform_real_distribution<double> dist(0.0, 1.0); // Uniform distribution in [0.0, 1.0)


    // Initialization of the array
    for (c = 0; c < size; c++)
        //num[c] = (rand() % 100); // Random function with range [0, 99]
        //num[c] = (rand() % 100) +1; // Random function with range [1, 100]
      num[c] = dist(gen);
    // Displaying the array on the screen
    cout << "Original numbers are: " << endl;
    for (c = 0; c < size; c++)
        cout << num[c] << endl;
    cout << endl;

    return 0;
}
