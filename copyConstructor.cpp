#include <bits/stdc++.h>
using namespace std;
class person
{
    string name;
    int age;

public:
    person() : name("kishan"), age(24)
    {
    }
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    person(person &obj)
    {
        name = obj.name;
        age = obj.age;
    }

public:
    void show()
    {
        cout << "name :" << name << " age :" << age << endl;
    }
};

int main()
{
    // Write C++ code here
    person p1("Ram", 56), p2;
    p2.show();
    p2 = p1;
    person p3 = p1;
    p3.show();
    p1.show();
    p2.show();
    return 0;
}