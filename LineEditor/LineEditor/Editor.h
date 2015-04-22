#pragma once
#include <fstream>
#include "LinkedList.h"
#include <string>

using namespace std;


//Editor.h header file ...telling us what Editor does
class Editor
{

	//declaring as private... so only accessible here 
private:
	int numLines, currentLine;
	LinkedList list;

	//can be accessed out side this class 
public:
	Editor();
	~Editor();


//*******FUNCTIONS FOR EDITING
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

