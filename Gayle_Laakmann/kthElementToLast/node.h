#ifndef node_h
#define node_h

class LinkedList
{

private:
	struct node
	{
		int data;
		node *next;
	};
	node *head;

public:
	LinkedList ();
	node *createNode (int key);	
	void appendNodeBack (int key);
	void printList ();
	void removeDuplicates ();
	void kthElementToLast (int k);
};
#endif