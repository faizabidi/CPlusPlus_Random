//#include "BST.cpp"
#include "BST2.cpp"
#include <iostream>

int main ()
{
	int array[10] = {3, 65, 2, 0, 67, -56, 23, 45, 654, 1000};

	BST tree, tree1;

	//add stuff to tree
	for (int i = 0; i < 10; i ++)
		tree.addLeaf (array[i]);

	tree.printInOrder ();

	if ( tree.isBalanced2() )
		std::cout << "\nTree is balanced!\n";
	else
		std::cout << "\nTree is not balanced!\n";

	tree1.addLeaf (12);
	tree1.addLeaf (11);
	tree1.addLeaf (13);
	tree1.printInOrder ();

	if ( tree1.isBalanced2() )
		std::cout << "\nTree is balanced!\n";
	else
		std::cout << "\nTree is not balanced!\n";

	return 0;
}