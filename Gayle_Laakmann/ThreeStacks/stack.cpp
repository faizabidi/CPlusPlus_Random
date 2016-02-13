#include "stack.h"

Stack::Stack (int size)
{
	maxStackSize = size;
	initializeStack ();

	//allocate array
	//it starts from 0 not 1
	list = new int [maxStackSize - 1];
}

void Stack::initializeStack () 
{ 
	//a new stack will always have last = -1
	for (unsigned int i = 0; i < 3; i++)
		last[i] = -1; 
}

bool Stack::isEmpty (int stackNum) const 
{ 
	//check if last is -1
	return last[stackNum - 1] == -1; 
}

bool Stack::isFull (int stackNum) const	
{ 
	//check if last is full or equal to the maximum size
	return last[stackNum - 1] == ((maxStackSize / 3) - 1); 
}

void Stack::push (int stackNum, int item)
{
	//if stack is empty
	if (isEmpty (stackNum))
	{
		last[stackNum - 1] = 0;
		list[ ( (stackNum - 1) * 3) + last[stackNum - 1] ] = item;
		return;
	}

	//if stack is not empty and not full
	if (!isFull (stackNum) && !isEmpty (stackNum))
	{
		last[stackNum - 1]++;
		list[ ( (stackNum - 1) * 3 ) + last[stackNum - 1] ] = item;
		return;
	}
	
	//else, stack would be full
	std::cout << "Stack is full! Can't add more\n";
}

void Stack::pop (int stackNum)
{
	if (isEmpty (stackNum))
	{
		std::cout << "Stack is empty!\n";
		return;
	}

	//if stack is not empty
	last[stackNum - 1]--;
}


int Stack::peek (int stackNum)
{
	//if stack is empty
	if (isEmpty (stackNum))
		return -999;
	else
		return list[ ( (stackNum - 1) * 3 ) + last [stackNum - 1]];
}

Stack::~Stack ()
{
	delete[] list;
}