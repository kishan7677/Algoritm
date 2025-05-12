// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *head = nullptr;
Node *tail = nullptr;
void push_link(int value)
{
    // from back
    // Node *newnode=new Node(value);
    // newnode->next= head;
    // head =newnode;

    // from front
    Node *newnode = new Node(value);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
// from back
void print_link()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool hasCycle()
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    for (int i = 10; i >= 4; i--)
    {
        push_link(i);
    }
    print_link();
    bool output = hasCycle();
    cout << output;

    return 0;
}