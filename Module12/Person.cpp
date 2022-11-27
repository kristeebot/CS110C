#include "Person.h"

using namespace std;

Person::Person(string x, int y)
{
    name = x;
    birthday = y;
}

Person::Person(const Person &rhs)
{
    name = rhs.name;
    birthday = rhs.birthday;
}



bool operator==(const Person &lhs, const Person &rhs)
{
    return lhs.name.compare(rhs.name) == 0 && lhs.birthday == rhs.birthday;
}

std::ostream & operator<<(std::ostream &os, const Person &person)
{
    return os << "Person(name: " << person.name << ", age: " << person.birthday << ")";
}
bool operator<(const Person &p1, const Person &p2)
{
    return p1.name < p2.name;
}
bool operator>(const Person &p1, const Person &p2)
{
    return p1.name > p2.name;
}
bool operator<=(const Person &p1, const Person &p2)
{
    return p1.name <= p2.name;
}


bool operator==(const PersonItem &lhs, const PersonItem &rhs)
{
    return lhs.key.compare(rhs.key) == 0;
}
bool operator<(const PersonItem &p1, const PersonItem &p2)
{
    return p1.key.compare(p2.key) == -1;
}

bool operator>(const PersonItem &p1, const PersonItem &p2)
{
    return p1.key.compare(p2.key) == 1;
}

bool operator<=(const PersonItem &p1, const PersonItem &p2)
{
    return p1.key.compare(p2.key) <= 0;
}



