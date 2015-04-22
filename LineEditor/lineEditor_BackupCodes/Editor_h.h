#pragma once
#include <fstream>
#include "LinkedList.h"
#include <string>

using namespace std;


class Editor
{

private:
	int numLines, currentLine;
	LinkedList list;


public:
	Editor();
	~Editor();

	void getFile(string filePath);
	void saveFile(string filePath);


	string getLine(int lineNum);

	int getNumLines();
	int getCurrentLine();

	void setCurrentLine(int newLine);
	void insertLine(int lineBefore);

	void insertBeforeIndex(string newLine, int lineNum);
	void substitute(string newLine, int lineNum);

	void deleteElement(int lineNum);
};

