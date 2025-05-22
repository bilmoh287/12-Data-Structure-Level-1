#include <iostream>
using namespace std;

// Creating a node
class Node

{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int Value)
{
    Node* new_node = new Node();
    new_node->next = head;
    new_node->value = Value;
    new_node->prev = NULL;

    if (head != NULL)
    {
        head->prev = new_node;
    }

    head = new_node;
}

Node* Find(Node* head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void DeleteNode(Node*& head, Node*& NodeToDelete)
{
    if (head == NULL || NodeToDelete == NULL)
    {
        return;
    }
    if (head == NodeToDelete)
    {
        head = NodeToDelete->next;
    }
    if (NodeToDelete->next != NULL)
    {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }
    if (NodeToDelete->prev != NULL)
    {
        NodeToDelete->prev->next = NodeToDelete->next;
    }
    delete NodeToDelete;
}

void DeleteFirstNode(Node*& head)
{
    if (head == NULL)
    {
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

void PrintNodeDetails(Node* head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}

void InsertAtTheEnd(Node*& head, int Value)
{
    Node* new_nod = new Node();
    new_nod->next = NULL;
    new_nod->value = Value;

    if (head == NULL)
    {
        new_nod->prev = NULL;
        head = new_nod;
    }
    else 
    {
        Node* Current = head;
        while (Current->next != NULL)
        {
            Current = Current->next;
        }
        Current->next = new_nod;
        new_nod->prev = Current;
    }
}

// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    //InsertAtBeginning(head, 0);
    //Node* N1 = Find(head, 5);
    DeleteFirstNode(head);

    cout << "\n\n\nLinked List Contenet after Deletion:\n";
    PrintList(head);
    PrintListDetails(head);

}

