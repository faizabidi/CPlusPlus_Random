// https://leetcode.com/problems/binary-tree-pruning/description/

class Solution {
public:
    bool checkTree(TreeNode *root){
        if(!root)
            return false;
        // Check if there's at least one 1 in the tree
        if(root->val == 1)
            return true;
        return (checkTree(root->left) || checkTree(root->right));
    }
    TreeNode* pruneTree(TreeNode *root) {
        if(!root)
            return root;
        // Check if the main root can be removed
        if(!checkTree(root))
            return NULL;
        // Run a BFS on each node and check
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                if(!checkTree(temp->left))
                    temp->left = NULL;
                else
                    q.push(temp->left);
            }
            if(temp->right){
                if(!checkTree(temp->right))
                    temp->right = NULL;
                else
                    q.push(temp->right);
            }
        }
        return root;
    }
};