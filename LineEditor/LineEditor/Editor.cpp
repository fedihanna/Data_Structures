#include "Editor.h"



//Editor.cpp ...telling how the functions from the "Editor.h" will do tteir jobs
Editor::Editor()
{
	this->numLines = 0;
	this->currentLine = 0;
}


Editor::~Editor()
{

}


//*******GET FILE
void Editor::getFile(string filePath)
{
	//****INPUT THE STREAM
	ifstream readFromFile(filePath);
	string readBuffer; //declaring a string readBuffer 

	//if file is open, make the link list
	int line = 0;
	if (readFromFile.is_open())
	{
		while (!readFromFile.eof())
		{
			
			getline(readFromFile, readBuffer);

			if (line == 0)
			{
				list.insertAsFirstElement(readBuffer);
			}
			else
			{
				list.insert(readBuffer);
			}

			line++;
			this->numLines++;
			
		}
		this->currentLine = (this->numLines - 1);
		readFromFile.close();
	}
	

}


//*******SAVE FILE
void Editor::saveFile(string filePath)
{
	
		//******OUTPUT THE STREAM
		ofstream writeToFile;
		writeToFile.open(filePath);

		//loop for going through the file
		for (int i = 0; i < this->numLines; i++)
		{
			writeToFile << getLine(i) << endl;
		}
		//writeToFile << userInput;
		writeToFile.close();
}

string Editor::getLine(int lineNum)
{
	return list.getLine(lineNum);
}

int Editor::getNumLines()
{
	return this->numLines;
}

int Editor::getCurrentLine()
{
	return this->currentLine;
}



void Editor::setCurrentLine(int newLine)
{
	this->currentLine = newLine;
}


void Editor::insertBeforeIndex(string newLine, int lineNum)
{
	list.insertBeforeIndex(newLine, lineNum);
	this->numLines++;
}

void Editor::substitute(string newLine, int lineNum)
{
	list.substitute(newLine, lineNum);
}

void Editor::deleteElement(int lineNum)
{
	list.deleteElement(lineNum);
	this->numLines--; //deleting one line
}

