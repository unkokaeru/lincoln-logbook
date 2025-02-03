#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    int a, b, iterations = 0; // iteration - counts the total iterations
    int num[10];  // Declare an array of 10 numbers
    int size = 10;  // Define the number of elements

    srand(time(0));  // Seed the random generator to avoid repetitive sequences

    // Initialize the array with random numbers between 1 and 100
    for (int c = 0; c < size; c++) {
        num[c] = rand() % 100 + 1;  // Random numbers between 1 and 100
    }

    // Display original numbers
    cout << "Original numbers: ";
    for (int c = 0; c < size; c++) {
        cout << num[c] << " ";
    }
    cout << endl;

    // Optimized Bubble Sort with early stopping
    bool swapped;
    for (a = 0; a < size - 1; a++) {
        swapped = false;  // Reset swap flag
        for (b = 0; b < size - 1 - a; b++) {  // Inner loop shrinks as elements get sorted
            iterations++; // It counts  each iteration
            if (num[b] > num[b + 1]) {
                swap(num[b], num[b + 1]);  // It uses swap function
                swapped = true;
            }
        }
        if (!swapped) break;  // If no swaps, array is already sorted
    }

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int c = 0; c < size; c++) {
        cout << num[c] << " ";
    }
    cout << endl;
  // Printing the total number of iterations
    cout << " Total interations:" << iterations << endl;

    return 0;
}