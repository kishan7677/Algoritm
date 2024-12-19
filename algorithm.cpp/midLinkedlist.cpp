#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data ;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

int Linklength(Node* head){
    int len=0;
          while(head){
            head = head->next ;
            len++;
          }
          return len ;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
   int len= Linklength(head);
   cout<<len;

}
