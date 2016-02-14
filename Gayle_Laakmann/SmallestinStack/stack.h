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
	bool isEmpty () const;
	
	//check if stack is full
	bool isFull () const;

	//reset main stack
	void initializeStack ();

	//add item to specific stack
	void push (int item);

	//remove item from stack
	void pop ();

	//return the top of the stack
	int peek ();

	int minimum ();

	//destructor
	~Stack();

private:
	//how big the stack would be
	int maxStackSize;

	//keep track of the top of the three stacks
	int last;

	//array to store stuff
	int *list;

	//array to store minimum
	int *min;
};
#endif