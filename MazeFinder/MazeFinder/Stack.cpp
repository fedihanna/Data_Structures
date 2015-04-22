#include "Stack.h"


	Stack::Stack()
	{
		size = 0;
		stack = new stackNode[size];
	}


	//******PUSH
	void Stack::Push(stackNode newnode)
	{
		//incrementing the size of the stack
		//...adding to the stack
		size++;

		//creating a new array, thats one element larger then the old array
		stackNode * newArr = new stackNode[size];

		//copying the old array into the new one 
		memcpy(newArr, stack, size * sizeof(stackNode));

		//deleting the old array
		delete[] stack;

		//assigning the new array to the old one 
		stack = newArr;

		//adding the new node to the array
		stack[size - 1] = stackNode(newnode);
	}


	//*******POP
	void Stack::pop()
	{
		//decrementing the size of the stack
		size--;

		//creating a new array, thats one element larger the the old array
		stackNode * newArr = new stackNode[size];

		//copying the old array into the new one 
		memcpy(newArr, stack, size * sizeof(stackNode));

		//deleting the old array
		delete[] stack;

		//assigning the new array to the old one 
		stack = newArr;
	}


	//return a stack node
	//allows user to see the top if the stack if it is neccesary
	stackNode Stack::getTop()
	{
		return stack[size - 1];
	}
