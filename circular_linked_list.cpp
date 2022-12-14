#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtHead(Node*& head, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void deleteAthead(Node*& head)
{
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    Node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(Node*& head, int pos)
{
    if(pos == 1)
    {
        deleteAthead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count != pos-1)
    {
        temp = temp->next;
        count++;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void display(Node*& head)
{
    if(head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << temp->val;

        if(temp->next != head)
            cout << " -> ";
        temp = temp->next;
    }
    while(temp != head);
    cout << endl;
}

int main(void)
{
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    insertAtHead(head, 777);
    insertAtHead(head, 999);

    display(head);

    deletion(head, 2);

    display(head);

    deletion(head, 1);

    display(head);
}
