//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// CS110C
// Prof Max Luttrel
// Kristina Helwing
// 101022

/** Implementation file for the class SortedListHasA.
 @file SortedListHasA.cpp */

#include "SortedListHasA.h" // Header file
#include "LinkedList.h"
#include <cassert>
#include <cmath>

template <class ItemType>
SortedListHasA<ItemType>::SortedListHasA(bool descending)
{
   listPtr = new LinkedList<ItemType>();
   this->descending = descending;
} // end default constructor

template <class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType> &sList)
{
   // First, create our own list
   listPtr = new LinkedList<ItemType>();
   this->descending = sList.descending;

   // Then add items to it using public methods
   for (int position = 1; position <= sList.getLength(); position++)
   {
      listPtr->insert(position, sList.getEntry(position));
   } // end for
} // end copy constructor

template <class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
   clear();
} // end destructor

template <class ItemType>
void SortedListHasA<ItemType>::insertSorted(const ItemType &newEntry)
{
   int newPosition = fabs(getPosition(newEntry));
   listPtr->insert(newPosition, newEntry);
} // end insertSorted

template <class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType &anEntry)
{
   bool ableToRemove = false;
   if (!isEmpty())
   {
      int position = getPosition(anEntry);

      ableToRemove = position > 0;
      if (ableToRemove)
      {
         ableToRemove = listPtr->remove(position);
      } // end if
   }    // end if

   return ableToRemove;
} // end removeSorted

template <class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType &anEntry) const
{

   for (int i = 1; i <= listPtr->getLength(); i++)
   {
      ItemType currentItem = listPtr->getEntry(i);
      if (currentItem == anEntry)
      {
         return i;
      }
      else if (descending ? currentItem < anEntry : currentItem > anEntry)
      {
         return -i;
      }
   }
   return -(listPtr->getLength() + 1);

} // end getPosition

//=====================
// List operations:

template <class ItemType>
bool SortedListHasA<ItemType>::remove(int position)
{
   return listPtr->remove(position);
} // end remove

template <class ItemType>
void SortedListHasA<ItemType>::clear()
{
   listPtr->clear();
} // end clear

template <class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const
{
   return listPtr->getEntry(position);
} // end getEntry

template <class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const
{
   return listPtr->isEmpty();
} // end isEmpty

template <class ItemType>
int SortedListHasA<ItemType>::getLength() const
{
   return listPtr->getLength();
} // end getLength

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use in this .cpp file.
// (just strings for now, add more types if desired)
template class SortedListHasA<std::string>;
template class SortedListHasA<int>;
