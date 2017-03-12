// https://leetcode.com/problems/count-complete-tree-nodes/?tab=Solutions

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
    int countNodes(TreeNode* root){
        // BFS - O(n)
        /*int count = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            count++;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }*/
        // O(logN * logN)
        if(!root)
            return 0;
        // Find height of left and right sub-trees
        TreeNode *lft = root;
        TreeNode *rit = root;
        int lft_height = 0;
        int rit_height = 0;
        while(lft){
            lft_height++;
            lft = lft->left;
        }
        while(rit){
            rit_height++;
            rit = rit->right;
        }
        if(lft_height == rit_height)
            return pow(2, lft_height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};