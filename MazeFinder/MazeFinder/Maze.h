#pragma once
#include <fstream>
using namespace std;



class Maze
{
private:
	//class level properties.
	//declaring input and output
	//character sequence pointing to maze 
	// x and y are set to 0
	ifstream inputstream;
	ofstream outputstream;
	char **maze, templine[2048]; //charater array pointing to maze which is coming in on a 2GB buffer 
	//----             //||
	int numberOfLines = 0, lineLengths = 0;

public:
	//**********DECLARING INPUT FILE PATH
	Maze(char *inputfilepath);
	char GetMazeAt(int x, int y);
	void SetMazeAt(char token, int x, int y);
	int GetXLength();
	int GetYLength();
	void saveMaze();
};