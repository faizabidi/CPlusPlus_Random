// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

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
    int maxDepth(Node* root){
        if(!root)
            return 0;
        int depth = 0;
        // Apply BFS
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            depth++;
            while(k > 0){
                Node *temp = q.front();
                q.pop();
                vector<Node *> tempArray = temp->children;
                // Push all the children to the queue
                for(int i = 0; i < tempArray.size(); i++)
                    q.push(tempArray[i]);
                k--;
            }
        }
        return depth;
    }
};