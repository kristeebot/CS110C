// KristinaHelwing
// CS110C MAX LUTTRELL
// AssignmentEight
// This assigment determines if a string is a palindrome

// You will need to implement your own queue class which supports the queue operations discussed in class and the textbook.
// As with assignment 7, you don’t need to make a templated class -- a simple implementation which deals with char data will suffice.
// I encourage you to implement your own class, only using the code in your textbook as a reference if needed.
// You may implement either an array-based or a link-based queue (unless you’re going for the extra credit, see below).

// Once you have your queue class implemented,
// you can create a function which has a loop which pushes each character onto the stack and enqueues each character onto the queue one by one.
// You can then pop characters from the stack and dequeue characters from the queue one by one -- if the string is a palindrome, they’re all equal!

// Extra Credit
// We discussed an array-based implementation that uses no special data member,
// such as a count of items in the queue or a boolean isFull, to track whether or not the queue is full.
// Rather, it uses an array of MAX_QUEUE+1 entries but only uses MAX_QUEUE of them for queue items.
// You sacrifice one array location by making front the index of the location before the actual front of the queue.
// Thus, the queue is full if front equals (back+1) % (MAX_QUEUE+1) but the queue is empty if front equals back.
// For up to 10% extra credit, implement your queue using this approach.

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_STACK = 100;

// You should be able use your stack class from Assignment 7 without modification.
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
        // cout << "pushing value: " << value << endl;
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
const int MAX_QUEUE = 100;
// a queue of chars
class Queue
{
private:
    // an array to hold queue entries
    char entries[MAX_QUEUE];
    // properties to hold current front,
    // back, and count
    int front;
    int back;
    int count;

public:
    Queue()
    {
        front = 0;
        back = MAX_QUEUE - 1;
        count = 0;
    };
    bool enqueue(char newEntry);
    bool dequeue();
    char peek();
    bool isEmpty()
    {
        return count == 0;
    }
};

bool Queue::enqueue(char newEntry)
{
    if (count >= MAX_QUEUE)
    {
        return false;
    }
    back = (back + 1) % MAX_QUEUE;
    entries[back] = newEntry;
    count++;
    return true;
}
bool Queue::dequeue()
{
    if (isEmpty())
    {
        return false;
    }
    front = (front + 1) % MAX_QUEUE;
    count--;
    return true;
}
char Queue::peek()
{
    if (isEmpty())
    {
        cerr << "peeking at an empty array" << endl;
        exit(-1);
    }
    return entries[front];
}

bool isPalindrome(string stringInput)
{
    Stack myStack; // a new empty stack
    Queue myQueue; // a new empty queue

    // Once you have your queue class implemented, you can create a function which has a loop which pushes each character onto the stack and enqueues each character onto the queue one by one.
    // You can then pop characters from the stack and dequeue characters from the queue one by one -- if the string is a palindrome, they’re all equal!
    // Add each character of the string to both the queue and the stack

    for (int i = 0; i < stringInput.size(); i++)
    {
        char nextChar = stringInput[i]; 
        myQueue.enqueue(nextChar);
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
    /* // compare the queue characters with the stack characters
     charactersAreEqual = true
     while (aQueue is not empty and charactersAreEqual)
     {
         queueFront = aQueue.peekFront()
         stackTop = aStack.peek()
         if (queueFront == stackTop)
         {
             aQueue.dequeue()
             aStack.pop()
         }
         else
             charachtersAreEqual = false
     }
     return charactersAreEqual


     return false;
     */
}

int main()
{
    cout << "racecar: " << isPalindrome("racecar") << "should be true" << endl;
    cout << "taco: " << isPalindrome("taco") << "Should be false" << endl;
    return 0;
}
// For this assignment, implement the algorithm discussed in the textbook section 13.2.2
// which uses a queue and a stack to determine if a string S is a palindrome.
