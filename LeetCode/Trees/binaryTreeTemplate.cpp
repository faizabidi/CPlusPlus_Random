#include <iostream>

class Trees{
private:
	struct Node{
		int data;
		Node *left;
		Node *right;
	}*root;
	// Create a leaf node
	Node *createLeaf(int val){
		Node *newNode = new Node;
		newNode->data = val;
		newNode->left = newNode->right = NULL;
		return newNode; 
	}	
	// Recursive helper function for insertion
	void insert_recursive_private(Node *ptr, int val){
		if(!ptr){
			root = createLeaf(val);
			return;
		}
		if(val <= ptr->data){
			if(ptr->left)
				insert_recursive_private(ptr->left, val);
			else
				ptr->left = createLeaf(val);
		}
		else{
			if(ptr->right)
				insert_recursive_private(ptr->right, val);
			else
				ptr->right = createLeaf(val);
		}
	}
	// In-order using recursion
	void print_recursive_private(Node *ptr){
		if(!ptr)
			return;
		if(ptr->left)
			print_recursive_private(ptr->left);
		std::cout << ptr->data;
		if(ptr->right)
			print_recursive_private(ptr->right);
	}

public:
	Trees(){ root = NULL; };
	// Iterative insertion
	void insert_iterative(int data){
		// Tree is empty
		if(!root)
			root = createLeaf(data);
		Node *curr = root;
		Node *parent = NULL;
		while(true){
			parent = curr;
			if(data <= curr->data){
				curr = curr->left;
				if(!curr){
					parent->left = createLeaf(data);
					return;
				}
			}
			else{
				curr = curr->right;
				if(!curr){
					parent->right = createLeaf(data);
					return;
				}
			}
		}
	}
	// Recusive insertion function calling its wrapper
	void insert_recursive(int val){
		insert_recursive_private(root, val);
	}

	void print_recursive(){
		print_recursive_private(root);
	}
};

int main(){
	Trees obj1;
	obj1.insert_recursive(2);
	obj1.insert_iterative(3);


	return 0;
}