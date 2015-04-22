#pragma once
#include <string>
using namespace std;

class Node
{
public:
	Node *next;
	string data;
	Node();
	~Node();
};