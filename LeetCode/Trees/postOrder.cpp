// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    /*
    // Recursive
    std::vector<int> result;
    vector<int> postorderTraversal(TreeNode* root){
        if(!root)
            return result;
        if(root->left)
            postorderTraversal(root->left);
        if(root->right)
            postorderTraversal(root->right);
        result.push_back(root->val);
        return result;
    }*/
        
    // Iterative
    vector<int> postorderTraversal(TreeNode* root){
        std::vector<int> result;
        if(!root)
            return result;
        // We will solve using two stacks - stack and vector
        // Refer: http://articles.leetcode.com/binary-tree-post-order-traversal/
        std::stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            result.push_back(temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};