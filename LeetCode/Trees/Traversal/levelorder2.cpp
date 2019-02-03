// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    // Iterative
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        std::vector<std::vector<int>> result;
        std::vector<int> path_root;
        if(!root)
            return result;
            
        std::queue<TreeNode *> q;
        path_root.push_back(root->val);
        result.push_back(path_root);
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            std::vector<int> path;
            while(k > 0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    path.push_back(temp->left->val);
                }
                if(temp->right){
                    q.push(temp->right);
                    path.push_back(temp->right->val);
                }
                k--;
            }
            if(path.size() > 0)
                result.push_back(path);
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};