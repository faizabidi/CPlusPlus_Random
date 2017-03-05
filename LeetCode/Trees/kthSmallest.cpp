// https://leetcode.com/problems/kth-smallest-element-in-a-bst/?tab=Description

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
    int kthSmallest(TreeNode* root, int k){
        // Store all in a vector
        std::vector<int> array;
        if(!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            array.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
               
        // Sort the vector
        std::sort(array.begin(), array.end());
        // Print it
        std::vector<int>::iterator it;
        for(it = array.begin(); it != array.end(); it++)
            std::cout << *it << " ";
        return array[k - 1];
        
    }
};