#pragma once
#include "Node.h"
#include <string>
using namespace std;

class LinkedList
{
private:

	//node constructed pointing at first node
	Node *first;


public:
	LinkedList();
	~LinkedList();

//*******FUNCTIONS WE ARE USING FOR LINK LIST
	bool isEmpty();
	void insertAsFirstElement(string data);
	void insert(string data);
	void deleteElement(int lineNum);
	string getLine(int lineNum);
	void insertBeforeIndex(string newLine, int lineNum);
	void substitute(string newLine, int lineNum);
	void deleteFirstNode();
};