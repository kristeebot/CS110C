// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 112022

#include <iostream>
#include "BinaryNodeTree.h"
#include "Person.h"

using namespace std;

template <class ItemType>
class Dictionary
{
private:
    BinaryNodeTree<ItemType> tree;

public:
    Dictionary() {}

    void addEntry(ItemType value)
    {
        tree.add(value);
    }

    ItemType getEntry(ItemType targetValue)
    {
        return tree.getEntry(targetValue);
    }
};

int main()
{
    Person gavin("gavin", 12181962);
    Person kristina("kristina", 7181978);
    Person kathy("kathy", 7251952);
    Person reinhard("reinhard", 4161949);

    Dictionary<PersonItem> myDict;
    myDict.addEntry(PersonItem(gavin.name, gavin));
    myDict.addEntry(PersonItem(kristina.name, kristina));
    myDict.addEntry(PersonItem(kathy.name, kathy));
    myDict.addEntry(PersonItem(reinhard.name, reinhard));

    PersonItem found = myDict.getEntry(PersonItem(gavin.name));
    cout << "Found: " << found.value << ", should be: " << gavin << endl;

    return 0;
}