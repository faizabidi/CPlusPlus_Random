// https://leetcode.com/problems/find-largest-value-in-each-tree-row/?tab=Description

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
    // Let's do level order traversal
    vector<int> largestValues(TreeNode* root){
        std::queue<TreeNode *> q;
        std::vector<int> ans;
        if(!root)
            return ans;
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty()){
            int size = q.size();
            
            long max = LONG_MIN;
            bool flag = false;
            
            //std::cout << temp->data;
            while(size > 0){
                TreeNode *temp = q.front();
                q.pop();
                std::cout << temp->val;
                if(temp->left){
                    q.push(temp->left);
                    if(temp->left->val > max){
                        max = temp->left->val;
                        flag = true;
                    }
                }
                if(temp->right){
                    q.push(temp->right);
                    if(temp->right->val > max){
                        max = temp->right->val;
                        flag = true;
                    }
                }
                size--;
            }
            if(flag)
                ans.push_back(max);
            std::cout << std::endl;
        }
        return ans;
    }
};