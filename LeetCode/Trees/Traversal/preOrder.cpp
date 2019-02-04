/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Iterative solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        if(!root)
            return {};
        vector<int> array;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            array.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return array;
    }
};