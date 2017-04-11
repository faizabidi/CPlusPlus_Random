// https://leetcode.com/problems/minimum-depth-of-binary-tree/#/description

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
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            // Check each level. The first leaf found is the minimum depth
            depth++;
            while(size > 0){
                TreeNode *temp = q.front();
                q.pop();
                // Check if leaf node
                if(!temp->left && !temp->right)
                    return depth;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                size--;
            }
        }
        return depth;
    }
};