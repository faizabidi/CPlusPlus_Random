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

	std::cout << "Enter node to be delete: ";
	int data;
	std::cin >> data;

	//obj.search (data);
	obj.deleteKey (data);

	return 0;
}