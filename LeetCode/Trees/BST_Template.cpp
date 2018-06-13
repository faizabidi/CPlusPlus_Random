#include <iostream>
#include <vector>

struct TreeNode{
	TreeNode *left, *right;
	int val;
};

void printInOrder(TreeNode *root){
	if(!root)
		return;
	if(root->left)
		printInOrder(root->left);
	std::cout << root->val << " ";
	if(root->right)
		printInOrder(root->right);
}

TreeNode *insert(TreeNode *root, int element){
    // Create a new node
    TreeNode *newNode = new TreeNode;
    newNode->left = newNode->right = NULL;
    newNode->val = element;
    
    // Check if the root is NULL
    // In which case, it is the first element in the tree
    if(!root){
        root = newNode;
        return root;
    }
    
    // Else, traverse the tree and find the position where to insert
    TreeNode *temp = root;
    
    // Go as left as possible
    while(temp->val < element && temp->right)
        temp = temp->right;
    
    // Go as right as possible
    while(temp->val > element && temp->left)
        temp = temp->left;
    
    
    // Insert
    if(temp->val >= element)
        temp->left = newNode;
    else
        temp->right = newNode;
    return root;
}

int main(){
	std::vector<int> array = {41, 37, 44, 39, 42, 48};
	

	TreeNode *root = NULL;

	for(int i = 0; i < array.size(); i++)
		root = insert(root, array[i]);
	
	printInOrder(root);
	std::cout << std::endl;

	return 0;
}
