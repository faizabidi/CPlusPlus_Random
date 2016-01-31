#include<iostream>
#include "DLL_Node.h"
#include "DLL_Node.cpp"

int main()
{
	DLLNode list;
	list.AppendAtBack(12);
	list.AppendInFront(20);
	list.AppendInFront(20);
	list.AppendAtBack(12);
	list.AppendInFront(56);
	list.AppendAtBack(125);
	list.AppendAtBack(12);
	list.AppendAtBack(100);
	list.AppendAtBack(100);
	list.AppendAtBack(100);

	std::cout<<"Original list\n";
	list.PrintList();

	std::cout<<"Deleting node 125\n";
	list.DeleteNode(125);
	list.PrintList();

	
	std::cout<<"Removing duplicates\n";
	list.RemoveDuplicates();
	list.PrintList();


	std::cout<<"Printing reverse list\n";
	list.DisplayNodesReverse();

	std::cout<<"Original list\n";
	list.PrintList();

	std::cout<<"Actually reversing the list\n";
	list.ReverseList();
	list.PrintList();

	std::cout<<"Reversing the reversed list\n";
	list.DisplayNodesReverse(); 

	std::cout<<"Sorting the list\n";
	//list.BubbleSortList();
	list.SelectionSortList ();
	list.PrintList();
	
	return 0;
}