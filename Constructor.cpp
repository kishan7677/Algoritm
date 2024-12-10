#include <bits/stdc++.h>
using namespace std;
class person
{
    string name;
    int age;
    int *p;

public:
//default constructor
    person() : name("kishan"), age(24)
    {
    }

//parmetrized constructor
    person(string name, int age , int z)
    {
        this->name = name;
        this->age = age;
        *p=z;
    }
//There is Two types of copy constructor 


//shallow copy constructor
    person(person &obj)
    {
        name = obj.name;
        age = obj.age;
        p = obj.p;
    }

    
//Deep copy constructor
    /*person(person &obj)
    {
        name = obj.name;
        age = obj.age;
        *p = *obj.p;
    }*/

    person(person &&obj)
    {
        name = obj.name;
    }

    person(person &&obj) noexcept : name(std::move(obj.name)), age(obj.age)
    {
        obj.age = 0; // Optional
        cout << "Move Constructor called!" << endl;
    }

public:
    void show()
    {
        cout << "name :" << name << " age :" << age << endl;
    }
};
//there is one more constructor that is move constructor 

int main()
{
    // Write C++ code here
    person p1("Ram", 56,5), p2;
    p2.show();
    p2 = p1;// implicit  copy assignment operator . It is created by default by the compiler.
    person p2 = std::move(p1);
    person p3 = p1;//copy constructor 
    p3.show();
    p1.show();
    p2.show();
    return 0;
}

// there are four types of constructor
// 1.default constructor
// 2.parmetrized constructor
// 3.copy constructor
// 4. move constructor
// https://www.udacity.com/blog/2023/01/exploring-c-rvalue-references.html  here there is detail of c value and r value