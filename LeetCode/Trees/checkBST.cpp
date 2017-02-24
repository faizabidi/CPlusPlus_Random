// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root){
        return isValidBST_Helper(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST_Helper(TreeNode* root, long min, long max){
        // If root is NULL
        if(!root)
            return true;
        // If root is not NULL
        if(root->val > min && root->val < max){
                //if(root->val >= root->left->val && root->val < root->right->val)
                return isValidBST_Helper(root->left, min, root->val) 
                        && isValidBST_Helper(root->right, root->val, max);
        }
        return false;
    }

    // Iterative
    // Do an in-order traversal
    // If array is sorted, it is a BST
    vector<int> inOrder(Node *root, vector<int> &array){
        if(!root)
            return array;
        if(root->left)
           inOrder(root->left, array);
        array.push_back(root->data);
        if(root->right)
           inOrder(root->right, array);
        return array;
    }

    bool checkBST(Node* root){
        vector<int> array;;
        array = inOrder(root, array);
        
        for(int i = 0; i < array.size() - 1; i++){
            if(array[i] >= array[i + 1])
                return false;
        }
        return true;
    }
};