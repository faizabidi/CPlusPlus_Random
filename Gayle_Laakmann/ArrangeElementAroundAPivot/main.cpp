#include <iostream>
#include "node.cpp"

int main ()
{
	LinkedList list;
	list.appendNodeFront (2);
	list.appendNodeFront (3);
	list.appendNodeFront (11);
	list.appendNodeFront (4);
	list.appendNodeFront (5);
	list.appendNodeFront (6);
	list.appendNodeFront (7);
	list.appendNodeFront (8);
	list.appendNodeFront (9);
	list.appendNodeFront (10);

	list.printList ();

	std::cout << "Enter pivot value: ";
	unsigned int pivot;
	std::cin >> pivot;
	list.ArrangeNodesAroundPivot (pivot);

	//list.printList();

	return 0;
}