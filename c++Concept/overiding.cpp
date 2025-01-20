#include <bits/stdc++.h>
using namespace std ;

class base{
    int x = 10;
    int y=20;
    public:
    virtual void fun1(){
        cout<<"base fun1"<<endl;
    }
};
class derived:public base{
    public:
    void fun1(){
        cout<<"derived fun1"<<endl;
    }

};
int main(){
    base *ptrBase;
    derived d;
    ptrBase = &d;
    ptrBase->fun1();
}