#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Implement a circular array-based queue of char entries in C++ based on the class definition below.
// enqueue/dequeue should use member variable count to return false if the queue is full/empty, respectively.
// Once you have implemented all four member functions of the Queue class,

// Global const for maximum queue entries
const int MAX_QUEUE = 3;

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

void check(bool val, string msg)
{
    if (!val)
    {
        cerr << msg << endl;
    }
}

int main()
{
    // write a simple main() function which demonstrates your queue works by enqueuing / dequeueing several elements, and convincing yourself it is working properly.
    // This queue only has room for three items; you should test your enqueue function to make sure it returns false if you try to enqueue when the queue is full.
    Queue myQueue;
    myQueue.enqueue('a');
    myQueue.enqueue('b');
    myQueue.enqueue('c');
    if (myQueue.enqueue('d'))
    {
        cerr << "should not be able to enqueue a fourth element" << endl;
    }
    check(myQueue.peek() == 'a', "should be a");
    myQueue.dequeue();
    check(myQueue.peek() == 'b', "should be b");
    myQueue.dequeue();
    check(myQueue.peek() == 'c', "should be c");
    myQueue.dequeue();
    check(myQueue.isEmpty(), "should be empty");
    // You should test your dequeue function to make sure it returns false if you try to dequeue when the queue is empty.
    check(!myQueue.dequeue(), "should return false if dequeuing while empty");
    return 0;
}
