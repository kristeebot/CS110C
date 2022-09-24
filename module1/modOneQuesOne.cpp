// Question 1
// Implement a recursive reverseString in C++ function like the one in the pdf's videos, but with a twist.
// You are no longer allowed to print out the last character in s.  You are, however, allowed to print out the first character in s, i.e. s[0].
// First, make one change to the function so that it prints out the first character in s, s[0] and then calls ReverseString on s minus the last character.
// Notice that it doesn't work anymore!  It no longer reverses the string.  Look at what it does and think about why.
// What further changes can you make to the function to fix it?
// In other words, write a recursive function that reverses the string, but you aren't allowed to print out the last character in s.
// You are allowed print out the first character in s.  Useful string functions:
// s.size() - returns length of string s
// s.substr(pos,len) - returns the substring of s of length len starting at postion pos (zero is first position)

// recursively outputs reverse of string s
// precondition: s is a string
// postcondition: s isn't changed
#include <string>
#include <iostream>
using namespace std;

void reverseString(string s)
{
    int length = s.size();
    if (length > 0)
    {
        // write the last character
        cout << s[length - 1];
        // call reverseString on s minus the last character
        reverseString(s.substr(0, length - 1));
    }
}
void writeArrayBackward(int anArray[], int firstPos, int lastPos)
{
    if (firstPos <= lastPos)
    {
        cout << anArray[lastPos] << endl;
        writeArrayBackward(anArray, firstPos, lastPos - 1);
    }
}

void reverseString2(string s)
{
    int length = s.size();
    if (length > 0)
    {
        // call reverseString2 on s minus the first character
        reverseString2(s.substr(1, length - 1));
        // write the first character
        cout << s[0];
    }
}
// recursively write an array of ints backward
// Pre: anArray is a valid array of ints;
// firstPos, lastPos are zero-indexed first and last indices
// in array to write backwards.
// Post: anArray is output backwards from firstPos to lastPos
int mainQ1()
{
    int arr[] = {2, 4, 6, 8};
    writeArrayBackward(arr, 0, 3);
    reverseString("abcde");
    cout << endl;
    reverseString2("abcde");
    cout << endl;

    return 0;
}
/*SAMPLE OUTPUT
8
6
4
2
edcba
edcba
*/
