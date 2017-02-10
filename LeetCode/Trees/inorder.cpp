// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
     // Recursion
    /*std::vector<int> nodes;
    vector<int> inorderTraversal(TreeNode* root){
        if(!root)
            return nodes;
        if(root->left)
            inorderTraversal(root->left);
        nodes.push_back(root->val);
        if(root->right)
           inorderTraversal(root->right); 
       return nodes;
    }*/
    
    // Iterative
    vector<int> inorderTraversal(TreeNode* root){
        std::stack<TreeNode *> s;
        std::vector<int> nodes;
        if(!root)
            return nodes;
        s.push(root);
        // Add the left most node since that's the smallest
        while(root->left){
            root = root->left;
            s.push(root);
        }
        // We need to check the left most element of the right element of this node
        while(!s.empty()){
            TreeNode *temp = s.top();
            nodes.push_back(temp->val);
            s.pop();
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
        return nodes;
    }
};