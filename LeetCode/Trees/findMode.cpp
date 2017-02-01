// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    std::vector<int> findMode(TreeNode* root){
        std::vector<int> mode;
        if(!root)
            return mode;
        std::map<int, int> hash;
        // Do a level order traversal, and add to hashmap
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            hash[node->val]++;
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        std::map<int, int>::iterator it;
        int max = 0;
        // Find the max key
        for (it = hash.begin(); it != hash.end(); it++ )
            max = std::max(max, it->second);
        // Find all values with max key value
        for (it = hash.begin(); it != hash.end(); it++ ){
            if(it->second == max)
                mode.push_back(it->first);
        }
        return mode;
    }
};