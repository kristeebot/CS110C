
#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 // Heap implementation
template <class ItemType>
class Heap
{
private:
    vector<ItemType> items;
    void heapify();
    void heapifyDown(int rootIndex);
    bool isLeaf(int index);
    int getLeftIndex(int index)
    {
        return index * 2 + 1;
    }
    int getRightIndex(int index)
    {
        return index * 2 + 2;
    }
    void swapItems(int leftIndex, int rightIndex)
    {
        ItemType item = items[rightIndex];
        items[rightIndex] = items[leftIndex];
        items[leftIndex] = item;
    }

public:
    bool add(ItemType item);
    bool remove();
    ItemType peekTop();
    void print();
    bool isEmpty()
    {
        return items.empty();
    }
};

#endif // HEAP_H_
