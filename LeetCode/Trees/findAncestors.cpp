bool findAncestors_helper(node *root, int val, std::vector<int> &ancestors){
    if(!root)
        return false;
    if(root->data == val)
        return true;
    // If found in left sub-tree
    if(findAncestors_helper(root->left, val, ancestors){
        ancestors.push_back(root->data);
        // We need to return true else it will again start of 
        // as false for one node above the found on
        // Think about it if you don't understand
        return true;
    }
    // If foudn in right sub-tree 
    if(findAncestors_helper(root->right, val, ancestors)){
        ancestors.push_back(root->data);
        return true
    }
    return false;
}

std::vector<int> findAncestors(node *root, int val){
    std::vector<int> ancestors;
    findAncestors_helper(root, val, ancestors);
    return ancestors;
}