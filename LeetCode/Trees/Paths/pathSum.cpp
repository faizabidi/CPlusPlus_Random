// https://leetcode.com/problems/path-sum-ii/
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
    
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        pathSumHelper(root, sum, path, result);
        return result;
    }
    void pathSumHelper(TreeNode *temp, int sum, std::vector<int> path, 
                            std::vector<std::vector<int>> &result){
        if(!temp)
            return;
        path.push_back(temp->val);
        // Found
        if(!temp->left && !temp->right && temp->val == sum){
            result.push_back(path);
            return;
        }
        // If left exists
        if(temp->left)
           pathSumHelper(temp->left, sum - temp->val, path, result);
        if(temp->right)
           pathSumHelper(temp->right, sum - temp->val, path, result);
    }
};