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

void LinkedList::appendNodeFront (int key)
{
	node *newNode = createNode(key);

	//if tree is empty
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	//if tree is not empty
	newNode->next = head;
	head = newNode;
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

void LinkedList::ArrangeNodesAroundPivot (int key)
{
	//if list is empty
	if (head == NULL)
	{
		std::cout << "List is empty!\n";
		return;
	}

	
	node *temp = head;
	node *last = head;
	while (last->next != NULL)
		last = last->next;

	while (temp != NULL)
	{
		node *nextNode = temp->next;
		//node *duplicate;
		//node *current = temp;
		if (temp->data < key)
		{	
			temp->next = head;
			head = temp;
			//appendNodeFront (temp->data);
			//temp->data = temp->next->data;
			//duplicate = temp->next;
			//temp->next = temp->next->next;
			//delete duplicate;
		}
		else
		{
			last->next = temp;
			last = temp;
			/*appendNodeBack (temp->data);
			temp->data = temp->next->data;
			duplicate = temp->next;
			temp->next = temp->next->next;
			delete duplicate;*/
		}
		temp = nextNode;
	}
	last->next = NULL;
}