// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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

// Recursive solution
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

// Iterative solution
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        vector<int> array;
        stack<Node *> s;
        s.push(root);
        while(!s.empty()){
            Node *temp = s.top();
            s.pop();
            array.push_back(temp->val);
            for(int i = temp->children.size() - 1; i >= 0; i--)
                s.push(temp->children[i]);
        }
        return array;
    }
};