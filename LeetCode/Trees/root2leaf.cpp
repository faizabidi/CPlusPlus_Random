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
    void binaryTreePaths_helper(TreeNode* root, vector<string> &ans, string temp){
        if(!root)
            return;
        std::cout << "Running f(" << root->val << ")\n";
        temp += to_string(root->val);
        // If leaf node found
        if(!root->left && !root->right)
            ans.push_back(temp);
        temp += "->";
        if(root->left)
            binaryTreePaths_helper(root->left, ans, temp);
        if(root->right)
            binaryTreePaths_helper(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> ans;
        if(!root)
            return ans;
        string temp = "";
        binaryTreePaths_helper(root, ans, temp);
        return ans;
    }
};

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