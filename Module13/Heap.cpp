#include "Heap.h"

template <class ItemType>
bool Heap<ItemType>::add(ItemType item)
{
    items.push_back(item);
    heapify();
    return true;
}

template <class ItemType>
void Heap<ItemType>::print()
{
    for (int i = 0; i < items.size(); i++)
    {
        ItemType item = items[i];
        std::cout << item << endl;
    }
}

template <class ItemType>
bool Heap<ItemType>::isLeaf(int index)
{
    int leftIndex = getLeftIndex(index);
    if (leftIndex >= items.size())
    {
        // If the left index exceeds our total,
        // then we know there's no right index,
        // and thus we're a leaf node.
        return true;
    }
    return false;
}

template <class ItemType>
void Heap<ItemType>::heapifyDown(int rootIndex)
{
    if (isLeaf(rootIndex))
    {
        return;
    }

    int largerChildIndex = getLeftIndex(rootIndex);
    int rightIndex = getRightIndex(rootIndex);
    int smallest = rootIndex;
 
    if (rightIndex < items.size())
    {

        if (items[rightIndex] < items[smallest])
        {
            smallest = rightIndex;
        }
    }

    if (smallest != rootIndex)
        // items[rootIndex] > items[largerChildIndex])
    {
        swapItems(rootIndex, smallest);
        heapifyDown(smallest);
    }

    // Transform the semiheap rooted at largerChildIndex into a heap
    
    // else root is a leaf, so we are done
}

template <class ItemType>
void Heap<ItemType>::heapify()
{
    //  trickle new item up to the right spot in the tree
    int newDataIndex = items.size() - 1;
    if (newDataIndex == 0)
    {
        return;
    }
    bool inPlace = false;
    while ((newDataIndex > 0) && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if (items[newDataIndex] >= items[parentIndex])
        {
            inPlace = true;
        }
        else
        {
            swapItems(newDataIndex, parentIndex);
            newDataIndex = parentIndex;
        }
    }
}

template <class ItemType>
bool Heap<ItemType>::remove()
{
    ItemType item = items.back();
    items.pop_back();
    items[0] = item;
    heapifyDown(0);
    return true;
}

template <class ItemType>
ItemType Heap<ItemType>::peekTop()
{
    return items[0]; // vector will throw exception if empty
}

template class Heap<int>;