// https://www.hackerrank.com/challenges/30-binary-search-trees

#include <iostream>
#include <cstddef>	

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if(data <= root->data){
                cur = insert(root->left, data);
                root->left = cur;
            }
            else{
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }
    int getHeight(Node* root){
        if(root == NULL)
            return -1;
        int left_depth = getHeight(root->left) + 1;
        int right_depth = getHeight(root->right) + 1;
        int max_height = std::max(left_depth, right_depth);
        return max_height;
    }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0){
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    std::cout << height;

    return 0;
}