#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Editor.h"

using namespace std;

string menu(int currentLine);
string getLine();

//****MAIN

//E:\IT COURSE 2015 - 16 (PART 4)\PROG 2400 Hal O'Connell\LineEditor\LineEditor\hardLuckWoman.txt
int main(int argc, char** argv)
{
	Editor editor;
	editor.getFile(argv[1]);


	while (true)
	{


		//Parsing the command
		string buffer;
		vector<string> arguments;
		istringstream ss(menu(editor.getCurrentLine()));
		system("cls");

		while (ss >> buffer)

		{
			arguments.push_back(buffer);
		}

		string commandLetter = arguments.at(0);
		int numArgs = arguments.size(), argNum1, argNum2;

		if (numArgs == 2 || numArgs == 3)
		{
			argNum1 = atoi(arguments.at(1).c_str());
		}
		 if (numArgs == 3)
		{
			argNum2 = atoi(arguments.at(2).c_str());
		}

		//********************V
		if (commandLetter == "v")
		{
			for (int i = 0; i < editor.getNumLines(); i++)
			{
				cout << i << ":  " << editor.getLine(i) << endl;
			}
		}

		//**************************I
		else if (commandLetter == "i")
		{
			if (numArgs == 2)

			{
				editor.insertBeforeIndex(getLine(), argNum1);
			}
			else
			{
				editor.insertBeforeIndex(getLine(), editor.getCurrentLine());
			}
		}

		//***********************S
		else if (commandLetter == "s")
		{
			if (numArgs == 2)

			{
				editor.substitute(getLine(), argNum1);
			}
			else
			{
				editor.substitute(getLine(), editor.getCurrentLine());
			}

		}
		//*********************D
		else if (commandLetter == "d")
		{
			if (numArgs == 3)
			{
				for (int i = argNum1; i < argNum2; i++)
				{
					editor.deleteElement(argNum1);
				}
			}
			else if (numArgs == 2)
			{

				editor.deleteElement(argNum1);
			}
			else
			{
				editor.deleteElement(editor.getCurrentLine());
			}
		}


		//************************L
		else if (commandLetter == "l")
		{
			if (numArgs == 3)
			{
				for (int i = argNum1; i <= argNum2; i++)
				{
					cout << i << ":  " << editor.getLine(i) << endl;
				}
			}
			else if (numArgs == 2)
			{
				cout << argNum1 << ":  " << editor.getLine(argNum1) << endl;
			}
			else
			{
				cout << editor.getCurrentLine() << ":  " << editor.getLine(editor.getCurrentLine()) << endl;
			}
		}


		//**************************G
		else if (commandLetter == "g")
		{
			if (numArgs == 2)
			{
				editor.setCurrentLine(argNum1);
			}
		}


		//************************E
		else if (commandLetter == "e")
		{
			editor.saveFile(argv[2]);

			for (int i = 0; i < editor.getNumLines(); i++)
			{
				editor.deleteElement(0);
			}
			return 0;
		}


		//********************Q
		else if (commandLetter == "q")
		{
			for (int i =0; i < editor.getNumLines(); i++)
			{
				editor.deleteElement(0);
			}
			return 0;
		}
	}
}




//*******MENU
string menu(int currentLine)
{


	cout << "EDIT \n";
	cout << endl << "Current Line: " << currentLine << endl;
	cout << " Commands: I, D, V, G, L, S, E, Q." << endl;

	string choice;
	getline(std::cin, choice);
	return choice;
}

string getLine()
{
	cout << " Enter a line to be inserted." << endl;

	string line;
	getline(std::cin, line);
	return line;
}








