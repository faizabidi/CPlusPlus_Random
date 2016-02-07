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
	//std::cout << "NULL";
	node *newNode = createNode (key);
	//std::cout << "NULL";
	//if tree is empty
	if (head == NULL)
	{
		head = newNode;
		//std::cout << "NULL";
		return;
	}

	//if tree is not empty
	//traverse to the last node in the list
	node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	//std::cout << "NULL";
	//std::cout << temp->data << "\n";
	//std::cout << newNode->data;
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

void LinkedList::ArrangeNodesAroundPivot (int key)
{
	//if list is empty
	if (head == NULL)
	{
		std::cout << "List is empty!\n";
		return;
	}

	//if list is not empty
	node *temp = head;
	//appendNodeBack (99);
	//printList ();
	while (temp != NULL)
	{
		//appendNodeBack (temp1->data);	
		if (temp->data <= key)
		{
			//std::cout << "test ";
			appendNodeFront (temp->data);	
			temp->data = temp->next->data;
			temp->next = temp->next->next;
			delete temp->next;
		}
		/*else if (temp->data > key)
		{
			//std::cout << "test ";
			appendNodeBack (temp->data);
			temp->data = temp->next->data;
			temp->next = temp->next->next;
			delete temp->next;
		}*/
		temp = temp->next;
	}
}