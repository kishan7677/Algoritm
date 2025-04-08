#include<bits/stdc++.h>
using namespace std;
int x=0,y=0;
queue<int> squeue;
mutex mtx;
condition_variable cv ;
// void threadFunc(int id){
    
//     if (id == 1){
//         for(int i=0;i<100;i++){
//             x=x+1;
        
//            arr[i]=x;
//     }
//     }
//      else if(id ==2){
//         for(int i=0;i<5;i++){
//         cout <<"thread2 x:"<<arr[i]<<endl;
//         }
//     }

// }
void populate(){
    for(int i=0;i<100;i++){
        std::lock_guard<std::mutex> lock(mtx);
        x=(x+i)*10;
        cout << "pushed " << x << endl;
        squeue.push(x);
        cv.notify_one();
        }
}
void print(){
    while(true){
        unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !squeue.empty(); });
        int temp = squeue.front();
        squeue.pop();
        cout << "popped "<<temp<<endl;
        mtx.unlock();
        if(temp==100) break;
    }
}
int main(){
    std::thread thread1(populate);
    std::thread thread2(print);
    thread1.join();
    thread2.join();
}