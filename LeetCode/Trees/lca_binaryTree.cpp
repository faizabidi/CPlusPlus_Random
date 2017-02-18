// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?tab=Description

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
    
    // Find all ancestors
    bool findAncestors(TreeNode *temp, TreeNode *val, std::vector<TreeNode *> &path){
        if(!temp)
            return false;
        if(temp == val){
            path.push_back(temp);
            return true;
        }
        // Find if present in left sub-trees
        if(findAncestors(temp->left, val, path)){
            path.push_back(temp);
            return true;
        }
        // Find if present in right sub-trees
        else if(findAncestors(temp->right, val, path)){
            path.push_back(temp);
            return true;
        }
        return false;
    }   
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        // Find all ancestors of both nodes
        // And take the intersection
        if(!root)
            return NULL;
            
        std::vector<TreeNode *> p_ancestors, q_ancestors;
        TreeNode * lca;
        
        // p's ancestors
        findAncestors(root, p, p_ancestors);
        
         // q's ancestors
        findAncestors(root, q, q_ancestors);
        
        // Reverse the vectors to start at the top
        std::reverse(p_ancestors.begin(), p_ancestors.end());
        std::reverse(q_ancestors.begin(), q_ancestors.end());
        
        std::cout << p->val << "'s ancestors are:";
        for(int i = 0; i < p_ancestors.size(); i++)
            std::cout << p_ancestors[i]->val << " ";
        std::cout << std::endl;
        
        std::cout << q->val << "'s ancestors are:";
        for(int i = 0; i < q_ancestors.size(); i++)
            std::cout << q_ancestors[i]->val << " ";
        std::cout << std::endl;
        
        // Find out the last common element
        for(int i = 0; i < p_ancestors.size() && i < q_ancestors.size(); i++){
            if(p_ancestors[i] != q_ancestors[i]){
                lca = p_ancestors[i - 1];
                break;
            }
            else 
                lca = p_ancestors[i];
        }
        return lca;
    }
};