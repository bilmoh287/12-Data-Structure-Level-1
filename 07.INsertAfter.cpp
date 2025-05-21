#include <iostream>
using namespace std;

//creating a node
class Node
{
public:
	int Value;
	Node* next;
};

void InsertAtBegining(Node* &head, int Value)
{
	//allocate memory to a new node
	Node* new_node = new Node();

	//inser the data
	new_node->Value = Value;
	new_node->next = head;

	//move head to new node
	head = new_node;
}

Node* Find(Node* head, int Value)
{
	while (head != NULL)
	{
		if (head->Value == Value)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void InsertAfter(Node* &Prev_Node, int Value)
{
	if (Prev_Node == NULL)
	{
		cout << "\nPrev_Node Cannot be NULL!";
		return;
	}

	//new node to prev nodes next node, and prev node to the new node.
	Node* new_node = new Node();
	new_node->Value = Value;
	new_node->next = Prev_Node->next;
	Prev_Node->next = new_node;
}

void PrintNode(Node* head)
{
	while (head != NULL)
	{
		cout << head->Value << " ";
		head = head->next;
	}
}

int main()
{
	Node* head = NULL;

	InsertAtBegining(head, 1);
	InsertAtBegining(head, 2);
	InsertAtBegining(head, 3);
	InsertAtBegining(head, 4);
	InsertAtBegining(head, 5);

	PrintNode(head);

	Node* N1 = Find(head, 2);
	//if (N1 != NULL)
	//	cout << "\nNode Found :-)";
	//else
	//	cout << "\nNode Not Found :-(";
	
	InsertAfter(N1, 10);
	cout << "\n";
	PrintNode(head);
}

