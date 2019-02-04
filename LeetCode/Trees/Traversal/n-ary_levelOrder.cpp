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
    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>> matrix;
        if(!root)
            return matrix;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> array;
            while(size > 0){
                Node *temp = q.front();
                q.pop();
                size--;
                array.push_back(temp->val);
                for(int i = 0; i < temp->children.size(); i++)
                    q.push(temp->children[i]);
            }
            matrix.push_back(array);
        }
        return matrix;
    }
};