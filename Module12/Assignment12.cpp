// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 112022

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:
    string name;
    int birthday;
    Person(string x, int y)
    {
        name = x;
        birthday = y;
    }
};
template <class ItemType>
class Dictionary
{
public:
    void addEntry(string key, ItemType value)
    {
        // TO DO
    }
    ItemType getEntry(string key)
    {
        return Person("test", 0);
    }
};
int main()
{
    Person gavin("gavin", 12181962);
    Person kristina("kristina", 7181978);
    Person kathy("kathy", 7251952);
    Person reinhard("reinhard", 4161949);
    Dictionary<Person> myDict;
    myDict.addEntry(gavin.name, gavin);
    Person found = myDict.getEntry(gavin.name);
    cout << found.birthday << "should be: " << gavin.birthday << endl;
    return 0;
}