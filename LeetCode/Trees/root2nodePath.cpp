#include <iostream>
#include <vector>
#include <queue>

class tree{
private:
	struct node{
		int data;
		node *left;
		node *right;
	}*root;

	node *createLeaf(int key){
		node *newNode = new node;
		newNode->data = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	void printTreePrivate(node *temp){
		if(!temp)
			return;
		// Print in-order -> left, root, right
		printTreePrivate(temp->left);
		std::cout << temp->data << " ";
		printTreePrivate(temp->right); 
	}

	void printVector(std::vector<int> array){
		for(int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}

	bool printRoot2nodePrivate(node *start, node *dest, std::vector<int> &tempPath){
		if(!start)
			return false;
		if(start == dest){
			tempPath.push_back(start->data);
			return true;
		}
		if(printRoot2nodePrivate(start->left, dest, tempPath)){
			tempPath.push_back(start->data);
			return true;
		}
		if(printRoot2nodePrivate(start->right, dest, tempPath)){
			tempPath.push_back(start->data);
			return true;
		}
		return false;
	}

	void visibleNodesPrivate(node *root){
		int count = 0;
		if(!root)
			return;
		std::queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *temp = q.front();
			q.pop();
			std::vector<int> tempPath;
			if(printRoot2nodePrivate(root, temp, tempPath)){
				if(temp->data >= *std::max_element(tempPath.begin(), tempPath.end()))
					std::cout << temp->data << std::endl;
			}
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}

public:
	tree(){root = NULL;}
	
	void addLeaf(int key){
		if(!root){
			root = createLeaf(key);
			return;
		}
		// Do a BFS and find the first empty left or right
		std::queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *temp = q.front();
			q.pop();
			if(!temp->left){
				temp->left = createLeaf(key);
				return;
			}
			else
				q.push(temp->left);
			if(!temp->right){
				temp->right = createLeaf(key);
				return;
			}
			else
				q.push(temp->right);
		}
	}

	void printTree(){
		printTreePrivate(root);
	}

	void printRoot2node(){
		// Print for every node
		if(!root)
			return;
		std::queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *temp = q.front();
			q.pop();
			std::cout << "Path from root to " << temp->data << " is\n";
			std::vector<int> tempPath;
			if(printRoot2nodePrivate(root, temp, tempPath)){
				std::reverse(tempPath.begin(), tempPath.end());
				printVector(tempPath);
			}
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}

	void visibleNodes(){
		visibleNodesPrivate(root);
	}
};

int main(){
	tree obj1;
	obj1.addLeaf(5);
	obj1.addLeaf(3);
	obj1.addLeaf(10);
	obj1.addLeaf(20);
	obj1.addLeaf(21);
	obj1.addLeaf(1);
	//obj1.addLeaf(25);
	//obj1.addLeaf(12);
	obj1.printTree();
	std::cout << std::endl;
	obj1.printRoot2node();
	std::cout << std::endl;
	obj1.visibleNodes();

	return 0;
}