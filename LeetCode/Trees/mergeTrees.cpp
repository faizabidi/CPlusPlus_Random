// https://leetcode.com/problems/merge-two-binary-trees/description/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(!t1 && t2)
            return t2;
        if(t1 && !t2)
            return t1;
        if(!t1 && !t2)
            return NULL;
        
        queue<TreeNode *> q1, q2;
        q1.push(t1);
        q2.push(t2);
        // Do a level order traversal
        // Merge t2 into t1
        while(!q1.empty() && !q2.empty()){
            TreeNode *temp1 = q1.front();
            q1.pop();
            TreeNode *temp2 = q2.front();
            q2.pop();
            temp1->val += temp2->val;
            if(!temp1->left && temp2->left)
                temp1->left = temp2->left;
            else if(temp1->left && temp2->left)
                q1.push(temp1->left), q2.push(temp2->left);
                
            if(!temp1->right && temp2->right)
                temp1->right = temp2->right;
            else if(temp1->right && temp2->right)
                q1.push(temp1->right), q2.push(temp2->right);
        }
        return t1;
    }
};

// Using recursion
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(!t1 && t2)
            return t2;
        if(t1 && !t2)
            return t1;
        if(!t1 && !t2)
            return NULL;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
