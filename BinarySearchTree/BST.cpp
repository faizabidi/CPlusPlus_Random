#include <iostream>
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
		if (Ptr->left != NULL)
			//traverse down the left node since there is another node on the left bottom
			AddLeafPrivate (key, Ptr->left);
		//when it reaches the last node on the left
		else
		{
			//add the node to the tree
			Ptr->left = CreateLeaf (key);
		}
		return;
	}
	
	//if key is greater than the root value
	if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
			//traverse down the right node since there is another node on the right bottom
			AddLeafPrivate (key, Ptr->right);
		//when it reaches the last node on the right
		else
		{
			//add the node to the tree
			Ptr->right = CreateLeaf (key);
		}
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
		std::cout<<"Tree is empty!\n";
		return;
	}

	//if tree is not empty
	if (Ptr != NULL)
	{
		//check if it is possible to go further left
		if (Ptr->left != NULL)
			PrintInOrderPrivate (Ptr->left);
		//print root value
		std::cout<<Ptr->key<<" ";
		//check if it is possible to go further right
		if (Ptr->right != NULL)
			PrintInOrderPrivate (Ptr->right);
	}
}

//search function to call the private serach function
BST::node *BST::SearchNode (int key) { return SearchNodePrivate (key, root); }

//private search function to find a given node
BST::node *BST::SearchNodePrivate (int key, node *Ptr)
{
	//check if tree is empty
	if (Ptr == NULL)
	{
		std::cout<<"Tree is empty!\n";
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
		std::cout<<"Tree is empty!\n";
		return;
	}

	//*ptr will point to the node where key is found
	node *Ptr = SearchNode (key);

	if (Ptr != NULL)
	{
		std::cout<<"Parent node is "<<Ptr->key<<std::endl;
		Ptr->left == NULL ? std::cout<<"Left child is NULL\n" : std::cout<<"Left child is "<<Ptr->left->key<<std::endl;
		Ptr->right == NULL ? std::cout<<"Right child is NULL\n" : std::cout<<"Right child is "<<Ptr->right->key<<std::endl;
		std::cout<<std::endl;
		return;
	}
	//if key not found
	std::cout<<key<<" is not in the tree\n";
}

//public function to call private function to find the smallest node
int BST::SmallestNode () { return SmallestNodePrivate (root); }

//private function to find the smallest node
//smallest node in a BST would be extreme left
int BST::SmallestNodePrivate (node *Ptr)
{
	if (Ptr == NULL)
	{
		std::cout<<"\nTree is empty\n";
		return -99999;
	}
	//check left pointers recursively
	if (Ptr->left != NULL)
		return SmallestNodePrivate (Ptr->left);
	
	//when you reach the left most node, return its value
	return Ptr->key;
}

void BST::HeightOfTree ()
{
	int count1 = 0;//count2 = 0;
	while (root != NULL)
	{
		count1++;
		root = root->left;
	}
	std::cout<<"Left height is "<<count1;
}

//pubiic function calling the private function to delete a node
void BST::RemoveNode (int key) { RemoveNodePrivate (key, root); }

//function to remove a node from a tree
void BST::RemoveNodePrivate (int key, node *parent)
{
	//empty tree
	if (root == NULL)
	{
		std::cout<<"Nothing to delete. Tree is empty!\n";
		return;
	}
 
	if (root != NULL)
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

		std::cout<<"Node not found in the tree\n";
	}
}

//function to delete the root node
void BST::RemoveRootMatch()
{
	//if tree is empty
	if  (root == NULL)
	{
		std::cout<<"Tree is empty!\n";
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
			std::cout<<"Root node "<<rootKey<<" deleted\n";
			return;
		}
		
		//case when root has no right but left child
		if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			DeletePtr->left = NULL;
			delete DeletePtr;
			std::cout<<"Root node "<<rootKey<<" deleted\n";
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
			std::cout<<"Root node "<<rootKey<<" overwritten by "<<smallest<<std::endl;
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
		std::cout<<"Tree is empty!\n";
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
			std::cout<<"Node "<<matchKey<<" deleted\n";
			return;
		}

		//when no left child but right child
		if (match->left == NULL && match->right != NULL)
		{
			check == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			DeletePtr = match;
			delete DeletePtr;
			std::cout<<"Node "<<matchKey<<" deleted\n";
			return;
		}
	
		//when no right child but left child
		if (match->left != NULL && match->right == NULL)
		{
			check == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			DeletePtr = match;
			delete DeletePtr;
			std::cout<<"Node "<<matchKey<<" deleted\n";
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