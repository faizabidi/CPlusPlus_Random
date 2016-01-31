#ifndef DLL_Node_h
#define DLL_Node_h

class DLLNode
{
private:
	struct node
	{
		int data;
		node *next;
		node *prev;
	};
	//head node
	node *head;

public:
	DLLNode ();
	node *CreateNode (int key);
	void AppendAtBack (int a);
	void AppendInFront (int a);
	void PrintList ();
	node *SearchNode (int key);
	void DeleteNode (int a);
	void DisplayNodesReverse ();
    void RemoveDuplicates ();
    void ReverseList ();
    void Swap(node *a, node *b);
    void BubbleSortList ();
    void SelectionSortList ();
};
#endif