/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void postorderTraversal(vector<int> &array, Node *root){
        if(!root)
            return;
        for(int i = 0; i < root->children.size(); i++)
            postorderTraversal(array, root->children[i]);
        // Add to array
        array.push_back(root->val);
    }
    vector<int> postorder(Node* root){
        vector<int> array;
        postorderTraversal(array, root);
        return array;
    }
};