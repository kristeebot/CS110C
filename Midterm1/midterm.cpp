// KristinaHelwing
//MidTerm1
// CS110C MaxLuttrell
// 100322

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

// Part 1. Write a recursive C++ function that returns how many odd integers are contained in an integer array of length size.  
//You may assume the array passed in and its size are valid, that the array has at least three elements, and that all of the elements in the array are positive.  No points given for a solution which isn’t recursive. Your function must have the following signature:

int numOdds(int array[], int size)
{
    if (size == 1)
    {
        return array[0] % 2;
    }
    return array[0] % 2 + numOdds(&array[1], size - 1);
}

// Part 2. Write a simple main() function which demonstrates that your function works correctly. It should do the following:
// Create an int array with at least three elements, and give the elements some reasonable values. 
//At least one of the elements should be odd.
// Call your function with this array and its size as parameters, and output the return value.
// Your answer should be an entire C++ program which compiles and runs properly on hills.

int main()
{
    int numbersToCount[] = {5, 3, 6, 7, 8};
    int oddCount = numOdds(numbersToCount, 5);
    assert(oddCount == 3);
    cout << "The amount of odd numbers in the array are: " << oddCount << endl;
    return 0;
}
/* SAMPLE OUTPUT
The amount of odd numbers in the array are: 3
Process exited with status 0
logout
*/