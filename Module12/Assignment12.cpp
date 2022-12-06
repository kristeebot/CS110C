// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 112022
// Module 12
// This program uses a BST to sort people and birthdays

//NOTES FOR TA:
//Hacked Binary Node Tree from module 9 to function as a binary search tree
//Sample Output at bottom of main()

#include <iostream>
#include "BinaryNodeTree.h"
#include "Person.h"
using namespace std;

//global variable sub-optimal implementation
string currentSearchMonth;
//dictionary designed to work specifically people vs generic dictionary templated on item type
class PersonDictionary
{
private:
    BinaryNodeTree<PersonItem> tree;

public:
    PersonDictionary() {}

    void addEntry(Person value)
    {
        tree.add(PersonItem(value.name, value));
    }

    PersonItem getEntryByName(Person targetValue)
    {
        return tree.getEntry(PersonItem(targetValue.name, targetValue));
    }

    // remove an entry
    bool removeEntry(Person targetValue)
    {
        return tree.remove(PersonItem(targetValue.name, targetValue));
    }

    // search the dictionary for the birthday for a given name
    string getBirthday(string name)
    {
        // TODO
        return getEntryByName(Person(name, "")).value.birthday;
    }

    static void visitItem(PersonItem &item)
    {
        cout << item.value << endl;
    }

    static void visitMonthItem(PersonItem &item)
    {
        if (item.value.birthday.rfind(currentSearchMonth, 0) == 0)
        {
            cout << item.value << endl;
        }
    }
    // display the name and birthday of every entry in the dictionary
    void displayAllItems()
    {
        tree.inorderTraverse(visitItem);
    }

    // display everyone in the dictionary who was born in a given month
    void displayAllForMonth(string month)
    {
        currentSearchMonth = month + "/";
        tree.inorderTraverse(visitMonthItem);
    }
};

int main()
{
    srand(time(0));

    PersonDictionary myDict;

    Person Kirk("Kirk", "3/22/2031");
    Person Spock("Spock", "3/26/2031");
    Person Bones("Bones", "1/20/2020");
    Person Uhura("Uhura", "12/28/2032");
    Person Scotty("Scotty", "3/3/2020");
    Person Sulu("Sulu", "04/20/2037");

    myDict.addEntry(Kirk);
    myDict.addEntry(Spock);
    myDict.addEntry(Bones);
    myDict.addEntry(Uhura);
    myDict.addEntry(Scotty);
    myDict.addEntry(Sulu);

    myDict.displayAllItems();

    cout << "Entries for March: " << endl;
    myDict.displayAllForMonth("3");

    PersonItem found = myDict.getEntryByName(Kirk);
    cout << "Found: " << found.value << ", should be: " << Kirk << endl;

    // remove all the entries I added:
    myDict.removeEntry(Kirk);
    myDict.removeEntry(Spock);
    myDict.removeEntry(Bones);
    myDict.removeEntry(Uhura);
    myDict.removeEntry(Scotty);
    myDict.removeEntry(Sulu);

    cout << "after removing all items:" << std::endl;

    myDict.displayAllItems();

    return 0;
}

/*
*****SAMPLE OUTPUT********
1 arguments:
argv[0] = '/Users/kristinahelwing/CS110C/Module12/Assignment12'
Added with 1 comparisons
Added with 2 comparisons
Added with 2 comparisons
Added with 3 comparisons
Added with 3 comparisons
Added with 4 comparisons
Person(name: Bones, birthday: 1/20/2020)
Person(name: Kirk, birthday: 3/22/2031)
Person(name: Scotty, birthday: 3/3/2020)
Person(name: Spock, birthday: 3/26/2031)
Person(name: Sulu, birthday: 04/20/2037)
Person(name: Uhura, birthday: 12/28/2032)
Entries for March: 
Person(name: Kirk, birthday: 3/22/2031)
Person(name: Scotty, birthday: 3/3/2020)
Person(name: Spock, birthday: 3/26/2031)
searched with 1 recursions
Found: Person(name: Kirk, birthday: 3/22/2031), should be: Person(name: Kirk, birthday: 3/22/2031)
after removing all items:
Process exited with status 0
*/