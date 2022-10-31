// KristinaHelwing
// CS110C MAX LUTTRELL
// AssignmentEight
// This assigment determines if a string is a palindrome

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_STACK = 10;

// Stack class from Assignment 7 without modification.
class Stack
{
private:
    char stack[MAX_STACK];
    int top;

public:
    Stack()
    {
        top = 0;
    }
    void push(char value)
    {
        stack[top++] = value;
    }
    char peek()
    {
        if (isEmpty())
        {
            cerr << "cannot peek into an empty stack" << endl;
            exit(-1);
        }
        return stack[top - 1];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        top--;
        return true;
    }
};
const int MAX_QUEUE = 10;
// a queue of chars
class Queue
{
private:
    // an array to hold queue entries
    char entries[MAX_QUEUE + 1];
    // properties to hold current front,
    // back, and count
    int front;
    int back;

public:
    Queue()
    {
        back = MAX_QUEUE;
        front = 0;
        memset(entries, 0, MAX_QUEUE + 1);
    };
    bool enqueue(char newEntry);
    bool dequeue();
    char peek();
    bool isEmpty()
    {
        return front == back;
    }
    bool isFull()
    {
        return front == ((back + 1) % MAX_QUEUE); // extra credit
    }
};

bool Queue::enqueue(char newEntry)
{
    if (isFull())
    {
        return false;
    }
    back = (back + 1) % MAX_QUEUE;
    entries[back] = newEntry;
    return true;
}
bool Queue::dequeue()
{
    if (isEmpty())
    {
        return false;
    }
    front = (front + 1) % MAX_QUEUE;
    return true;
}
char Queue::peek()
{
    if (isEmpty())
    {
        cerr << "peeking at an empty array" << endl;
        exit(-1);
    }
    return entries[front + 1];
}

bool isPalindrome(string stringInput)
{
    int length = stringInput.size();
    if (length > MAX_QUEUE || length > MAX_STACK)
    {
        throw length_error("String exceeds queue size");
    }
    Stack myStack; // a new empty stack
    Queue myQueue; // a new empty queue

    // A function which has a loop which pushes each character onto the stack and enqueues each character onto the queue one by one.
    // Pop characters from the stack and dequeue characters from the queue one by one -- if the string is a palindrome, they’re all equal!
    // Adding each character of the string to both the queue and the stack

    for (int i = 0; i < length; i++)
    {
        char nextChar = stringInput[i];
        if (!myQueue.enqueue(nextChar))
        {
            throw range_error("Could not enqueue");
        }
        myStack.push(nextChar);
    }
    while (!myStack.isEmpty())
    {
        char sChar = myStack.peek();
        char qChar = myQueue.peek();
        if (sChar != qChar)
        {
            return false;
        }
        myStack.pop();
        myQueue.dequeue();
    }
    return true;
}

int main()
{
    cout << "Checking for palindromes" << endl;
    cout << "racecar: " << isPalindrome("racecar") << " should be TRUE" << endl;
    cout << "taco: " << isPalindrome("taco") << " should be FALSE" << endl;
    try
    {
        cout << "tattarrattat: " << isPalindrome("tattarrattat") << " should be TRUE" << endl;
    }
    catch (length_error e)
    {
        cerr << "Length error: " << e.what() << endl;
    }
    cout << "burritto: " << isPalindrome("Burritto") << " should be FALSE" << endl;
    return 0;
}

/*SAMPLE OUTPUT
Checking for palindromes
racecar: 1 should be TRUE
taco: 0 should be FALSE
tattarrattat: Length error: String exceeds queue size
burritto: 0 should be FALSE
Process exited with status 0
logout
*/