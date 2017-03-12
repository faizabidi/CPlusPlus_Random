// https://leetcode.com/problems/binary-tree-right-side-view/?tab=Description

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
    vector<int> rightSideView(TreeNode* root){
        std::vector<int> result;
        if(!root)
            return result;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int node;
            while(size > 0){
                TreeNode *temp = q.front();
                q.pop();
                node = temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                size--;
            }
            result.push_back(node);
        }
        return result;
    }
};