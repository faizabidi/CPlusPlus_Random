// https://leetcode.com/problems/binary-tree-paths/

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
    // Recursive
    vector<string> binaryTreePaths(TreeNode* root){
        std::vector<std::string> allPaths;
        if(!root)
            return allPaths; 
        helper(root, std::to_string(root->val), allPaths);
        return allPaths;
    }
    void helper(TreeNode *temp, std::string node_value, std::vector<std::string> &tempPath){
        if(!temp->left && !temp->right)
            tempPath.push_back(node_value);
        if(temp->left)
            helper(temp->left, node_value + "->" + std::to_string(temp->left->val), tempPath);
        if(temp->right)
            helper(temp->right, node_value + "->" + std::to_string(temp->right->val), tempPath);
            
    }
    // Non-recursive
    /*vector<string> binaryTreePaths(TreeNode* root){
        std::vector<std::string> allPaths;
        if(!root)
            return allPaths;
        std::queue<TreeNode *> q;
        std::queue<std::string> tempPaths;
        
        q.push(root);
        tempPaths.push(std::to_string(root->val));

        while(!q.empty()){
            TreeNode *temp = q.front(); 
            q.pop();

            std::string node_value = tempPaths.front(); 
            tempPaths.pop(); 
            
            // If both left and right are empty
            if(!temp->left && !temp->right)
                allPaths.push_back(node_value);
            
            // If left exists
            if(temp->left){
                q.push(temp->left);
                tempPaths.push(node_value + "-->" + std::to_string(temp->left->val));
            }
            // If right exists
            if(temp->right){
                q.push(temp->right);
                tempPaths.push(node_value + "-->" + std::to_string(temp->right->val));
            }
        }
        return allPaths;
    }*/
};