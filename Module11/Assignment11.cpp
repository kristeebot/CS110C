// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 111422

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
For up to 10 points extra credit, instead of using the hack, make your own class Patient to contain patient information.
You’ll need to have two member variables for priority and name, overload the < and > operators, and have a way to print out the patient’s name.
You can then make your heap an array of objects of your Patient class instead of an array of strings.
You'll also need to adjust the sample main() above to work with objects of your Patient class.
*/
class Patient
{
public:
    string name;
    int priority;
    Patient(string x, int y)
    {
        name = x;
        priority = y;
    }
};
std::ostream &operator<<(std::ostream &os, Patient const &patient)
{
    return os << patient.name << ": " << patient.priority;
}
bool operator<(const Patient &p1, const Patient &p2)
{
    return p1.priority < p2.priority;
}
bool operator>(const Patient &p1, const Patient &p2)
{
    return p1.priority > p2.priority;
}
bool operator<=(const Patient &p1, const Patient &p2)
{
    return p1.priority <= p2.priority;
}

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
    // The root must have a left child; assume it is the larger child
    int largerChildIndex = getLeftIndex(rootIndex);
    int rightIndex = getRightIndex(rootIndex);

    // now see if there is a right child which is larger than left child
    if (rightIndex < items.size())
    {
        // There's a right child, but is the right child bigger?
        if (items[rightIndex] > items[largerChildIndex])
        {
            largerChildIndex = rightIndex;
        }
    }
    // If item in root is smaller than item in larger child, swap items
    if (items[rootIndex] < items[largerChildIndex])
    {
        iter_swap(items.begin() + rootIndex, items.begin() + largerChildIndex);
    }

    // Transform the semiheap rooted at largerChildIndex into a heap
    heapifyDown(largerChildIndex);

    //     heapRebuild (rootIndex: integer, items: ArrayType, itemCount:integer)
    // if (the root is not a leaf)
    // {
    // // The root must have a left child; assume it is the larger child
    // largerChildIndex = 2 * rootIndex + 1 // Left child index
    // // now see if there is a right child which is larger than left child
    // if (the root has a right child)
    // {
    // rightChildIndex = 2 * rootIndex + 2 // Right child index
    // if (items[rightChildIndex] > items[largerChildIndex])
    // largerChildIndex = rightChildIndex // Larger child index
    // }
    // // If item in root is smaller than item in larger child, swap items
    // if (items[rootIndex] < items[largerChildIndex])
    // {
    // Swap items[rootIndex] and items[largerChildIndex]
    // // Transform the semiheap rooted at largerChildIndex into a heap
    // heapRebuild (largerChildIndex, items, itemCount)
    // }
    // }
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
        if (items[newDataIndex] <= items[parentIndex])
        {
            inPlace = true;
        }
        else
        {
            std::iter_swap(items.begin() + newDataIndex, items.begin() + parentIndex);
            newDataIndex = parentIndex;
        }
    }
}

template <class ItemType>
bool Heap<ItemType>::add(ItemType item)
{
    items.push_back(item);
    heapify();
    return true;
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

int main()
{
    // Create Patient objects and call the constructor with different values
    Patient patientObj1("Bob", 5);
    Patient patientObj2("Mary", 9);
    Patient patientObj3("Max", 1);
    Patient patientObj4("Julio", 3);
    Patient patientObj5("Stacy", 7);
    Patient patientObj6("Paul", 4);
    Patient patientObj7("Reiko", 2);
    Patient patientObj8("Jennifer", 6);
    Patient patientObj9("Chang", 5);

    Heap<Patient> ER;
    ER.add(patientObj1);
    ER.add(patientObj2);
    ER.add(patientObj3);
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    ER.add(patientObj4);
    ER.add(patientObj5);
    ER.add(patientObj6);
    ER.add(patientObj7);
    ER.add(patientObj8);
    ER.add(patientObj9);
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    ER.print();
    while (!ER.isEmpty())
    {
        cout << ER.peekTop() << " will now see the doctor.\n";
        ER.remove();
    }
    return 0;
}
