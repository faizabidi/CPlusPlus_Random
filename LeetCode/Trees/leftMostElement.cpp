// https://leetcode.com/problems/find-bottom-left-tree-value/?tab=Description

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
    int findBottomLeftValue(TreeNode* root){
        // Do a level order traversal
        std::queue<TreeNode *> q;
        q.push(root);
        int data;
        while(!q.empty()){
            int size = q.size();
            std::vector<int> array;
            while(size > 0){
                TreeNode *temp = q.front();
                array.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                size--;
            }
            data = array[0];
        }
    return data;
    }
};