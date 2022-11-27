#ifndef _PERSON_CLASS
#define _PERSON_CLASS

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int birthday;
    Person() : name(""), birthday(0) {}
    Person(string x, int y);
    Person(const Person &rhs);
};

bool operator==(const Person &lhs, const Person &rhs);
std::ostream &operator<<(std::ostream &os, const Person &person);
bool operator<(const Person &p1, const Person &p2);
bool operator>(const Person &p1, const Person &p2);
bool operator<=(const Person &p1, const Person &p2);


class PersonItem {
    public:
    string key;
    Person value;
    PersonItem() {
        key = "";
        value = Person("", 0);
    }
    PersonItem(string key, Person value) {
        this->key = key;
        this->value = value;
    }
    PersonItem(string key) {
        this->key = key;
    }
};

bool operator==(const PersonItem &lhs, const PersonItem &rhs);
bool operator<(const PersonItem &p1, const PersonItem &p2);
bool operator>(const PersonItem &p1, const PersonItem &p2);
bool operator<=(const PersonItem &p1, const PersonItem &p2);


#endif // _PERSON_CLASS
