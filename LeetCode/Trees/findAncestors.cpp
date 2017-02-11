bool findAncestors_helper(node *root, int val, std::vector<int> &ancestors){
    if(!root)
        return false;
    if(root->data == val)
        return true;
    if(findAncestors_helper(root->left, val, ancestors) || findAncestors_helper(root->right, val, ancestors))
        ancestors.push_back(root->data);
    return false;
}

std::vector<int> findAncestors(node *root, int val){
    std::vector<int> ancestors;
    findAncestors_helper(root, val, ancestors);
    return ancestors;
}