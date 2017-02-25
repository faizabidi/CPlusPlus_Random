// https://www.hackerrank.com/challenges/binary-search-tree-insertion

/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node *createLeaf(int value){
    node *newNode = new node;
    newNode->left = newNode->right = NULL;
    newNode->data = value;
    return newNode;
}

node *insert(node * root, int value){
    if(!root){
        root = createLeaf(value);
        return root;
    }
    
    node *newNode = createLeaf(value);
    node *temp = root;
    node *temp_parent;
        
    while(temp){
        if(temp->data > newNode->data){
            temp_parent = temp;
            temp = temp->left;
        }
        else{
            temp_parent = temp;
            temp = temp->right;
        }
    }
    
    if(temp_parent->data > newNode->data)
        temp_parent->left = newNode;
    else
        temp_parent->right = newNode;
    
   return root;
}

// Recursive
// Recursive
node *insert(node * root, int value){
    if(!root){
        root = createLeaf(value);
        return root;
    }
    if(root->data > value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}