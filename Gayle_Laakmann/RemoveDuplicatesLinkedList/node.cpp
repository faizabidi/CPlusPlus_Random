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

void LinkedList::removeDuplicates ()
{
	//if tree is empty
 	if (head == NULL || head->next == NULL)
 	{
 		std::cout << "Nothing to remove!\n";
 		return;
 	}

 	//if tree is not empty
 	node *current = head;

 	while (current != NULL)
 	{
 		node *temp = current;
 		node *duplicate;

 		while (temp->next != NULL)
 		{
 			if (current->data == temp->next->data)
 			{
 				duplicate = temp->next;
 				temp->next = temp->next->next;
 				delete duplicate;
 			}
 			else
	 			temp = temp->next;
 		}
 		current = current->next;
 	}
}