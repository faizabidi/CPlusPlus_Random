#include <iostream>
#include "node.cpp"

int main ()
{
	LinkedList list;
	list.appendNodeFront (2);
	list.appendNodeFront (8);
	list.appendNodeFront (1);
	list.appendNodeFront (9);
	list.appendNodeFront (0);
	list.appendNodeFront (7);
	/*list.appendNodeFront (7);
	list.appendNodeFront (8);
	list.appendNodeFront (9);
	list.appendNodeFront (10);*/

	list.printList ();

	std::cout << "Enter pivot value: ";
	unsigned int pivot;
	std::cin >> pivot;
	list.ArrangeNodesAroundPivot (pivot);
	std::cout << std::endl;
	list.printList();

	return 0;
}