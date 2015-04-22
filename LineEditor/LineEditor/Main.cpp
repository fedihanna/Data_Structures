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
//how command line arguments are passed to main()
//argc (argument count) and argv (argument vector) 
int main(int argc, char** argv)
{
	Editor editor;
	editor.getFile(argv[1]); //opening the file and storing contents as a link list in editor class

	bool valid = true;
	while (true)
	{ 		
		while (valid)
		{
			//Parsing the command
			string buffer;
			vector<string> arguments;
			istringstream ss(menu(editor.getCurrentLine())); //getting a command from console 
            system("cls"); //clearing the screen

			while (ss >> buffer)
			{
				arguments.push_back(buffer); //splitting the command string so 
				//arguments.at(0) = "d"
				//arguments.at(1) = "5"
				//arguments.at(2) = "10"

				//because we have to convert the numbers to integers and 
				//they are strings when entered in console
			}

			string commandLetter = arguments.at(0);
			int numArgs = arguments.size(), argNum1, argNum2;
			
			if (numArgs == 2 || numArgs == 3)
			{


//*************VALIDATE FOR ARG 1
				// help from google
				const char *firstNum = arguments.at(1).c_str();//converting string to an integer
				for (int i = 0; i < arguments.at(1).length(); i++)
				{
					if (!isdigit(firstNum[i]))
						valid = false;
				}
				argNum1 = atoi(arguments.at(1).c_str());//converting string to an integer
			}
			if (numArgs == 3)
			{


//***************VALIDATE FOR ARG 2
				//help from google
			const char *secondNum = arguments.at(2).c_str();
			for (int i = 0; i < arguments.at(2).length(); i++)
			{
				if (!isdigit(secondNum[i]))
					valid = false;
			}
				argNum2 = atoi(arguments.at(2).c_str());//converting string to an integer
			}



//*******V (shows the list)
			if (commandLetter == "v")
			{
				//printed the entire link list in console
				//using the editor to get the number of lines
				for (int i = 0; i < editor.getNumLines(); i++)
				{
					                    //space is required between letter and number commands
					std::cout << i << ":  " << editor.getLine(i) << endl;
				}
			}



//********I (inserts lines)
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



//******S (substitute lines)
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




//******D (delete elements)
			else if (commandLetter == "d")
			{
				//if there is 2 sets of numbers
				if (numArgs == 3)
				{
					for (int i = argNum1; i < argNum2; i++)
					{
						editor.deleteElement(argNum1);
					}
				}
				//if there is one set of numbers
				else if (numArgs == 2)
				{

					editor.deleteElement(argNum1);
				}
				else
				{
					editor.deleteElement(editor.getCurrentLine());
				}
			}




//******L (lists the line)
			else if (commandLetter == "l")
			{
				if (numArgs == 3) //refering to number of line inputed by user
				{
					             //1st number      //2nd number
					for (int i = argNum1; i < argNum2; i++)
					{
						std::cout << i << ":  " << editor.getLine(i) << endl;
					}
				}
				            //1st number (0 based)
				else if (numArgs == 2)
				{
					         
					std::cout << argNum1 << ":  " << editor.getLine(argNum1) << endl;
				}
				else
				{
					std::cout << editor.getCurrentLine() << ":  " << editor.getLine(editor.getCurrentLine()) << endl;
				}
			}




//*******G (go to line specified)
			else if (commandLetter == "g")
			{
				if (numArgs == 2)
				{
					editor.setCurrentLine(argNum1);
				}
			}




//********E (exit and save)
			else if (commandLetter == "e")
			{
		        //calls on "saveFile" function
				//bringing in that vector string again
				editor.saveFile(argv[2]); 

				//brings in the list form console
				for (int i = 0; i < editor.getNumLines(); i++)
				{
					//calls on delete function from Editor
					editor.deleteElement(0);
				}
				return 0;
			}




//*******Q (exit without saving)
			else if (commandLetter == "q")
			{
				for (int i = 0; i < editor.getNumLines(); i++)
				{
					editor.deleteElement(0);
				}
				return 0;
			}



//*********DISPLAYS VALIDATION FOR COMMAND LETTER 
			else {
				std::cout << "Sorry, invalid command." << endl << endl;
			}



//*********DISPLAYS VALIDATION FOR NUMBERS
		}
		std::cout << "Sorry, commands can only be followed by numbers" << endl << endl;
		valid = true;
	}
}




//*******MENU
string menu(int currentLine)
{

	std::cout << "EDIT \n";
	std::cout << endl << "Current Line: " << currentLine << endl;
	std::cout << "I: (Insert text)" << endl;
	std::cout << "D: (Delete lines)" << endl;
	std::cout << "V: (Display lines)" << endl;
	std::cout << "G: (Go to a line specified)" << endl;
	std::cout << "L: (Lists the line)" << endl;
	std::cout << "S: (Subtitute line)" << endl;
	std::cout << "E: (Exit and Save)" << endl;
	std::cout << "Q: (Exit without saving)" << endl;

	string choice;
	getline(std::cin, choice);
	return choice;
}

string getLine()
{
	std::cout << " Enter a line to be inserted." << endl;

	string line;
	getline(std::cin, line);
	return line;
}








