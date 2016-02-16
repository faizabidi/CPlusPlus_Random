/* 
Time and space complexity is O (n)
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

void BST::checkHeight () { std::cout << checkHeightPrivate (root); } 

int BST::checkHeightPrivate (node *ptr)
{
	if (ptr == NULL)
		return 0;

	//check if left sub trees are balanced
	int lheight = checkHeightPrivate (ptr->left);
	if (lheight == -1)
		return -1;

	int rheight = checkHeightPrivate (ptr->right);
	if (rheight == -1)
		return -1;

	int heightdiff = std::abs (lheight - rheight);
	if (heightdiff > 1)
		return -1;
	else
		return 1 + std::max (lheight, rheight);
}

bool BST::isBalanced2 () { return isBalancedPrivate2 (root); }

bool BST::isBalancedPrivate2 (node *ptr)
{
	if (checkHeightPrivate (ptr) == -1)
		return false;
	else
		return true;
}