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
    bool isValidBST(TreeNode *root){
        return isValidBST_Helper(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST_Helper(TreeNode* root, long min, long max){
        // If root is NULL
        if(!root)
            return true;
        // If root is not NULL
        if(root->val > min && root->val < max){
                //if(root->val >= root->left->val && root->val < root->right->val)
                return isValidBST_Helper(root->left, min, root->val) 
                        && isValidBST_Helper(root->right, root->val, max);
        }
        return false;
    }
};