#include "MazeFinder.h"

	MazeFinder::MazeFinder(Maze * maze) : maze(maze)
	{
		//we are telling the finder where the begining of the maze is
		//putting value on top of the stack
		//'#' is the character we are using
		stack.Push(stackNode(1, 0)); //starting coords
		maze->SetMazeAt('#', stack.getTop().GetX(), stack.getTop().GetY());
	}


	//********SOLVE
	void MazeFinder::Solve()
	{
		//while we are not at the end of the maze
		//-2 because it is zero based and consider x and y
		while (stack.getTop().GetY() < maze->GetXLength() - 2)
		{
			//if move is available
			//then take the move
			if (moveAvailable())
			{
				takeMove();
				maze->SetMazeAt('#', stack.getTop().GetX(), stack.getTop().GetY());
			}

			else
			{
				//if no moves are available...back track
				//maze will select SetMazeAtfunction
				//then we use 'pop' to remove the top stack 
				//we are now back tracking
				maze->SetMazeAt('x', stack.getTop().GetX(), stack.getTop().GetY());
				stack.pop();
			}
		}
	}


	//******IS MOVE AVAILABLE
	bool MazeFinder::moveAvailable()
	{
		int x = stack.getTop().GetX();
		int y = stack.getTop().GetY();

		//x-1 is safe gaurding us from an exception
		//if x-1 isnt greater than 0....dont even bother going forward
		//look for another spot to move
		//if no spots to mkove go backwards (pop)
		//&& and forward is seeing if we can actually move there
		//if so ...do it
		if (x - 1 > 0 && maze->GetMazeAt(x - 1, y) == ' ')
		{
			return true;
		}
		else if (x + 1 < maze->GetYLength() && maze->GetMazeAt(x + 1, y) == ' ')
		{
			return true;
		}

		//y-1 is safe gaurding us from an exception
		//if y-1 isnt greater than 0....dont even bother going forward
		//&& and forward is seeing if we can actually move there
		//if so ...do it
		else if (y - 1 > 0 && maze->GetMazeAt(x, y - 1) == ' ')
		{
			return true;
		}
		else if (y + 1 < maze->GetXLength() && maze->GetMazeAt(x, y + 1) == ' ')
		{
			return true;
		}

		//return false incase there are no moves
		return false;
	}


	//**********TAKE MOVE
	//this function happens when it returns true
	void MazeFinder::takeMove()
	{
		int x = stack.getTop().GetX();
		int y = stack.getTop().GetY();

		//x-1 is safe gaurding us from an exception
		//if x-1 isnt greater than 0....dont even bother going forward
		//&& and forward is seeing if we can actually move there
		//if so ...do it
		if (x - 1 > 0 && maze->GetMazeAt(x - 1, y) == ' ')
		{
			stack.Push(stackNode(x - 1, y));
		}
		else if (x + 1 < maze->GetYLength() && maze->GetMazeAt(x + 1, y) == ' ')
		{
			stack.Push(stackNode(x + 1, y));
		}

		//y-1 is safe gaurding us from an exception
		//if y-1 isnt greater than 0....dont even bother going forward
		//&& and forward is seeing if we can actually move there
		//if so ...do it
		else if (y - 1 > 0 && maze->GetMazeAt(x, y - 1) == ' ')
		{
			stack.Push(stackNode(x, y - 1));
		}
		else if (y + 1 < maze->GetXLength() && maze->GetMazeAt(x, y + 1) == ' ')
		{
			stack.Push(stackNode(x, y + 1));
		}
	}



