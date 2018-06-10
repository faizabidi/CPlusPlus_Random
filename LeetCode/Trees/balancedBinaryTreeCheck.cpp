// https://leetcode.com/problems/balanced-binary-tree/submissions/1

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
    int getHeight(TreeNode *root){
        if(!root)
            return 0;
        int height = 0;
        queue<TreeNode *> q;
        q.push(root);
        // Do a level order traversal
        while(!q.empty()){
            int k = q.size();
            while(k != 0){
                TreeNode *temp = q.front(); 
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                k--;
            }       
            height++;
        }
        return height;
    }
    bool isBalanced(TreeNode* root){
        if(!root)
            return true;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            while(k > 0){
                TreeNode *temp = q.front(); 
                q.pop();
                int leftHeight = 0, rightHeight = 0;
                if(temp->left){
                    leftHeight = getHeight(temp->left);
                    q.push(temp->left);
                }
                if(temp->right){
                    rightHeight = getHeight(temp->right);
                    q.push(temp->right);
                }
                if(std::abs(rightHeight - leftHeight) > 1)
                    return false;
                k--;
            }
        }
        return true;
    }
};
