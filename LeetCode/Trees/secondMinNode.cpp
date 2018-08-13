// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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
    int findSecondMinimumValue(TreeNode* root){
        if(!root)
            return 0;
        vector<int> smallest;
        int smallest2 = INT_MAX, secondSmallest = INT_MAX;
        // Apply BFS
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->val < smallest2){
                secondSmallest = smallest2;
                smallest2 = temp->val;
            }
            else if(temp->val < secondSmallest && temp->val != smallest2)
                secondSmallest = temp->val;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(secondSmallest == INT_MAX)
            return -1;
        return secondSmallest;
    }
};