#ifndef node_h
#define node_h

class CircularLinkedList
{

private:
	struct node
	{
		int data;
		node *next;
	};
	node *head;

public:
	CircularLinkedList ();
	node *createNode (int key);	
	void appendNodeBack (int key);
	void printList ();
	void ReturnNodeAtBeginningOfLoop ();
};
#endif