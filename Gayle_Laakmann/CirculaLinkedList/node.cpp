#include "node.h"

CircularLinkedList::CircularLinkedList ():head(NULL) {}

CircularLinkedList::node *CircularLinkedList::createNode (int key)
{
	node *newNode = new node;
	newNode->data = key;
	newNode->next = NULL;
	return newNode;
}

void CircularLinkedList::appendNodeBack (int key)
{
	node *newNode = createNode(key);

	//if tree is empty
	if (head == NULL)
	{
		head = newNode;
		newNode->next = head;
		return;
	}

	//if tree is not empty
	//traverse to the last node in the list that points to the head node
	node *temp = head;
	while (temp->next != head)
		temp = temp->next;

	//make temp point to the new node
	temp->next = newNode;

	//make the new node point to the head
	newNode->next = head;
}

void CircularLinkedList::printList ()
{
	//if tree is empty
	if (head == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//if tree not empty
	node *temp = head;
	
	while (temp->next != head)
	{
		std::cout << temp->data<<"-->";
		temp = temp->next;

	}
	std::cout << temp->next->data << std::endl;
}

void CircularLinkedList::ReturnNodeAtBeginningOfLoop ()
{
	//check where the looping occurs
	//create two pointers, slow moves one step while fast moves two steps
	node *fast = head, *slow = head;

	//if fast becomes NULL or points to NULL, it would mean no loop in the list
	//else, point where fast and slow meet would be the point where looping starts
	
	while (fast != NULL && fast->next != NULL)
	{	
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}


	//if no looping
	if (fast == NULL || fast->next == NULL)
	{
		std::cout << "No loop in the list!\n";
		return;
	}

	//if loop in the list
	std::cout << "Collision point is " << fast->data << std::endl;

	//point slow to head and keep fast at collision point
	//increment both at the same pace now till both don't meet
	//the point at which both meet again is the starting position of the loop

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	std::cout << "Starting point of loop is " << fast->data << std::endl;
}