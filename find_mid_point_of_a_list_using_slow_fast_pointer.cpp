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

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    if(head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->val;
        if(head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int findMid(Node*& head)
{
    // Case 1: Head Empty
    if(head == NULL)
        return -1;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

int main(void)
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    display(head);

    int mid = findMid(head);

    cout << "Mid: " << mid << endl;
}
