#include <iostream>
#include <list>
#include "BST.h"

//initialize root with NULL
BST::BST() { root = NULL; }

//CreateLeaf function returns a pointer pointing to the new leaf created
BST::node *BST::CreateLeaf (int key) 
{
	node *newNode = new node;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	//return pointer pointing to this newly created node
	return newNode;
}

//function to call the private function to create a leaf
//in the main function, only worry about the value, and not the location of root
void BST::AddLeaf (int key)
{
	//root is a private member
	AddLeafPrivate (key, root);
}

void BST::AddLeafPrivate (int key, node *Ptr)
{
	//check if tree is empty
	if (Ptr == NULL)
	{
		root = CreateLeaf (key);
		return;
	}
	//if tree not empty and key is less than the root value
	if (key <= Ptr->key)
	{
		//traverse down the left node since there is another node on the left bottom
		if (Ptr->left != NULL)
		{
			AddLeafPrivate (key, Ptr->left);
			return;
		}
		//when it reaches the last node on the left
		//add the node to the tree
		Ptr->left = CreateLeaf (key);
		
		return;
	}
	
	//if key is greater than the root value
	if (key > Ptr->key)
	{
		//traverse down the right node since there is another node on the right bottom
		if (Ptr->right != NULL)
		{
			AddLeafPrivate (key, Ptr->right);
			return;
		}
		//when it reaches the last node on the right
		//add the node to the tree
		Ptr->right = CreateLeaf (key);
	
		return;
	}
}

//function to call the private member function PrintInOrderPrivate
void BST::PrintInOrder() { PrintInOrderPrivate (root); }

//function to print the tree
void BST::PrintInOrderPrivate (node *Ptr)
{
	//check if tree is empty
	if (Ptr == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//if tree is not empty
	//uncomment the below line for Pre-Order Traversal
	//std::cout << Ptr->key<<" ";
		
	//check if it is possible to go further left
	if (Ptr->left != NULL)
		PrintInOrderPrivate (Ptr->left);

		
	//print root value
	std::cout << Ptr->key<<" ";
		
	//check if it is possible to go further right
	if (Ptr->right != NULL)
		PrintInOrderPrivate (Ptr->right);
		
	//uncomment the below line while commenting the other two for Post-Order Traversal
	//std::cout << Ptr->key<<" ";
}

//search function to call the private serach function
BST::node *BST::SearchNode (int key) { return SearchNodePrivate (key, root); }

//private search function to find a given node
BST::node *BST::SearchNodePrivate (int key, node *Ptr)
{
	//check if tree is empty
	if (Ptr == NULL)
	{
		std::cout << "Tree is empty!\n";
		return NULL;
	}

	//if tree is not empty
	if (Ptr != NULL)
	{
		if (key == Ptr->key)
			return Ptr;
		//if key is smaller than the root
		else if (key < Ptr->key)
			return SearchNodePrivate(key, Ptr->left);
		//if key is greater than the root
		else
			return SearchNodePrivate(key, Ptr->right);
	}
	//if key not found
	else
		return NULL;
}

//function to print the children of each node in the tree with value = key
void BST::PrintChildren (int key)
{
	//if tree is empty
	if (root == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//*ptr will point to the node where key is found
	node *Ptr = SearchNode (key);

	if (Ptr != NULL)
	{
		std::cout << "Parent node is " << Ptr->key << std::endl;
		Ptr->left == NULL ? std::cout << "Left child is NULL\n" : std::cout << "Left child is " << Ptr->left->key << std::endl;
		Ptr->right == NULL ? std::cout << "Right child is NULL\n" : std::cout << "Right child is " << Ptr->right->key << std::endl;
		std::cout << std::endl;
		return;
	}
	//if key not found
	std::cout << key << " is not in the tree\n";
}

//public function to call private function to find the smallest node
int BST::SmallestNode () { return SmallestNodePrivate (root); }

//private function to find the smallest node
//smallest node in a BST would be extreme left
int BST::SmallestNodePrivate (node *Ptr)
{
	if (Ptr == NULL)
	{
		std::cout << "\nTree is empty\n";
		return -99999;
	}
	//check left pointers recursively
	if (Ptr->left != NULL)
		return SmallestNodePrivate (Ptr->left);
	
	//when you reach the left most node, return its value
	return Ptr->key;
}

//pubiic function calling the private function to delete a node
void BST::RemoveNode (int key) { RemoveNodePrivate (key, root); }

//function to remove a node from a tree
void BST::RemoveNodePrivate (int key, node *parent)
{
	//empty tree
	if (parent == NULL)
	{
		std::cout << "Nothing to delete. Tree is empty!\n";
		return;
	}
 
	if (parent != NULL)
	{
		if (key == parent->key)
		{
			RemoveRootMatch ();
			return;
		}
		
		//if key is found on the left sub tree
		if (key < parent->key && parent->left != NULL)
		{
			parent->left->key == key ? RemoveMatch (parent, parent->left, true) : RemoveNodePrivate (key, parent->left);
			return;
		}
		
		//if key is found on the right sub tree
		if (key > parent->key && parent->right != NULL)
		{
			parent->right->key == key ? RemoveMatch (parent, parent->right, false) : RemoveNodePrivate (key, parent->right);
			return;
		}

		std::cout << "Node not found in the tree\n";
	}
}

//function to delete the root node
void BST::RemoveRootMatch()
{
	//if tree is empty
	if  (root == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//if tree is not empty
	if (root != NULL)
	{
		node *DeletePtr = root;
		int rootKey = root->key;
		int smallest;

		//case when root has no children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete DeletePtr;
			return;
		}
		
		//case when root has no left but right child
		if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			DeletePtr->right = NULL;
			delete DeletePtr;
			std::cout << "Root node " << rootKey << " deleted\n";
			return;
		}
		
		//case when root has no right but left child
		if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			DeletePtr->left = NULL;
			delete DeletePtr;
			std::cout << "Root node " << rootKey << " deleted\n";
			return;
		}

		//case when root has both left and right children
		if (root->left != NULL && root->right != NULL) 
		{
			//find the smallest element in the right sub tree
			smallest = SmallestNodePrivate (root->right);
			//delete that smallest node
			RemoveNodePrivate (smallest, root);
			//replace root key with the smallest node
			root->key = smallest;
			std::cout << "Root node " << rootKey << " overwritten by " << smallest << std::endl;
			return;
		}
	}
}

//function to delete a non-root node
void BST::RemoveMatch(node *parent, node *match, bool check)
{
	//if tree is empty
	if (root == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}

	//if tree if not empty
	if (root != NULL)
	{
		node *DeletePtr;
		int matchKey = match->key;
		int smallest;

		//when no children of the matching node
		if (match->left == NULL && match->right == NULL)
		{
			//true means on the left sub-tree
			//false means on the right sub-tree
			check == true ? parent->left = NULL : parent->right = NULL;
			DeletePtr = match;
			delete DeletePtr;
			std::cout << "Node " << matchKey << " deleted\n";
			return;
		}

		//when no left child but right child
		if (match->left == NULL && match->right != NULL)
		{
			check == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			DeletePtr = match;
			delete DeletePtr;
			std::cout << "Node " << matchKey << " deleted\n";
			return;
		}
	
		//when no right child but left child
		if (match->left != NULL && match->right == NULL)
		{
			check == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			DeletePtr = match;
			delete DeletePtr;
			std::cout << "Node " << matchKey << " deleted\n";
			return;
		}
		
		//when right and left child
		if (match->left != NULL && match->right != NULL)
		{
			//store the smallest value found in the right sub-tree
			smallest = SmallestNodePrivate (match->right);
			//remove the smallest node found from the tree
			RemoveNodePrivate (smallest, match);
			//replace the value of the match with the smallest node found
			match->key = smallest;
			return;
		}		
	}
}

int BST::HeightOfTree () { return HeightOfTreePrivate (root); }

int BST::HeightOfTreePrivate (node *Ptr)
{
	if (Ptr == NULL) { return 0; }
	else
		return 1 + std::max (HeightOfTreePrivate (Ptr->left), HeightOfTreePrivate (Ptr->right));
}

int BST::leafCount () { return leafCountPrivate (root); }

int BST::leafCountPrivate (node *ptr)
{
	if (ptr == NULL)
		return 0;
	else
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;
	else
		return leafCountPrivate (ptr->left) + leafCountPrivate (ptr->right);
}

int BST::numberOfNodes () { return numberOfNodesPrivate (root); }

int BST::numberOfNodesPrivate (node *ptr)
{
	if (ptr == NULL)
		return 0;
	else
		return 1 + numberOfNodesPrivate (ptr->left) + numberOfNodesPrivate (ptr->right);
}

int BST::sumOfNodesRecursive () { return sumOfNodesPrivateRecursive (root); }

int BST::sumOfNodesPrivateRecursive (node *ptr)
{
	//check if tree is empty
	if (ptr == NULL)
		return 0;
	else
		return ptr->key + sumOfNodesPrivateRecursive (ptr->left) + sumOfNodesPrivateRecursive (ptr->right);
}

int BST::sumOfNodesIterative () { return sumOfNodesIterativePrivate (root); }

int BST::sumOfNodesIterativePrivate (node *ptr)
{
	int sum = 0;

	if (ptr == NULL)
		return 0;
	
	else
	{
		//create a queue to store nodes
		std::list <node *> queue;

		//push the first node in queue and mark it as visited
		queue.push_back (ptr);

		while (!queue.empty ())
		{
			//store the front value of the queue
			node *temp = queue.front ();

			sum = sum + temp->key;

			//for level order traversal, we could uncomment the below line
			//std::cout << temp->key << " ";

			//remove node from queue
			queue.pop_front ();

			//store the left children
			if (temp->left != NULL)
				queue.push_back (temp->left);

			//store the right children
			if (temp->right != NULL)
				queue.push_back (temp->right);
		}
	}
	return sum;
}

int BST::lowestCommonAncesstor (int n1, int n2) { return lowestCommonAncesstorPrivate (root, n1, n2)->key; }

BST::node *BST::lowestCommonAncesstorPrivate (node *ptr, int n1, int n2)
{
	if (ptr == NULL)
	{
		std::cout << "Tree is empty!\n";
		return NULL; 
	}

	//if both nodes are smaller than root, lca lies in the left part of the tree
	if (n1 < ptr->key && n2 < ptr->key)
		return lowestCommonAncesstorPrivate (ptr->left, n1, n2);
	//if both nodes are bigger than root value, lca lies in the right part of the tree 
	if (n1 > ptr->key && n2 > ptr->key)
		return lowestCommonAncesstorPrivate (ptr->right, n1, n2);
	//else, ptr (new root) is the lca
	else
		return ptr;
}

int BST::distanceBetweenNodes (int n1, int n2)
{
	node *node1 = SearchNode (n1);
	node *node2 = SearchNode (n2);

	node *lca = lowestCommonAncesstorPrivate (root, n1, n2);

	int distance = 0;

	//traverse from lca to node1
	node *temp1 = lca;
	while (true)
	{
		if (node1->key == temp1->key)
			break;
		else if (node1->key > temp1->key)
			temp1 = temp1->right;
		else
			temp1 = temp1->left;
		distance++;
	}

	//traverse from lca to node2
	node *temp2 = lca;
	while (true)
	{	
		if (node2->key == temp2->key)
			break;
		else if (node2->key > temp2->key)
			temp2 = temp2->right;
		else
			temp2 = temp2->left;
		distance++;
	}

	return distance;
}