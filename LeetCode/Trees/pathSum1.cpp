// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum){
        std::string path;
        if(!root){
            std::cout << path;
            return false;
        }
        path = std::to_string(root->val);
        if(hasPathSum_helper(root, path, sum))
            return true;
        return false;
    }
    
    bool hasPathSum_helper(TreeNode* temp, std::string path, int sum){
        bool flag = false;
        // If leaf and found
        if(!temp->left && !temp->right && temp->val == sum){
            std::cout << "Value of this leaf is " << temp->val << std::endl;
            std::cout << path << std::endl;
            return true;
        }
        int new_sum = sum - temp->val;
        if(temp->left)
            flag = flag || hasPathSum_helper(temp->left, path + "->" + std::to_string(temp->left->val), new_sum);
        if(temp->right)
            flag = flag || hasPathSum_helper(temp->right, path + "->" + std::to_string(temp->right->val), new_sum);
        return flag;
    }
};