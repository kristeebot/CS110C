// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 112022

#include <iostream>
#include "BinaryNodeTree.h"
#include "Person.h"
#include <cstdlib>
#include <time.h>

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

// For testing, some code from googling:
string gen_random(const int len)
{
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

PersonItem makeRandomPerson()
{
    string name = gen_random(15);
    int birthday = rand();
    Person p(name, birthday);
    return PersonItem(p.name, p);
}

int main()
{
    srand(time(0));

    Dictionary<PersonItem> myDict;

    Person gavin("gavin", 12181962);
    Person kristina("kristina", 7181978);
    Person kathy("kathy", 7251952);
    Person reinhard("reinhard", 4161949);
    myDict.addEntry(PersonItem(gavin.name, gavin));
    myDict.addEntry(PersonItem(kristina.name, kristina));
    myDict.addEntry(PersonItem(kathy.name, kathy));
    myDict.addEntry(PersonItem(reinhard.name, reinhard));


    // add a bunch of random people so I can make sure we're really O(logN)
    for (int i = 0; i < 10000; i++)
    {
        myDict.addEntry(makeRandomPerson());
    }

    PersonItem found = myDict.getEntry(PersonItem(reinhard.name));
    cout << "Found: " << found.value << ", should be: " << reinhard << endl;

    return 0;
}