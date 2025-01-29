#include <iostream>
#include <cstdlib>  // Needed for rand() and srand()
#include <ctime>    // Needed for time()
using namespace std;

int main()
{
    int b, c;
    double num[10];  // Declaration of the array for 10 numbers
    double a;
    int size;

    size = 10; // Number of elements to sort out
    
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0))); 

    // Initialization of the array
    for (c = 0; c < size; c++)
        //num[c] = (rand() % 100); // Random function with range [0, 99]
        num[c] = (rand() % 100) +1; // Random function with range [1, 100]
    
    // Displaying the array on the screen
    cout << "Original numbers are: " << endl;
    for (c = 0; c < size; c++)
        cout << num[c] << endl;
    cout << endl;

    return 0;
}
