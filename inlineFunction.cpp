#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class inlineFun{
public:
inline void callme(){
    cout<<"Hello, World!"<<endl;
}
};
int main(){
    inlineFun obj;
    obj.callme();

}