// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?tab=Description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    bool findAncesstors(TreeNode *root, TreeNode *p, vector<TreeNode *> &ancesstors){
        if(!root)
            return false;
        if(root == p){
            ancesstors.push_back(root);
            return true;
        }
        // If found in left sub-tree
        if(findAncesstors(root->left, p, ancesstors)){
            ancesstors.push_back(root);
            return true;
        }
        
        // If found in right sub-tree
        if(findAncesstors(root->right, p, ancesstors)){
            ancesstors.push_back(root);
            return true;
        }
        
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_ancesstors, q_ancesstors;
        findAncesstors(root, p, p_ancesstors);
        findAncesstors(root, q, q_ancesstors);
        
        // Find the first common value in the two vectors
        for(int i = 0; i < p_ancesstors.size(); i++){
            if(std::find(q_ancesstors.begin(), q_ancesstors.end(), p_ancesstors[i]) != q_ancesstors.end())
                return p_ancesstors[i];
        }
        return NULL;
    }
};
