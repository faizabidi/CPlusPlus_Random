/* 
Time complexity is O (nxn).
*/

#include "BST.h"

BST::BST ():root(NULL) {}

BST::node *BST::createLeaf (int item)
{
	node *newNode = new node;
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void BST::addLeaf (int item) { addLeafPrivate (item, root); }

void BST::addLeafPrivate (int item, node *ptr)
{
	if (ptr == NULL)
	{
		root = createLeaf (item);
		return;
	}
	if (item > ptr->data)
	{
		//traverse to the right most
		if (ptr->right != NULL)
		{
			addLeafPrivate (item, ptr->right);
			return;
		}

		ptr->right = createLeaf (item);
		return;
	}
	if (item <= ptr->data)
	{
		//traverse to the left most
		if (ptr->left != NULL)
		{
			addLeafPrivate (item, ptr->left);
			return;
		}

		ptr->left = createLeaf (item);
		return;
	}
}

void BST::printInOrder () { printInOrderPrivate (root); }

//left, root, right
void BST::printInOrderPrivate (node *ptr)
{
	if (ptr == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	if (ptr->left != NULL)
		//traverse to the left most end
		printInOrderPrivate (ptr->left);
	std::cout << ptr->data << " ";
	if (ptr->right != NULL)
		printInOrderPrivate (ptr->right);
}

void BST::getHeight () { std::cout << getHeightPrivate (root); }

int BST::getHeightPrivate (node *ptr)
{
	unsigned int height;

	if (ptr == NULL)
		return 0;
	else
		return 1 + std::max (getHeightPrivate (ptr->left), getHeightPrivate (ptr->right));
}

bool BST::isBalanced () { return isBalancedPrivate (root); }

bool BST::isBalancedPrivate (node *ptr)
{
	if (ptr == NULL)
		return true;
	
	int heightdiff = std::abs ( getHeightPrivate (ptr->left) - getHeightPrivate (ptr->right) );
		
	if (heightdiff >  1)
		return false;
	else
		return isBalancedPrivate (ptr->left) && isBalancedPrivate (ptr->right);
}