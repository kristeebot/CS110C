//CS110C
//KristinaHelwing
//091222
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void displayList(ListInterface<string> *listPtr)
{
   cout << "The list contains " << endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
   cout << endl
        << endl;
} // end displayList

void listTester()
{
   ListInterface<string> *listPtr = new LinkedList<string>();
   cout << "Testing the Link-Based List:" << endl;
   string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   for (int i = 0; i < 6; i++)
   {
      if (listPtr->insert(i + 1, data[i]))
         cout << "Inserted " << listPtr->getEntry(i + 1)
              << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1)
              << endl;
   } // end for

   displayList(listPtr);

   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;

   cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
   cout << "After replacing the entry at position 3 with XXX: ";
   listPtr->setEntry(3, "XXX");
   displayList(listPtr);

   listPtr->reverse();
   cout << "here is the reversed list" <<endl;
   displayList(listPtr);
   listPtr->reverse();
   cout << "removing item 3" << endl;
   listPtr->remove(3);
   listPtr->reverse();
   cout << "reversed list without item 3" << endl;
   displayList(listPtr);
   // remove the last node:
   listPtr->remove(5);
   displayList(listPtr);
} // end listTester

int main()
{
   listTester();
   return 0;
} // end main

/* KRISTINA'S SAMPLE OUTPUT:
Testing the Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains 
one two three four five six 

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains 
one two XXX four five six 

here is the reversed list
The list contains 
six five four XXX two one 

removing item 3
reversed list without item 3
The list contains 
six five four two one 

Process exited with status 0
logout
*/


/***** EXPECTED OUTPUT WITH CORRECT INSERT FUNCTION
Testing the Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains
one two three four five six

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains
one two XXX four five six */


