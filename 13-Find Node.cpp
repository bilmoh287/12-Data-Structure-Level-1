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
    //PrintListDetails(head);

    Node* N1 = Find(head, 9);
    if (N1 != NULL)
        cout << "\n\nNode Found :-)";
    else
        cout << "\n\nNode Not Found :-(";
    system("pause>0");

}

