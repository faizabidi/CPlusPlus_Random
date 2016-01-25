class BST
{
private:
    
    //for creating nodes. Each object coult store a key, and will...
    //...have two pointers
    struct node
    {
        int key;
        node *left;
        node *right;
    };
    //root node
    node *root;
    
    //CreateLeaf is in the private section since it returns node *...
    //..which is private to class
    node *CreateLeaf (int key);
    
    //add leaf to tree 
    void AddLeafPrivate (int key, node *Ptr);
    
    //print left child, root, and right child
    void PrintInOrderPrivate (node *Ptr);
    
    //pointer to the node needed
    node *SearchNodePrivate (int key, node *Ptr);

    //smallest node in the tree
    int SmallestNodePrivate(node *Ptr);

    //private function to delete a node in a tree
    void RemoveNodePrivate (int key, node *parent);

    //function to delete the root node
    void RemoveRootMatch();

    //function to remove a non-root node
    void RemoveMatch (node *parent, node *match, bool check);

    int HeightOfTreePrivate (node *Ptr);
    
public:
    
    //default constructor
    BST();
    //function to call the private AddLeafPrivate function
    void AddLeaf (int key);
    
    //function to call the private PrintInOrderPrivate function
    void PrintInOrder ();
    
    //return a pointer to a node
    node *SearchNode (int key);

    //print children of the nodes with value = key
    void PrintChildren (int key);

    //print smallest node in the tree
    int SmallestNode ();

    //function to call the private function to remove a root node
    void RemoveNode (int key);

    int HeightOfTree ();
};