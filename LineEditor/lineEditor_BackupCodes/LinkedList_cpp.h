#include "LinkedList.h"




LinkedList::LinkedList()
{
	this->first = NULL;
}


LinkedList::~LinkedList()
{
}

//*****IS EMPTY
bool LinkedList::isEmpty()
{
	//want to see if the list is empty when we start off
	//if its empty return true
	//if it has values in it, return false
	if (this->first == NULL)
		return true;
	else
		return false;
}

//****INSERT AS FIRST LETTER
void LinkedList::insertAsFirstElement(string data)
{
	//creating a temporary node
	//pointing to a new number
	//the temp pointer is referencing data which is assigned by "string data"
	//the next node will be NULL 
	//after everything is inserted, the head is set to temp and the last is set to temp
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	
	this->first = temp;
}


//******INSERT
//inserting a string of data
void LinkedList::insert( string data)
{
	//creating a new node
	//pointing to a new number
	//the temp pointer is referencing data whic is assigned by "string data"
	//next node will be NULL
	
	    Node *temp = new Node;
		temp->data = data;
		temp->next = NULL;
		
		//making a new node "n" which will be the first node
		//while "n" is referencing "next" and it is not equal to NULL
		//then "n" will reference the next node
		//which is now the temporary node
		Node *n = first;
		while (n->next != NULL)
		{
			n = n->next;
		}
		n->next = temp;
		
}


//*******GET LINE
//getting an integer
string LinkedList::getLine(int lineNum)
{
	//declaring i to be used in the loop
	//new node is referencing first node
	//if "i" is not equal to a line Number
	//then have "n" pointing to the next node
	//then return as string data
	int i = 0;
	Node *n = this->first;


	while (i != lineNum)
	{
		n = n->next;
		i++;
	}
	return n->data;
}


//*****DELETE ELEMEMT
void LinkedList::deleteElement(int lineNum)
{
	//if no line is declared....delete line 0 (which should be default)
	if (lineNum == 0)
	{
		
		deleteFirstNode();
	}
	else
	{
		//a new node "n2" is made 
		//which can have access to first node
		int i = 0;
		Node *n2, *n = this->first;


		//if i is not equal to previous line number
		//then "n" can reference next 
		while (i != (lineNum - 1))
		{
			n = n->next;
			i++;
		}
		//storing a pointer to the line before the line to be deleted
		n2 = n;
		//incrementing to the line to be deleted
		n = n->next;
		//setting the next property of the line before this one, to be the line after this one
		//because the nodes could be between other nodes
		n2->next = n->next;
		//deleting this line
		delete n;
	}
	
}



//*****INSERT BEFORE INDEX
void LinkedList::insertBeforeIndex(string newLine, int lineNum)
{
	//declaring i
	//mad ea node which is refencing the first
	int i = 0;
	Node *n = this->first;

	//when i is not equal to previous line number
	//n node points to next node
	//new node is constructed below so user can type something
	while (i != (lineNum - 1))
	{
		n = n->next;
		i++;
	}

	//Make a new node to hold a new line.
	Node *newNode = new Node;
	newNode->data = newLine;
	//the new node will point to the index supplied (whatever user types)
	newNode->next = n->next;
	// the current node(before what the user types) will point to this new node
	n->next = newNode;
}


//********SUBSTITUTE
	void LinkedList::substitute(string newLine, int lineNum)
	{
		//declaring i
		//making to nodes that have access to the first
		int i = 0;
		Node *n2, *n = this->first;


		while (i != (lineNum - 1))
		{
			n = n->next;
			i++;
		}

		//Make a new node to hold a new line.
		//which can refernce data
		Node *newNode = new Node;
		newNode->data = newLine;


		//storing our grasp on the node before the node being replaced
		n2 = n;
		//Incrementing to node to be replaced
		n = n->next;

		//setting the node before this one to point to the new node
		n2->next = newNode;

		//Setting the new node to point to the next node
		newNode->next = n->next;

		//deleting the current node
		delete n;

	}

	void LinkedList::deleteFirstNode()
	{
		//"n" references first
		//this->first now references "next"
		//first node can now be deleted
		Node *n = this->first;
		this->first = this->first->next;
		delete n;
	}
	

