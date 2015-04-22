#pragma once //to be included once in a complilation
#include <string>

using namespace std;


class Node
{

	//node constructed pointing to next 
public:
	Node *next;
	string data;

	Node(); 
	~Node(); 
};