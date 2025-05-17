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
    while(ll)
    {
        cout << ll->data << ' ';
        ll = ll->next;
    }
}
void insert_head(Node* &a, int head)
{
    if(a == NULL){
        a = new Node(head);
        return;
    }
    Node *temp = new Node(head);
    temp->next = a;
    a = temp;    
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
void insert_tail(Node*& a,int tail)
{
    if(a == NULL)
    {
        a = new Node(tail);
        return;
    }
    Node* head = a;
    while(a->next != NULL)
        a = a->next;
    a->next = new Node(tail);
    a = head;
}

void sortList(Node* &head) {
    if (head == NULL || head->next == NULL) return;
    
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void sortListDescending(Node* &head) {
    if (head == NULL || head->next == NULL) return;
    
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data < ptr1->next->data) {  // Changed > to < for descending order
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main()
{
    Node *a = __null;
    for(int i= 1 ; i<=3; i++)
        insert_tail(a,i);

    printL(a);
    
    return 0;
}