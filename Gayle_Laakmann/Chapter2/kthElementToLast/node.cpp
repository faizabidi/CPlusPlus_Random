#include "node.h"

LinkedList::LinkedList ():head(NULL) {}

LinkedList::node *LinkedList::createNode (int key)
{
	node *newNode = new node;
	newNode->data = key;
	newNode->next = NULL;
	return newNode;
}

void LinkedList::appendNodeBack (int key)
{
	node *newNode = createNode(key);

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

void LinkedList::kthElementToLast (int k)
{
	//if list is empty
	if (head == NULL)
	{
		std::cout << "List is empty!\n";
		return;
	}

	//if list is not empty
	//reach the end of the list and count the items
	node *temp = head;
	unsigned int count = 0;
	while (temp->next != NULL)
	{
		count ++;
		temp = temp->next;
	}

	//we are interested in the (count - k + 1)th element
	unsigned int pos = count - k + 1;

	//reset the temp pointer
	temp = head;

	for (unsigned int i = 0; i < pos; i++)
		temp = temp->next;

	std::cout << k << "th element from back is " << temp->data << std::endl;
}