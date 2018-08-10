// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> levelAverages;
        if(!root)
            return levelAverages;
        queue<TreeNode *> q;
        q.push(root);
        levelAverages.push_back(root->val);
        while(!q.empty()){
            int k = q.size();
            long sum = 0, count = 0;
            while(k > 0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    sum += temp->left->val;
                    count++;
                }
                if(temp->right){
                    q.push(temp->right);
                    sum += temp->right->val;
                    count++;
                }
                k--;
            }
            if(sum == 0)
                cout << "Sum is zero.\n";
            if(count != 0)
                levelAverages.push_back(double(sum)/count);
        }
        return levelAverages;
    }
};