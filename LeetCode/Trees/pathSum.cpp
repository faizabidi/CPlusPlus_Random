// https://leetcode.com/problems/path-sum/

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
    // Non-recursive solution
    bool hasPathSum(TreeNode* root, int sum){
        if(root == NULL)
            return false;
        // Non-recursive solution
        std::queue<TreeNode *> q;
        std::queue<int> values;
        q.push(root);
        values.push(root->val);
        while(!q.empty()){
            int sum_needed = values.front();
            TreeNode *curr = q.front();
            values.pop();
            q.pop();
            if(sum_needed == sum && !curr->left && !curr->right)
                return true;
            if(curr->left){
                q.push(curr->left);
                values.push(sum_needed + curr->left->val);
            }
            if(curr->right){
                q.push(curr->right);
                values.push(sum_needed + curr->right->val);
            }
        }
        return false;
    }
    // Recursive solution
    bool hasPathSum(TreeNode* root, int sum){
        if(!root)
            return false;
        int sum_needed = sum - root->val;
        if(sum_needed == 0 && !root->left && !root->right)
            return true;
        return (hasPathSum(root->left, sum_needed) || 
                hasPathSum(root->right, sum_needed));
    }
};