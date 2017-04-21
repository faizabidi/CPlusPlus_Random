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
        if(!p && !q)
            return true;
        if(!p)
            return false;
        if(!q)
            return false;
        std::queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode *temp1, *temp2;
            temp1 = q1.front();
            temp2 = q2.front();
            q1.pop();
            q2.pop();
            if(temp1->val != temp2->val)
                return false;
            if(temp1->left)
                q1.push(temp1->left);
            if(temp2->left)
                q2.push(temp2->left);
            if((temp1->left && !temp2->left) || (!temp1->left && temp2->left))
                return false;
            if(temp1->right)
                q1.push(temp1->right);
            if(temp2->right)
                q2.push(temp2->right);
            if((temp1->right && !temp2->right) || (!temp1->right && temp2->right))
                return false;
        }
        return true;
    }
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
};