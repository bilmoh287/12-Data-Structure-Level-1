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

}

