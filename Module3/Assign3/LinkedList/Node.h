//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h
    Listing 4-1 */
#ifndef _NODE
#define _NODE

template <class ItemType>
class Node
{
private:
   ItemType item;        // A data item
   Node<ItemType> *next; // Pointer to next node
   // TODO
   Node<ItemType> *previous; // Pointer to previous node

public:
   Node();
   Node(const ItemType &anItem);
   Node(const ItemType &anItem, Node<ItemType> *nextNodePtr, Node<ItemType> *previousNodePtr);
   // TODO - Node.h: add member variable Node* prev which points to previous node in linked list (or NULL for the first node in list)
   Node(Node<ItemType> *previousNode);
   void setItem(const ItemType &anItem);
   void setNext(Node<ItemType> *nextNodePtr);
   // TODO - Node.h: add setPrev(), getPrev() prototypes, these are setter and getter functions for prev pointer
   void setPrev(Node<ItemType> *previousNodePtr);
   Node<ItemType> *getPrev() const;
   ItemType getItem() const;
   Node<ItemType> *getNext() const;
}; // end Node

#endif