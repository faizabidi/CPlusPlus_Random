// https://leetcode.com/problems/invert-binary-tree/?tab=Description

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
    // Iterative
    TreeNode* invertTree(TreeNode* root){
        if(!root)
            return root;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            std::swap(temp->left, temp->right);
        }
        return root;
    }
    
    // Recursive
    TreeNode* invertTree(TreeNode* root){
        if(!root)
            return root;
        // Recursively swap left and right sub-trees
        if(root->left)
            invertTree(root->left);
        if(root->right)
            invertTree(root->right);
        std::swap(root->left, root->right);
        return root;
    }
};