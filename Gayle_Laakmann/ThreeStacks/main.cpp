
#include <iostream>
#include "stack.cpp"

int main ()
{
	std::cout << "How many elements in the entire stack? ";
	unsigned int numOfElem = 0;
	std::cin >> numOfElem;

	Stack firststack (numOfElem);

	firststack.push (1,1);
	firststack.push (1,2);
	firststack.push (1,3);

	firststack.push (2,4);
	firststack.push (2,5);
	firststack.push (2,6);
	
	firststack.push (3,7);
	firststack.push (3,8);
	firststack.push (3,9);

	firststack.pop (1);
	firststack.pop (2);
	firststack.pop (3);

	std::cout << "The top elements in the three stacks are "<< firststack.peek(1) << " " << firststack.peek (2) << " " << firststack.peek (3);
	return 0;
}