#include "Maze.h"


	//**********DECLARING INPUT FILE PATH
	Maze::Maze(char *inputfilepath)
	{
		//opening the text file
		inputstream.open(inputfilepath);

		// while we are not at the end of the text file
		while (!inputstream.eof())
		{
			//get a line
			inputstream.getline(templine, 2048);
			//increment the number of total lines
			numberOfLines++;
			//check the length of the line
			lineLengths = strlen(templine) + 1;
		}


		//now we make the first dimension of 
		//the character array to be as long as 
		//the total number of lines in the text file
		//and go through the elements
		//to create the second dimension
		//to be as long as the lines in the text file
		maze = new char*[numberOfLines];
		for (int i = 0; i < numberOfLines; i++)
		{
			maze[i] = new char[lineLengths];
		}
		//returning to the begining of the file
		inputstream.clear();
		             //seekg ...Sets the position of the next character to be extracted from the input stream.
		inputstream.seekg(0, ios::beg); //input/output stream back to the begining

		//now we can copy the data from the text file into the array
		int line = 0;
		// while we are not at the end of the text file
		while (!inputstream.eof())
		{
			//get a line
			inputstream.getline(templine, 2048);

			//strcpy is old and depreciated
			//so you must go to the properties of the project 
			//right click on preprocessor
			//enter the  line _CRT_SECURE_NO_WARNINGS
			strcpy(maze[line], templine);
			line++;

		}//end while loop
	}// end Maze


	//*****GET MAZE AT
	char Maze::GetMazeAt(int x, int y)
	{
		return maze[x][y];
	}


	//*********SET MAZE AT
	//token is the # sign or x
	void Maze::SetMazeAt(char token, int x, int y)
	{
		maze[x][y] = token;
	}


	//*******GET X LENGTH
   int Maze::GetXLength()
	{
	   //------------
		return lineLengths;
	}


	//********GET Y LENGTH
   int Maze::GetYLength()
	{

	   // ||
	   // ||
	   // ||
		return numberOfLines;
	}


	//******SAVE MAZE
   void Maze::saveMaze()
	{
		//saves to the desktop
		outputstream.open("C:\\Users\\W0004121\\Desktop\\solvedMaze.txt");

		for (int x = 0; x < numberOfLines; x++)
		{
			outputstream << maze[x] << endl;
		}

	}// end savedMaze
