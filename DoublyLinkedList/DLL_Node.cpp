#include <iostream>
#include "DLL_Node.h"

//initialize the construtor
DLLNode::DLLNode():head(NULL) {}

DLLNode::node *DLLNode::CreateNode (int key)
{
	node *newNode = new node;
	newNode->data = key;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//return a pointer to this new node
	return newNode;
}

void DLLNode::AppendAtBack (int a)
{
	//temp pointer pointing to the head
	node *temp = head;

	//create a new node
	node *newNode = CreateNode (a);

	//if list is empty
	if (temp == NULL)
	{
		//make new node the head
		head = newNode;
		return;
	}

	//else, traverse to the end of the list
	while (temp->next != NULL)
		//reach the end of the list
		temp = temp->next;

	//add the new node
	temp->next = newNode;
	newNode->prev = temp;
}

void DLLNode::AppendInFront (int a)
{
	//create new node
	node *newNode = CreateNode (a);

	//if tree is empty
	if (head == NULL)
	{
		//point head to the new node
		head = newNode;
		return;
	}

	node *temp = head;
	newNode->next = head;
	temp->prev = newNode;
	head = newNode;
}

void DLLNode::PrintList ()
{
	//if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty!\n";
		return;
	}

	node *temp = head;
	while (temp!= NULL)
	{
		std::cout<<temp->data<<"-->";
		temp = temp->next;
	}
	std::cout<<"NULL\n";
}

DLLNode::node *DLLNode::SearchNode (int key)
{
	//check if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty!\n";
		return NULL;
	}

	//else, search the list
	node *temp = head;
	while (temp->data != key && temp!= NULL)
		temp = temp->next;

	if (temp != NULL)
		return temp;
	else
	{
		std::cout <<"Node not found in the tree\n";
		return NULL;
	}
}

void DLLNode::DeleteNode (int key)
{
	//if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty!\n";
		return;
	}

	node *match = SearchNode (key);

	if (match == NULL)
	{
		std::cout<<"Node not found\n";
		return;
	}

	//if first node to be deleted
	if (match == head)
	{
		head = head->next;
		head->prev = NULL;
		delete match;
		return;
	}

	//if last node to be deleted
	if (match->next == NULL)
	{
		match->prev->next = NULL;
		delete match;
		return;
	}

	//if any other node to be deleted
	match->prev->next = match->next;
	match->next->prev = match->prev;
	delete match;
}

void DLLNode::DisplayNodesReverse ()
{
	
	//check if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty\n";
		return;
	}

	//go to the end of the list...
	//...and print using the prev pointer

	node *temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	while (temp != NULL)
	{
		std::cout<<temp->data<<"-->";
		temp = temp->prev;
	}
	std::cout<<"NULL\n";
}

void DLLNode::RemoveDuplicates ()
{
	//check if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty!\n";
		return;
	}

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
				temp->next = duplicate->next;
				//check if it is the last node
				if (duplicate->next != NULL)
					duplicate->next->prev = temp;
				delete duplicate;
			}
			else
				temp = temp->next;
		}
		current = current->next;
	}
}

void DLLNode::ReverseList ()
{
	//if tree is empty
	if (head == NULL)
	{
		std::cout<<"Tree is empty! Nothing to reverese\n";
		return;
	}

	node *current = head;
	node *previous = NULL, *nextt = NULL;

	while (current != NULL)
	{
		nextt = current->next;
		current->next = previous;
		current->prev = nextt;

		previous = current;
		current = nextt;
	}

	//change the head postion
	head = previous;
}

void DLLNode::Swap(node *a, node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void DLLNode::BubbleSortList()
{
	//if no nodes in the list
	if (head == NULL)
	{
		std::cout<<"List is empty!\n";
		return;
	}

	//else, sort the list
	node *current = head;
	node *nextt;
	
	//count number of nodes in the list
	int nodes_count = 0;
	while (current != NULL)
	{
		nodes_count++;
		current = current->next;
	}
	current = head;

	for (size_t i = 0; i < nodes_count; i++)
	{
		nextt = current->next;
		for (size_t j = i + 1; j < nodes_count; j++)
		{
			if (current->data > nextt->data)
				Swap (current, nextt);
			nextt = nextt->next;
		}
		current = current->next;
	}
}

void DLLNode::SelectionSortList ()
{
	if (head == NULL)
	{
		std::cout<<"List is empty!\n";
		return;
	}

	//find the smallest element
	for (node *i = head; i != NULL; i = i->next)
	{
		node *smallest = i;
		for (node *j = i; j != NULL; j = j->next)
		{
			//find the smallest element
			if (smallest->data > j->data)
				smallest = j;
		}
		//swap the values
		Swap (smallest, i);
	}
}