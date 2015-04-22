#include <iostream>
#include <chrono>
#include <ctime>


//****DEFINING ELEMENTS UP TO  1000
#define NUM_ELEMENTS 10000

using namespace std;
using namespace std::chrono; //chronological timer


//******SEQUNTAIL SEARCH
//this search compares each element until it reaches its target
//when target is reached...it will return true
//https://www.youtube.com/watch?v=Ij1eCQMOPO0
//https://www.youtube.com/watch?v=XSRp8aANXaY

static bool SeqSearch(int value, int * intArray)
{
	//loop running through elements
	//if i = the value
	//return it
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		if (intArray[i] == value)
		{
			return true;
		}
	}
}


//********BINARY SEARCH
//searches by splitting in the middle
//searches each side until number is found
//right and left sides keep getting split in the mmiddle until number is found
//https://www.youtube.com/watch?v=Ij1eCQMOPO0 
//https://www.youtube.com/watch?v=qoyARrLN_jQ

static bool BinSearch(int value, int * intArray)
{
	int left = 0; //left is 0
	int right = NUM_ELEMENTS; //NUM_ELEMENTS are set to right
	int i = (left + right) / 2; //reset the i to center

	//while we have not found the value and the left is less < right 
	while ((intArray[i] != value) && (left < right))
	{
		//if element is greater than value 
		//then move right
		//else move to left
		if (intArray[i] > value)
		{
			right = i - 1;
		}

		else
		{
			left = i + 1;
		}

		//reset the i to the center
		i = (left + right) / 2;
	}

	//if the left and right have not met
	//then we have hit the the number
	if (left <= right)
	{
		return true;
	}

	return false;	
}


//********MAIN
int main()
{
	//creating an array to search 
	int * intArray = new int[NUM_ELEMENTS];

	//every element is now assigned a value
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		intArray[i] = i;
	}

//*********CHRONO TIMER 
	//http://stackoverflow.com/questions/23896664/c-11-stdchrono-measure-time-elapsed
	//http://en.cppreference.com/w/cpp/chrono
	//http://stackoverflow.com/questions/8386128/how-to-get-the-precision-of-high-resolution-clock

	//creating a start time and end time variables
	high_resolution_clock::time_point start, end;

	//timing the search for all values
	//using the sequatail search
	//start clock
	start = high_resolution_clock::now();

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		//calls on SeqSearch function
		SeqSearch(i, intArray);

	}
	//end clock
	end = high_resolution_clock::now();

	cout << "Sequentail Search took: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds. \n";

	//timing the seach for all values
	//using the binary search
	//start clock
	start = high_resolution_clock::now();
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		//calls on BinSearch function
		BinSearch(i, intArray);

	}
	//end clock
	end = high_resolution_clock::now();

	cout << "Binary Search took: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds. \n";

	int i;
	cin >> i;
	return 0;
}