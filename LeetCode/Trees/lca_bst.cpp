// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        // Traverse through the tree
        // LCA would be the first node > p and < q
        // Recursively traverse
        // Let's do inorder
        if(!root)
            return root;
        
        // If both p and q smaller than root
        // LCA is in left tree
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
            
        // If both p and q biger than root
        // LCA is in right tree
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
            
        std::cout << root->val << "\n";
        return root;
    }
};