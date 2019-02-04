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
// Itreative solution
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        vector<int> array;
        stack<Node *> s;
        s.push(root);
        while(!s.empty()){
            Node *temp = s.top();
            s.pop();
            for(int i = 0; i < temp->children.size(); i++)
                s.push(temp->children[i]);
            array.push_back(temp->val);
        }
        reverse(array.begin(), array.end());
        return array;
    }
};