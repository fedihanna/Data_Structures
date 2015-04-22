#pragma once

class stackNode
{
	//declaring
private:
	int x;
	int y;

public:
	//constructing
	stackNode(){}
	stackNode(int x, int y) : x(x), y(y) {}
	
		int GetX()
		{
			return x;
		}

		int GetY()
		{
			return y;
		}
	
};