#include <iostream>
using namespace std;

//creating a node
class Node
{
public:
	int Value;
	Node* next;
};

void InsertAtBeginning(Node*& head, int Value)
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

void InsertAtTheEnd(Node*& head, int Value)
{
	Node* new_node = new Node();
	new_node->Value = Value;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	Node* LastNode = head;
	//cout << "\n";
	while (LastNode->next != NULL)
	{
		//cout << "\n" << LastNode->Value;
		LastNode = LastNode->next;
	}

	LastNode->next = new_node;
	return;
}

void DeleteNode(Node*& head, int Value)
{
	Node* Current = head, *Prev = head;

	//if the first value is equal to Value
	if (Current->Value == Value)
	{
		head = Current->next;
		delete Current;
		return;
	}

	//finding the value place
	while (Current != NULL && Current->Value != Value)
	{
		Prev = Current;
		Current = Current->next;
	}

	//if value is not found
	if (Current == NULL)
		return;

	//next value of the node before current will currents next
	Prev->next = Current->next;
	delete Current;
}

void DeleteFirstNode(Node*& head)
{
	if (head == NULL)
	{
		return;
	}

	Node* FirstNode = head;
	head = FirstNode->next;
	delete FirstNode;
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
	InsertAtBeginning(head, 0);
	cout << "\n";
	PrintNode(head);

	//DeleteNode(head, 0);
	DeleteFirstNode(head);
	DeleteFirstNode(head);
	cout << "\n";
	PrintNode(head);
}

