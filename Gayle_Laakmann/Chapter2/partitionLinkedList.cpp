#include <iostream>
#include <vector>

class LL
{
private:
	struct node
	{
		int data;
		node *next;
	}*head;

public:
	LL ():head(NULL){};
	node *createNode (int value)
	{	
		node *newNode = new node;
		newNode->data = value;
		newNode->next = NULL;
		return newNode;
	}
	
	void addNodeEnd (int data)
	{
		if (head == NULL)
			head = createNode (data);
		else
		{
			node *newNode = createNode (data);
			node *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	
	void printList ()
	{
		if (head == NULL)
			return;
		node *temp = head;
		while (temp != NULL)
		{
			std::cout << temp->data << "-->";
			temp = temp->next;
		}
		std::cout << "NULL\n";
	}
	
	void partition (int value)
	{
		node *temp = head;
		std::vector<int> left;
		std::vector<int> right;
		while (temp != NULL)
		{
			if (temp->data > value)
				right.push_back (temp->data);
			else if (temp->data < value)
				left.push_back (temp->data);
			temp = temp->next;
		}
		LL obj2;
		for (int i = 0; i < left.size (); i++)
			obj2.addNodeEnd (left.at(i));
		obj2.addNodeEnd (value);
		for (int i = 0; i < right.size (); i++)
			obj2.addNodeEnd (right.at(i));
		obj2.printList ();
	}
};

int main ()
{
	LL obj1;
	obj1.addNodeEnd (1);
	obj1.addNodeEnd (3);
	obj1.addNodeEnd (2);
	obj1.addNodeEnd (5);
	obj1.addNodeEnd (4);
	obj1.addNodeEnd (4);
	obj1.addNodeEnd (8);

	obj1.printList ();
	
	obj1.partition (3);

	return 0;
}