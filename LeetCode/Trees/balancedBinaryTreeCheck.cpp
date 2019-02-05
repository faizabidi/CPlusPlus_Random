// https://leetcode.com/problems/balanced-binary-tree/submissions/1

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
    // Find depth of tree
    int depth(TreeNode *root){
        if(!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    bool isBalanced(TreeNode* root){
        if(!root || (!root->left && !root->right))
            return true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            int left = 0, right = 0;
            if(temp->left){
                left = depth(temp->left);
                q.push(temp->left);
            }
            if(temp->right){
                right = depth(temp->right);
                q.push(temp->right);
            }
            if(abs(right - left) > 1)
                return false;
        }
        return true;
    }
};
