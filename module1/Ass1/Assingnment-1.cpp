// Assignment 1 - Recursion
// CS110C
// KristinaHelwing

/*
For this assignment, write the following functions in C++.  They must be recursive.
For all of these functions, you will not receive any credit for non-recursive solutions.
*/
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// 1.  Chapter 2, exercise 9: Write a recursive C++ function that writes the digits of a positive decimal integer in reverse order.
// Hint: 2015 % 10 == 5, 2015 / 10 == 201.  Example: if given the integer 2015, your function should output 5102. 
// recursively write an array of ints backward
// Pre: anArray is a valid array of ints;
// firstPos, lastPos are zero-indexed first and last indices in array to write backwards.
// Post: anArray is output backwards from firstPos to lastPos
void writeDigitsBackward(int *anArray, int firstPos, int lastPos)
{
    cout << anArray[lastPos] << endl;
    if (firstPos == lastPos)
    {
        return;
    }
    writeDigitsBackward(anArray, firstPos, lastPos - 1);
}
void writeDigitsBackward(int i)
{
    // Use Google and Stack overflow to get an array of digits:
    std::vector<int> digits;

    while (i)
    {
        int mod_digit = i % 10;
        digits.push_back(mod_digit);

        i /= 10;
    }

    std::reverse(digits.begin(), digits.end());
    int *digitArray = digits.data();

    // Call the actual recursive function:
    writeDigitsBackward(digitArray, 0, digits.size() - 1);
}
// 2.  Rewrite both of the functions writeBackward and writeBackward2 in section 2.3.1 of the text (page 61 in both the 6th and 7th edition) as C++ functions.
// You may use either C-strings (char *)  or C++ string objects for the string.
// Make sure you include all of the cout statements in these functions which indicate function entry, function exit, and about to write a character.
// Make sure you carefully trace the functions and understand why the cout statements appear where they do when you run the program.
void writeBackward(string s)
{
    cout << "enter writeBackward with string: " << s << endl;
    if (s.empty())
    {
        // do nothing-- this is the base case
    }
    else
    {
        cout << s.substr(s.size() - 1, 1) << endl;

        cout << "About to write last character of string: "
             << s << endl;
        // write last character of s
        writeBackward(s.substr(0, s.size() - 1)); // Point A
    }
    cout << "Leave writeBackward with string: " << s << endl;
}
void writeBackward2(string s)
{
    cout << "enter writeBackward2 with string: " << s << endl;
    if (s.empty())
    {
        // do nothing-- this is the base case
    }
    else
    {
        writeBackward2(s.substr(1, s.size() - 1)); // Point A

        cout << "About to write first character of string: "
             << s << endl;
        // write first character of s
        cout << s.substr(0, 1) << endl;
    }
    cout << "Leave writeBackward with string: " << s << endl;
}
// 3.  Chapter 2, exercise 4: Given two integers, start and end, where end is greater than start, write a recursive C++ function that returns the sum of the integers from start through end, inclusive.
// For example, if start is 3 and end is 6, the function should return 18, because 3+4+5+6 = 18.
int recursiveSum(vector<int> inputArray, int total)
{
    if (inputArray.empty())
    {
        return total;
    }
    int currentValue = inputArray[0];
    return recursiveSum(vector<int>(inputArray.begin() + 1, inputArray.end()), currentValue + total);
}
int main()
{
    writeDigitsBackward(123);
    writeBackward("cat");
    cout << endl;
    writeBackward2("dog");
    cout << endl;
    vector<int> sumInputs;
    sumInputs.push_back(4);
    sumInputs.push_back(5);
    sumInputs.push_back(6);
    int sum = recursiveSum(sumInputs, 0);
    cout << sum << endl;
    return 0;
}
/* SAMPLE OUTPUT
1 arguments:
argv[0] = '/Users/kristinahelwing/CS110C/moduleOne/Ass1/Assingnment-1'
3
2
1
enter writeBackward with string: cat
t
About to write last character of string: cat
enter writeBackward with string: ca
a
About to write last character of string: ca
enter writeBackward with string: c
c
About to write last character of string: c
enter writeBackward with string: 
Leave writeBackward with string: 
Leave writeBackward with string: c
Leave writeBackward with string: ca
Leave writeBackward with string: cat

enter writeBackward2 with string: dog
enter writeBackward2 with string: og
enter writeBackward2 with string: g
enter writeBackward2 with string: 
Leave writeBackward with string: 
About to write first character of string: g
g
Leave writeBackward with string: g
About to write first character of string: og
o
Leave writeBackward with string: og
About to write first character of string: dog
d
Leave writeBackward with string: dog

15
Process exited with status 0
*/
