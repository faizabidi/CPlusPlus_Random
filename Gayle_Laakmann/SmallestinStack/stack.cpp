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
	last = -1;
}

bool Stack::isEmpty () const 
{ 
	//check if last is -1
	return last == -1; 
}

bool Stack::isFull () const	
{ 
	//check if last is full or equal to the maximum size
	return last == (maxStackSize - 1);
}

void Stack::push (int item)
{
	//if stack is empty
	if (isEmpty ())
	{
		last = 0;
		list[last] = min[last] = item;
		return;
	}

	//if stack is not empty and not full
	if (!isFull () && !isEmpty ())
	{
		last++;
		list[last] = item;
		if (item < min[last - 1])
			min[last] = item;
		else
			min[last] = min[last - 1];
		return;
	}
	
	//else, stack would be full
	std::cout << "Stack is full! Can't add more\n";
}

void Stack::pop ()
{
	if (isEmpty ())
	{
		std::cout << "Stack is empty!\n";
		return;
	}

	//if stack is not empty
	last--;
}


int Stack::peek ()
{
	//if stack is empty
	if (isEmpty ())
	{
		std::cout << "Stack is empty!\n";
		return -999;
	}
	else
		return list[last];
}

int Stack::minimum ()
{
	if (!isEmpty ())
		return min[last];
	else
	{
		std::cout << "Stack is empty!\n";
		return -999;
	}
}

Stack::~Stack ()
{
	delete[] list;
}