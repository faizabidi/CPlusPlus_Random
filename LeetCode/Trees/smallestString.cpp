// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    void findPaths(TreeNode *root, vector<string> &paths, string temp){
        if(!root)
            return;
        if(!root->left && !root->right){
            temp += char(root->val+97);
            reverse(temp.begin(), temp.end());
            paths.push_back(temp);
            return;
        }
        findPaths(root->left, paths, temp + char(root->val+97));
        findPaths(root->right, paths, temp + char(root->val+97));
    }
    string smallestFromLeaf(TreeNode* root){
        if(!root)
            return {};
        // Find all paths and then find the smallest lexicographically
        vector<string> paths;
        findPaths(root, paths, "");
        sort(paths.begin(), paths.end());
        return paths[0];
    }
};