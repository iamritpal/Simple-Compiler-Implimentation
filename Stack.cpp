#include "Stack.hpp"

/*
	Stack constructor
	Creates stack object with size specified as parameter.
*/

Stack::Stack(int max)
{
	nmbItems = 0;
	StackVector.resize(max);
}

Stack::~Stack()
{}

/*
	push() routine
	Pushes new value onto stack vector.
	Resized stac vector to double the size in case stack overflow situation occurs.
*/

void Stack::push(int value)
{
	if (nmbItems >= StackVector.capacity())		// Stack vector capacity is full
		StackVector.resize(StackVector.capacity()*2);	// Double StackVector Size

	StackVector[nmbItems] = value;
	nmbItems++;
}


/*
	pop() routine
	Returns 1: When succefully popped value into ptr variable
			0: When stack underflow occurs, e.g. trying to pop empty stack
*/

int Stack::pop(void)
{
	if (nmbItems > 0)	// Stack is not empty
	{
		nmbItems--;
		return StackVector[nmbItems];
	}
	cout << "Stack underflow!" << endl;
	return 0;
}

int Stack::top(void)
{
	if (nmbItems > 0)	// Stack is not empty
	{
		return StackVector[nmbItems-1];
	}
	return 0;
}

int Stack::isEmpty(void)
{
	return(nmbItems == 0);
}
