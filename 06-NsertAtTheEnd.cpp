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

void InsertAtTheEnd(Node*& head,  int Value)
{
	Node* new_Node = new Node();
	new_Node->Value = Value;
	new_Node->next = NULL;

	if (head == NULL)
	{
		head = new_Node;
		return;
	}
	 
	Node* LastNode = head;
	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}

	LastNode->next = new_Node;
	return;
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

	//InsertAtBegining(head, 1);
	//InsertAtBegining(head, 2);
	//InsertAtBegining(head, 3);
	//InsertAtBegining(head, 4);
	//InsertAtBegining(head, 5);

	PrintNode(head);

	Node* N1 = new Node();
	//if (N1 != NULL)
	//	cout << "\nNode Found :-)";
	//else
	//	cout << "\nNode Not Found :-(";
	
	InsertAtTheEnd(head, 1);
	InsertAtTheEnd(head, 2);
	InsertAtTheEnd(head, 3);
	InsertAtBegining(head, 0);
	cout << "\n";
	PrintNode(head);
}

