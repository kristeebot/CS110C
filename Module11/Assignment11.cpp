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
public:           // Access specifier
    string name;  // Attribute
    int priority; // Attribute
    Patient(string x, int y)
    { // Constructor with parameters
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
bool operator<=(const Patient &p1, const Patient &p2)
{
    return p1.priority <= p2.priority;
}
template <class ItemType>

// heap is going to need an array (or vector) of items

class Heap
{
private:
    vector<ItemType> items;
    void heapify();

public:
    bool add(ItemType item);
    bool remove();
    ItemType peekTop();
};
template <class ItemType>
void Heap<ItemType>::heapify()
{
    // trickle up swapping all the way to the root, if necessary
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
            std::iter_swap(items.begin()+newDataIndex,items.begin()+parentIndex);
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

    cout << patientObj1 << endl;

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
    return 0;
}
