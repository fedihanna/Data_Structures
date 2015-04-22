#include "stackNode.cpp"
#include <cstring>

class Stack

{

private:
	int size;
	stackNode * stack;

public:
	Stack();
	void Push(stackNode newnode);
	void pop();
	stackNode getTop();

};
	