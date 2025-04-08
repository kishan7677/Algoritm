#include<bits/stdc++.h>
using namespace std;

void fun(int i, string str ){
    i++;
}

int main(){
    thread t(fun,0,"thread1");
    thread j(fun,0,"thread2");
    t.join();
    j.join();
}