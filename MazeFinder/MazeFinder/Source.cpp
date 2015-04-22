#include "MazeFinder.h"
#include <iostream>
#include <conio.h>
using namespace std;

void printMaze(Maze * maze);


//The variables are named argc (argument count) and argv (argument vector) command arguments passed
int main(int argc, char** argv)
{
	//declare the maze
	//pointer to maze
	//referencing to maze
	Maze maze(argv[1]);
	Maze * pointerToMaze;
	pointerToMaze = &maze;


	//calling on MazeFinder
	//pointing to maze
	//calling on the Solve method
	MazeFinder finder(pointerToMaze);
	finder.Solve();


	//calling from the print maze function
	printMaze(pointerToMaze);

	//when the maze is solved 
	//asks to save 
	//press y....anything else entered will result in the else statement
	//.....incorrect pin, press exit
	cout << "Maze solved !" << endl << "would you like to save ? " << endl;

	//gets character directly from keyboard
	if (_getch() == 'y')
	{
		maze.saveMaze();

		cout << "Maze saved !!" << endl;
	}
	else
	{
		cout << "Incorrect input, it did not save" << endl;
	}
	cout << "press any key to exit" << endl;

	return 0;
}


//******PRINT MAZE
void printMaze(Maze * maze)
{
	for (int x = 0; x < maze->GetYLength(); x++)
	{
		for (int y = 0; y < maze->GetXLength(); y++)
		{
			cout << maze->GetMazeAt(x, y);
		}
		cout << endl;
	}
}