// https://leetcode.com/problems/sum-of-left-leaves/

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
    // Iterative
    int sumOfLeftLeaves(TreeNode* root){
        if(!root)
            return 0;
        std::queue<TreeNode *> q;
        std::stack<TreeNode *> s;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                s.push(temp->left);
                //std::cout << "Value in queue is:" << q.front();
            }
            if(temp->right)
                q.push(temp->right);
        }
        int sum = 0;
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            std::cout << temp->val;
            if(!temp->left && !temp->right)
                sum += temp->val;
        }
        return sum;
    }

    // Recursive
    int sumOfLeftLeaves(TreeNode* root){
        int sum = 0;
        sumOfLeftLeaves_Helper(root, sum, false);
        return sum;
    }
    
    void sumOfLeftLeaves_Helper(TreeNode *root, int &sum, bool left){
        if(!root)
            return;
        if(root->left || root->right){
            sumOfLeftLeaves_Helper(root->left, sum, true);
            sumOfLeftLeaves_Helper(root->right, sum, false);
        }
        else if(left == true){
            std::cout << root->val << ",";
            sum += root->val;
        }
    }
};