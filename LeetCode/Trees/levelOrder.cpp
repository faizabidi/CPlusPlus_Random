// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root){
        std::queue<TreeNode *> s;
        std::vector<std::vector<int>> nodes;

        if(!root)
            return nodes;
        
        s.push(root);
        std::vector<int> root_val;
        root_val.push_back(root->val);
        nodes.push_back(root_val);
        
        while(!s.empty()){
            int size = s.size();
            std::vector<int> path;
            while(size > 0){
                TreeNode *temp = s.front();
                s.pop();
                //path.add(temp->val);
                if(temp->left){
                    s.push(temp->left);
                    path.push_back(temp->left->val);
                }
                if(temp->right){
                    s.push(temp->right);
                    path.push_back(temp->right->val);
                }
                size--;
            }
            if(path.size() > 0)
                nodes.push_back(path);
        }
        return nodes;
        
    }
};