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
		if(temp->data != -1)
			std::cout << temp->data << " ";
		inOrderPrintPrivate(temp->right);
	}

	void invertPrivate(node *temp, int level){
		if(!temp)
			return;
		int curr_level = 1;
		std::queue<node *> q;
		q.push(root);
		while(!q.empty()){
			int size = q.size();
			while(size > 0){
				node *temp = q.front();
				q.pop();
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
				if(curr_level == level)
					std::swap(temp->left, temp->right);
				size--;
			}
			curr_level++;
		}
	}
	int getHeightPrivate(node *temp){
		if(!temp)
			return 0;
		return 1 + std::max(getHeightPrivate(temp->left), getHeightPrivate(temp->right));
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
	void invert(int level){
		invertPrivate(root, level);
	}
	int getHeight(){
		return getHeightPrivate(root);
	}
};

int main(){
	int n;
	std::cout << "Enter N:";
	std::cin >> n;
	tree obj1;

	// Add 1 as the root always
	obj1.addLeaf(1);
	
	std::cout << "Enter the values of the tree:";
	for(int i = 0; i < n; i++){
		int left, right;
		std::cin >> left >> right;
		obj1.addLeaf(left);
		obj1.addLeaf(right);
	}

	int height = obj1.getHeight();
	// Depending on K, invert it equal number of times
	std::cout << "Enter T:";
	int t;
	std::cin >> t;
	for(int i = 0; i < t; i++){
		int k;
		std::cin >> k;

		for(int i = 1; i*k <= height; i++)
			obj1.invert(i*k);
		// Print it
		obj1.inOrderPrint();
		std::cout << std::endl;
	}
	return 0;
}