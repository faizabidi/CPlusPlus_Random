#ifndef stack_h
#define stack_h

class Stack
{
public:
	//constructor
	//size of stack
	Stack (int size);

	//const means this function will not modify any member variable of this class
	//check is stack is empty
	bool isEmpty (int stackNum) const;
	
	//check if stack is full
	bool isFull (int stackNum) const;

	//reset main stack
	void initializeStack ();

	//add item to specific stack
	void push (int stackNum, int item);

	//remove item from stack
	void pop (int stackNum);

	//return the top of the stack
	int peek (int stackNum);

	//destructor
	~Stack();

private:
	//how big the stack would be
	int maxStackSize;

	//keep track of the top of the three stacks
	int last[3];

	//array to store stuff
	int *list;
};
#endif