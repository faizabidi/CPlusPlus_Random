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
    void preorder(vector<int> &array, Node *root){
        if(!root)
            return;
        // Add to array
        array.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++)
            preorder(array, root->children[i]);
    }
    vector<int> preorder(Node* root){
        vector<int> array;
        preorder(array, root);
        return array;
    }
};