// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        // BFS
        queue<TreeNode *> q;
        q.push(root);
        //vector<int> temp = {root->val};
        ans.push_back({root->val});
        bool check = true;
        while(!q.empty()){
            int k = q.size();
            vector<int> list;
            while(k > 0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    list.push_back(temp->left->val);
                }
                if(temp->right){
                    q.push(temp->right);
                    list.push_back(temp->right->val);
                }
                k--;
            }
            if(check){
                reverse(list.begin(), list.end());
                check = false;
            }
            else
                check = true;
            if(list.size() > 0)
                ans.push_back(list);
        }
        return ans;
    }
};