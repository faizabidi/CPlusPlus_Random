#include <vector>
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

bool LinkedList::isPalindrome (LinkedList list)
{
	node *temp = head;

	unsigned int count = 0;

	//push all elements of the list in an array, and count total number of nodes
	std::vector<int> array;

	while (temp != NULL)
	{
		count++;
		array.push_back (temp->data);
		temp = temp->next;
	}

	bool check = true;

	for (unsigned int i = 0, j = array.size() -1; i < j; i++, j--)
	{
		if (array.at(i) != array.at(j))
			check = false;
	}

	return check;
}