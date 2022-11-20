// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 111422

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* EXTRA CREDIT */
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

    if (rightIndex < items.size())
    {

        if (items[rightIndex] > items[largerChildIndex])
        {
            largerChildIndex = rightIndex;
        }
    }

    if (items[rootIndex] < items[largerChildIndex])
    {
        swapItems(rootIndex, largerChildIndex);
    }

    // Transform the semiheap rooted at largerChildIndex into a heap
    heapifyDown(largerChildIndex);
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
            swapItems(newDataIndex, parentIndex);
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
    // Printing out the rest of the heap so I can make
    // sure that items are returned in priority order
    while (!ER.isEmpty())
    {
        cout << ER.peekTop() << " will now see the doctor.\n";
        ER.remove();
    }
    return 0;
}
 /* SAMPLE OUTPUT
Mary: 9 will now see the doctor.
Stacy: 7 will now see the doctor.
Jennifer: 6 will now see the doctor.
Bob: 5 will now see the doctor.
Chang: 5
Paul: 4
Julio: 3
Max: 1
Reiko: 2
Chang: 5 will now see the doctor.
Paul: 4 will now see the doctor.
Julio: 3 will now see the doctor.
Reiko: 2 will now see the doctor.
Max: 1 will now see the doctor.
Process exited with status 0
 */