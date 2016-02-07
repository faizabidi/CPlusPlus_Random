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
	void appendNodeBack (const int &key);
	void printList ();
	int SumOfNodes (const LinkedList list1);
};
#endif