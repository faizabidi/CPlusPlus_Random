
#include <iostream>
#include "stack.cpp"

int main ()
{
	std::cout << "How many elements in the entire stack? ";
	unsigned int numOfElem = 0;
	std::cin >> numOfElem;

	Stack firststack (numOfElem);

	firststack.push (32);
	firststack.push (2);
	firststack.push (-76);
	firststack.push (897);
	firststack.push (0);
	firststack.push (4);

	std::cout << "The smallest element in the stack is " << firststack.minimum () << "\n";

	firststack.pop ();
	firststack.pop ();
	firststack.pop ();
	firststack.pop ();

	std::cout << "The smallest element in the stack is " << firststack.minimum () << "\n";

	return 0;
}