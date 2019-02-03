// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    // Using  iteration
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;
        if(!root)
            return array;
        stack<TreeNode *> s;
        TreeNode *temp = root;
        while(!s.empty() || temp != NULL){
            // Go left if possible
            if(temp){
                s.push(temp);
                temp = temp->left;
            }
            else{
                temp = s.top();
                s.pop();
                array.push_back(temp->val);
                // Go to its right
                temp = temp->right;
            }
        }
        return array;
    }
};