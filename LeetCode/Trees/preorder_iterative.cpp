// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    /* //Recursion
    std::vector<int> tree;
    vector<int> preorderTraversal(TreeNode* root){
        if(!root)
            return tree;
        tree.push_back(root->val);
        if(root->left)
            preorderTraversal(root->left);
        if(root->right)
            preorderTraversal(root->right);
        return tree;
    }*/
    // Iterative
    vector<int> preorderTraversal(TreeNode* root){
        std::vector<int> result_path;
        std::stack<TreeNode *> s;
        if(!root)
            return result_path;
        s.push(root);
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            result_path.push_back(temp->val);
            // Push right first since we want left to be picked up at the 
            // top of the stack.
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return result_path;
    }
};