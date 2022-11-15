#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// Write a C++ function lefties which returns the number of nodes which have a left child in a link-based binary tree.

// You must use the BinaryNode class below for each node in the tree.  You cannot assume any other classes or functions are available.
// You can assume that for any given node, leftChildPtr is equal to nullptr if the node has no left child,
// and is a pointer to a valid node if it does in fact have a left child.

class BinaryNode

{

public:
    int item;

    BinaryNode *leftChildPtr;

    BinaryNode *rightChildPtr;
};

// You can assume that your function is called with parameter nodePtr pointing to a valid binary tree with one or more nodes.

// nodePtr: pointer to the root of tree we need to search

int lefties(BinaryNode *nodePtr)
{
    if (nodePtr == 0)
    {
        return 0;
    }
    int myCount = 0;
    if (nodePtr->leftChildPtr) {
        myCount = 1;
    }
    return myCount + lefties(nodePtr->leftChildPtr) + lefties(nodePtr->rightChildPtr);
}


int main()
{
    BinaryNode *root = new BinaryNode();
    root->item = -1;
    BinaryNode *leftOne = new BinaryNode();
    BinaryNode *leftTwo = new BinaryNode();
    BinaryNode *leftThree = new BinaryNode();
    BinaryNode *leftFour = new BinaryNode();
    BinaryNode *rightOne = new BinaryNode();
    BinaryNode *rightTwo = new BinaryNode();
    BinaryNode *rightThree = new BinaryNode();

    root->leftChildPtr = leftOne;
    root->rightChildPtr = rightOne;

    leftOne->leftChildPtr = leftTwo;
    leftOne->rightChildPtr = rightTwo;

    leftTwo->leftChildPtr = NULL;
    leftTwo->rightChildPtr = NULL;

    leftThree->leftChildPtr = NULL;
    leftThree->rightChildPtr = NULL;

    rightOne->leftChildPtr = leftThree;
    rightOne->rightChildPtr = NULL;

    rightTwo->leftChildPtr = NULL;
    rightTwo->rightChildPtr = rightThree;

    rightThree->leftChildPtr = leftFour;
    rightThree->rightChildPtr = NULL;

    int leftNodeCount = ::lefties(root);
    cout << "Lefties: " << leftNodeCount << std::endl;

    return 0;
}
