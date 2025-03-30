#include<iostream>
using namespace std;

struct  Node
{
    int data;
    Node *next;
    Node(){};
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void printL(Node *ll)
{
    //if(ll == 0) return;
    while(ll->next)
    {
        cout << ll->data << ' ';
        ll = ll->next;
    } cout << ll->data;
}
void printL(Node a)
{
    cout << a.data;
    return;
}
Node *insert_head(Node *a, int head)
{
    if(a == nullptr){
        a = new Node(head);
        return a;
    }

    Node *temp = new Node(head);
    temp->next = a;
    return temp;    
}
int main()
{
    Node *a = nullptr;
    for(int i=0 ; i< 10 ; i++)
    {
        a = insert_head(a,i+1);
    }
    printL(*&*&*&*&*&*&*&*&*&*&*a);
    cout << endl;
    printL(a);
    return 0;
}