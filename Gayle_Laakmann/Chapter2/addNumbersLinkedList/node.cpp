#include "node.h"
#include <math.h>

LinkedList::LinkedList ():head(NULL) {}

LinkedList::node *LinkedList::createNode (int key)
{
	node *newNode = new node;
	newNode->data = key;
	newNode->next = NULL;
	return newNode;
}

//add node at the end of the list
void LinkedList::appendNodeBack (const int &key)
{
	node *newNode = createNode (key);

	//if tree is empty
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	//if tree is not empty
	//traverse to the last node in the list
	node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

void LinkedList::printList ()
{
	//if tree is empty
	if (head == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//if tree not empty
	node *temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data<<"-->";
		temp = temp->next;

	}
	std::cout << "NULL\n";
}

int LinkedList::SumOfNodes (const LinkedList list1)
{	
	//find the length of the list
	node *temp = head;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	//re-assign temp to head
	temp = head;

	//calculate the sum
	unsigned int sum = 0;

	for (unsigned int i = 1; i < pow (10, count); i = i * 10)
	{
		sum = sum + temp->data * i;
		temp = temp->next;
	}

	return sum;
}