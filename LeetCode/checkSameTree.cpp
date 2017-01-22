// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q){
        // If only any one of them is NULL
        if(!p && q || p && !q)
            return false;
        // If both are NULL
        if(!p && !q)
            return true;
        if(p->val != q->val)
            return false;
        // Apply Level Order Traversal
        std::queue<TreeNode *> q1, q2;
        q1.push(p); q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode *q1_temp = q1.front();
            TreeNode *q2_temp = q2.front();
            q1.pop(); q2.pop();
            // Check if values are same
            if(q1_temp->val != q2_temp->val)
                return false;
            // If left sub-tree not empty
            if(q1_temp->left && q2_temp->left){
                q1.push(q1_temp->left);
                q2.push(q2_temp->left);
            }
            // If one left child is empty and the other is not
            if(!q1_temp->left && q2_temp->left)
                return false;
            if(q1_temp->left && !q2_temp->left)
                return false;
            // If right sub-tree not empty
            if(q1_temp->right && q2_temp->right){
                q1.push(q1_temp->right);
                q2.push(q2_temp->right);
            }
            // If one right child is empty and the other is not
            if(!q1_temp->right && q2_temp->right)
                return false;
            if(q1_temp->right && !q2_temp->right)
                return false;
        }
        return true;
        // Recursive solution
        bool isSameTree(TreeNode* p, TreeNode* q){
            // If both empty
            if(!p && !q)
                return true;
            // If both are non-empty
            if(p && q){
                return
                (
                    (p->val == q->val) &&
                    isSameTree(p->left, q->left) &&
                    isSameTree(p->right, q->right)
                );
            }
            // One is empty and other is not
            return false;
        }
    }
};