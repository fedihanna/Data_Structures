#include <iostream>
#include <string>
#include "Tree.cpp"
#include <fstream>


//the text files from Hal S Drive
//put into my H Drive
#define DICTIONARY "E:\\IT COURSE 2015-16 (PART 4)\\PROG 2400 Hal O'Connell\\Assign_4b_Trees\\dictionary.txt"
#define DOCUMENT "E:\\IT COURSE 2015-16 (PART 4)\\PROG 2400 Hal O'Connell\\Assign_4b_Trees\\mispelled.txt"

using namespace std;

//********FILL TREE WITH DICIONARY WORDS
//this fills the binary tree with words in the dictionary.txt text file
void FillTreeWithDictionaryWords(Tree * tree)
{
	//creating a bool "taller" and set it to false
	//char is 8 bit character set that holds 512 values
	//fstream: Stream class to both read and write from/to files.
	//calls on dictionary from stored on e drive
	bool taller = false;
	char temp[512];
	std::fstream instream;
	instream.open(DICTIONARY);


	//if not instream 
	//new character set will be called on
	//using the Insert function
	while (!instream.eof())
	{
		char * temp = new char[512];
		instream.getline(temp, 512);
		tree->Insert(temp, taller);
	}
}

//http://math.hws.edu/eck/cs225/s03/binary_trees/
//https://www.youtube.com/watch?v=8nCDvuNOWNU
//https://www.youtube.com/watch?v=3FPjmO3-6IY


//*******GET SPACES
string GetSpaces(int indent)
{
	//goes through the array 
	//using the loop 
	//to create a space after each word
	string charArray = " ";
	for (int i = 0; i <= indent; i++)
	{
		charArray += ' ';
	}
	return charArray;
}



//********PRINT 
void Print(Node * node, int indent)
{
	//if the node has a value
	//print the right side and indent 5 spaces
	//print left side and indent 5 spaces
	//when it prints, it calls on "GetSpaces" which indents 
	//also the node points to data
	if (node != NULL)
	{
		Print(node->right, indent + 5);
		cout << GetSpaces(indent) << node->data << endl;

		Print(node->left, indent + 5);
	}
}



//********MAIN
int main()
{
	//Creating, filling, and printing the tree
	Tree tree;
	FillTreeWithDictionaryWords(&tree);
	Print(tree.GetRoot(), 0); //GetRoot returns ...this->root

	//A temp char array to put lines of the document in
	//fstream: Stream class to both read and write from/to files.
	//calls on document from stored on e drive
	char temp[512];
	std::fstream instream;
	instream.open(DOCUMENT);

	cout << "Misspelled words are:" << endl << endl;

	while (instream >> temp)
	{
		int i = 0;
		char * line = "";

		while (temp[i])
		{
			//if the char is a LETTER, then add it to the 'line' string.
			//we can tell by looking at the AASCII values.
			//lines 97 to 122 are lower case
			//lines 65 to 90 are upper case
			if ((temp[i] < 123 && temp[i] > 96) || (temp[i] < 91 && temp[i] > 64))
			{
				//get the length of the line
				int len = strlen(line);

				//create a new line array thats larger then the line array
				char * newArray = new char[len + 2];

				//copy the line into it
				strcpy(newArray, line);

				//add the new char to the end of the line array
				newArray[len] = temp[i];

				//add the string terminating character 
				newArray[len + 1] = '\0';

				//assign the line array the new line array
				line = newArray;
			}
			i++;
		}

		//check that the string is longer then 0 before checking
		//if the tree contains it.
		//if it does not contain it, then print it
		if (strlen(line) > 0 && !tree.Contains(line))
		{
			std::cout << line << std::endl;
		}
	}

	int i;
	cin >> i;
	return 0;
}