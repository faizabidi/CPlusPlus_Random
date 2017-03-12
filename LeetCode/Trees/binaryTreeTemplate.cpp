// https://www.hackerrank.com/challenges/swap-nodes-algo

#include <iostream>
#include <queue>
#include <cstdlib>

class tree{
private:
	struct node{
		node *left;
		node *right;
		int data;
	}*root;

	node *createLeaf(int val){
		node *newNode = new node;
		newNode->left = newNode->right = NULL;
		newNode->data = val;
		return newNode;
	}

	void addLeafPrivate(node *temp, int val){
		if(!temp){
			root = createLeaf(val);
			return;
		}
		// Do a bfs = level order traversal
		std::queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *temp = q.front();
			q.pop();

			if(!temp->left){
				temp->left = createLeaf(val);
				return;
			}

			if(!temp->right){
				temp->right = createLeaf(val);
				return;
			}
			
			// Else, add both to the queue
			// -1 means NULL
			if(temp->left->data != -1)
				q.push(temp->left);
			if(temp->right->data != -1)
				q.push(temp->right);
		}

	}

	void inOrderPrintPrivate(node *temp){
		if(!temp)
			return;
		inOrderPrintPrivate(temp->left);
		// -1 means NULL
		if(temp->data != -1)
			std::cout << temp->data << " ";
		inOrderPrintPrivate(temp->right);
	}

	int getHeightPrivate(node *temp){
		if(!temp)
			return 0;
		return 1 + std::max(getHeightPrivate(temp->left), getHeightPrivate(temp->right));
	}

	bool searchPrivate(node *temp, int key){
		if(temp->data == key){
			std::cout << "Found\n";
			return true;
		}
		if(temp->left){
			if(searchPrivate(temp->left, key)){
				std::cout << "Checking left " << temp->left->data << std::endl;
				return true;
			}
		}
		if(temp->right){
			if(searchPrivate(temp->right, key)){
				std::cout << "Checking right " << temp->right->data << std::endl;
				return true;
			}
		}
		return false;
	}

    node *smallest(node *temp){
    	// Smallest is the left most element
		while(temp->left)
		    temp = temp->left;
		return temp;
    }

public:
	tree(){
		root = NULL;
	}
	void addLeaf(int val){
		addLeafPrivate(root, val);
	}
	void inOrderPrint(){
		inOrderPrintPrivate(root);
	}
	int getHeight(){
		return getHeightPrivate(root);
	}
	bool search(int key){
		return searchPrivate(root, key);
	}
};

int main(){
	tree obj1;
	obj1.addLeaf(1);
	obj1.addLeaf(2);
	obj1.addLeaf(3);
	obj1.addLeaf(4);
	obj1.addLeaf(5);
	obj1.addLeaf(6);
	obj1.addLeaf(7);
	obj1.inOrderPrint();
	std::cout << std::endl;
	if(obj1.search(78))
		std::cout << "8 is in the tree\n";
	return 0;
}