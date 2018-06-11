// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

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
    TreeNode *sortedArrayToBST_Helper(vector<int> nums, int start, int end){
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST_Helper(nums, start, mid-1);
        root->right = sortedArrayToBST_Helper(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int> nums){
        if(nums.size() == 0)
            return NULL;
        TreeNode *root = sortedArrayToBST_Helper(nums, 0, nums.size() - 1);
        return root;
    }        
};