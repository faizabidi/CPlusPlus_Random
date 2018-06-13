// https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
    // Insert in BST
    TreeNode *insert(TreeNode *root, int element){
        // Create a new node
        TreeNode *newNode = new TreeNode(element);
        
        // Check if the root is NULL
        // In which case, it is the first element in the tree
        if(!root){
            root = newNode;
            return root;
        }
        
        // Else, traverse the tree and find the position where to insert
        TreeNode *curr = root, *prev = root;

        while(curr){
            prev = curr;
            // Go as left as possible
            if(curr->val < element)
                curr = curr->right;
            else
                // Go as right as possible
                curr = curr->left;
        }

        // Insert
        if(prev->val >= element)
            prev->left = newNode;
        else
            prev->right = newNode;
        return root;
    }
    TreeNode* trimBST(TreeNode *root, int L, int R){
        if (!root)
            return NULL;
        // BFS
        // Store all the elements between L and R
        vector<int> elements;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            while(k > 0){
                TreeNode *temp = q.front();
                q.pop();
                // Check and store in a vector
                if(temp->val >= L && temp->val <= R)
                    elements.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                k--;
            }
        }
        // Build a BST from the vector
        TreeNode *ans = NULL;
        std::cout << elements.size() << std::endl;
        for(int i = 0; i < elements.size(); i++){
            std::cout << elements[i] << " ";
            ans = insert(ans, elements[i]);
        }
        return ans;
    }
};