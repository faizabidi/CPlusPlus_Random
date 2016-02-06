#include <iostream>
#include "node.cpp"

int main ()
{
	LinkedList obj;
	obj.appendNodeBack (2);
	obj.appendNodeBack (3);
	obj.appendNodeBack (3);
	obj.appendNodeBack (4);
	obj.appendNodeBack (5);
	obj.appendNodeBack (6);
	obj.appendNodeBack (5);
	obj.appendNodeBack (2);
	obj.appendNodeBack (7);
	obj.appendNodeBack (9);

	obj.printList ();

	//std::cout << "Removing duplicates...\n";
	//obj.removeDuplicates ();
	std::cout << "Kth element from back to be deleted? ";
	unsigned int pos = 0;
	std::cin >> pos;
	obj.kthElementToLast (pos);
	obj.printList ();

	return 0;
}