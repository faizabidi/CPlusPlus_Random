// https://leetcode.com/problems/sum-root-to-leaf-numbers/?tab=Description

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
    void printRoot2Leaf_helper(TreeNode *temp, std::string str, std::vector<std::string> &ans){
        if(!temp->left && !temp->right)
            ans.push_back(str);
        if(temp->left)
            printRoot2Leaf_helper(temp->left, str + std::to_string(temp->left->val), ans);
        if(temp->right)
            printRoot2Leaf_helper(temp->right, str + std::to_string(temp->right->val), ans);
    }
    std::vector<std::string> printRoot2Leaf(TreeNode *temp){
        std::vector<std::string> ans;
        if(!temp)
            return ans;
        std::string str = std::to_string(temp->val);
        printRoot2Leaf_helper(temp, str, ans);
        return ans;
        
    }
    int sumNumbers(TreeNode* root){
        std::vector<std::string> ans = printRoot2Leaf(root);
        int sum = 0;
        for(int i = 0; i < ans.size(); i++)
            sum += std::stoi(ans[i]);
        return sum;
    }
};