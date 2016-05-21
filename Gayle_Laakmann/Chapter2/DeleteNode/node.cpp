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

LinkedList::node *LinkedList::search (int key)
{
	if (head == NULL)
	{
		std::cout << "List is empty!\n";
		return NULL;
	}

	node *temp = head;
	node *foundNode;

	while (temp != NULL)
	{
		if (temp->data == key)
		{
			foundNode = temp;
			break;
		}
		else 
			temp = temp->next;
	}
	return foundNode;
}

void LinkedList::deleteKey (int key)
{
	node *temp = search (key);
	temp->data = temp->next->data;
	node *deletePtr = temp->next->next;
	temp->next = temp->next->next;
	delete deletePtr;

	printList();
}