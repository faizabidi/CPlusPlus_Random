// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    // Recursive
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        if(root->left)
            maxDepth(root->left);
        if(root->right)
            maxDepth(root->right);
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
    
    // Iterative
    int maxDepth2(TreeNode* root){
        int count = 0;
        if(!root)
            return count;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size > 0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                size--;
            }
        }
        return count;
    }
};