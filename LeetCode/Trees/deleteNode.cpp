// https://leetcode.com/problems/delete-node-in-a-bst/?tab=Description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Search if a node is found in a tree
	TreeNode *search(TreeNode *temp, int key){
        if(temp->val == key)
        	return temp;
        if(temp->left){
            if(search(temp->left, key))
            	return temp->left;
        }
        if(temp->right){
            if(search(temp->right, key))
            	return temp->right;
        }
        return NULL;
	}
	
    TreeNode *smallest(TreeNode *temp){
        // Smallest is the left most element
        while(temp->left)
            temp = temp->left;
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root)
            return root;
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
         // Else, we have found the node to delete
         // Only right
        else{
            if(!root->left){
            TreeNode *temp = root->right;
            delete root;
            return temp;
            }
            // Only left
            if(!root->right){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // Both left and right
            // Find the smallest node in the right sub-tree
            TreeNode *small = smallest(root->right);
            root->val = small->val;
            // Delete the duplicate
            root->right = deleteNode(root->right, small->val);
        }
        return root;
    }
};