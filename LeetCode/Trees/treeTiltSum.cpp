// https://leetcode.com/contest/leetcode-weekly-contest-29/problems/binary-tree-tilt/

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
    // BFS
    int findTilt(TreeNode* root){
        if(!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int tilt = 0;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            tilt += std::abs(sum(temp->left) - sum(temp->right));
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return tilt;
    }
private:
    int sum(TreeNode* root){
        if(!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return sum;
    }
};