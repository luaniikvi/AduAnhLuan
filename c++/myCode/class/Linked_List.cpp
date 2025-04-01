#include<iostream>
using namespace std;

struct Node
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
Node* insert_head(Node *a, int head)
{
    if(a == NULL){
        a = new Node(head);
        return a;
    }
    Node *temp = new Node(head);
    temp->next = a;
    return temp;    
}

void deleteNode(Node *a, int val)
{
    while (a->next)
    {
        if(a->next->data == val) {
            a->next = a->next->next;
                return;
        }
        a = a->next;
    }
    if(a->next->data == val)
    {
        a->next == NULL;
    }
    
    return;
}
void insert_tail(Node *a,int tail)
{
    if(a == NULL)
    {
        a = new Node(tail);
        return;
    }
    while(a->next != NULL)
    {
        a = a->next;
    }
    Node *temp = new Node(tail);
    a->next = temp;
    return;
}
int main()
{
    Node *a = nullptr;
    for(int i=0 ; i< 10 ; i++)
    {
        a = insert_head(a,i+1);
    }
    insert_tail(a,100);
    deleteNode(a,4);
    printL(a);
    return 0;
}