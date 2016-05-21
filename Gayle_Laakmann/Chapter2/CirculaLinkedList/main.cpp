#include <iostream>
#include "node.cpp"

int main ()
{
	CircularLinkedList obj;
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

	obj.ReturnNodeAtBeginningOfLoop ();

	return 0;
}