// https://leetcode.com/problems/path-sum-iii/#/description

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
    int ans = 0;
    int pathSum(TreeNode* root, int sum){
        if(!root && sum == 0)
            return ans;
        if(!root && sum != 0)
            return ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            pathSum_helper(temp, sum);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return ans;
    }
private:
    // Helper function to find if a path exists from root to any node for sum = sum
    void pathSum_helper(TreeNode* root, int target){
        if(!root)
            return;
        if(root->val == target)
            ans++;
        pathSum_helper(root->left, target - root->val);
        pathSum_helper(root->right, target - root->val);
    }
    
};