// https://www.hackerrank.com/challenges/tree-top-view

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root){
    if(!root)
        return;
    std::vector<int> left, right;
    node *temp = root;
    left.push_back(temp->data);
    while(temp->left){
        left.push_back(temp->left->data);
        temp = temp->left;
    }
    temp = root;
    while(temp->right){
        right.push_back(temp->right->data);
        temp = temp->right;
    }
    std::vector<int> result;
    for(int i = left.size() - 1; i >= 0; i--)
        result.push_back(left[i]);
    for(int j = 0; j < right.size(); j++)
        result.push_back(right[j]);
    for(int k = 0; k < result.size(); k++)
        std::cout << result[k] << " ";
}
