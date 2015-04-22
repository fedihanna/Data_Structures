#include "Stack.h"
#include "stackNode.cpp"
#include "Maze.h"

//declaring class maze finder
class MazeFinder
{
private:
	Stack stack;
	Maze * maze;


public:
	MazeFinder(Maze * maze);



	void Solve();
	bool moveAvailable();
	void takeMove();
};