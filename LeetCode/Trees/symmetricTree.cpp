https://leetcode.com/problems/symmetric-tree/#/description

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
    void print(std::vector<int> array){
        for(int i = 0; i < array.size(); i++)
            std::cout <<  array[i] << " ";
        std::cout <<  std::endl;
    }
    bool isSymmetric(TreeNode* root){
        if(!root)
            return true;
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            std::vector<int> array;
            while(size > 0){
                TreeNode *temp = q.front();
                q.pop();
                //array.push_back(temp->val);
                if(temp->left){
                    array.push_back(temp->left->val);
                    q.push(temp->left);
                }
                else if(!temp->left)
                    array.push_back(INT_MAX);
                if(temp->right){
                    q.push(temp->right);
                    array.push_back(temp->right->val);
                }
                else if(!temp->right)
                    array.push_back(INT_MAX);
                size--;
            }
            print(array);
            for(int i = 0, j = array.size() - 1; i < j; i++, j--){
                if(array[i] != array[j])
                    return false;
            }
        }
        return true;
    }
};