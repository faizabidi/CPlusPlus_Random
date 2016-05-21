#include <iostream>
#include "node.cpp"

int main ()
{
	LinkedList list;
	list.appendNodeBack (2);
	list.appendNodeBack (3);
	list.appendNodeBack (11);
	list.appendNodeBack (4);
	list.appendNodeBack (6);
	list.appendNodeBack (4);
	list.appendNodeBack (11);
	list.appendNodeBack (3);
	list.appendNodeBack (2);
	
	list.printList ();

	if (list.isPalindrome (list))
		std::cout << "List is a palindrome!\n";
	else
		std::cout << "List is NOT a palindrome!\n";

	return 0;
}