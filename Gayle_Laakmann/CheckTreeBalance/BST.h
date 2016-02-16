#ifndef BST_h
#define BST_h
#include <iostream>

class BST
{
private:
	struct node
	{
		node *left, *right;
		int data;
	};
	node *root;

	node *createLeaf (int item);

	void addLeafPrivate (int item, node *ptr);

	void printInOrderPrivate (node *ptr);

	int getHeightPrivate (node *ptr);

	bool isBalancedPrivate (node *ptr);

	int checkHeightPrivate (node *ptr);

	bool isBalancedPrivate2 (node *ptr);


public:
	BST ();

	void addLeaf (int item);

	void printInOrder ();

	void getHeight ();

	void checkHeight ();

	bool isBalanced ();

	bool isBalanced2 ();
};

#endif