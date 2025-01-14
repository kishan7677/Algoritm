#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data ;
    Node* next;

   Node (int data){
     this->data =data ;
     next = NULL;
   } 
};

void PrintLink(Node *head){
  while (head){
    cout<<head->data<<" ";
    head = head->next ;
  }
  cout<<endl ;
}
Node* revese(Node *head){
  if (head == NULL){
    return NULL;
  }
  Node *current=head,*prev=NULL,*newnext=NULL;
  while (current){
    newnext = current->next ;
    current->next = prev ;
    prev= current;
    current = newnext ;
  }
  return prev ;
}

int main(){
    Node *head= new Node(10);
    Node *temp = head;
    for(int i=2;i<10;i++){
        temp->next=new Node(10*i);
        temp= temp->next;
      
    }
    //PrintLink(head);
    //PrintLink(head);
    Node *rev=revese(head);
    PrintLink(rev);
}