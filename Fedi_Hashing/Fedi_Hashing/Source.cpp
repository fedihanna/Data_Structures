#include <iostream>
#include <string>
#include "HashTable.cpp"
#include <fstream>


//the text files from Hal S Drive
//put into my H Drive
#define DICTIONARY "E:\\IT COURSE 2015-16 (PART 4)\\PROG 2400 Hal O'Connell\\Assign_4b_Trees\\dictionary.txt"
#define DOCUMENT "E:\\IT COURSE 2015-16 (PART 4)\\PROG 2400 Hal O'Connell\\Assign_4b_Trees\\mispelled.txt"

using namespace std;

//********FILL TREE WITH DICIONARY WORDS
//this fills the binary tree with words in the dictionary.txt text file
void FillTableWithDictionaryWords(HashTable * hashTable)
{
	
	//char is 8 bit character set that holds 512 values
	//fstream: Stream class to both read and write from/to files.
	//calls on dictionary from stored on e drive
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
		hashTable->Insert(temp);
	}
}

//********MAIN
int main()
{
	//calling on HashTable class
	HashTable hashTable;
	FillTableWithDictionaryWords(&hashTable);
	

	//A temp char array to put lines of the document in
	//fstream: Stream class to both read and write from/to files.
	//calls on document from stored on e drive
	char temp[512];
	std::fstream instream;
	instream.open(DOCUMENT);

	cout << "Misspelled words are:" << endl << endl;

	//THIS IS FOR EACH IN THE MIS-SPELLED DOCUMENT
	while (instream >> temp)
	{
		int i = 0;
		char * line = "";

		while (temp[i])
		{
			//THIS ROUTINE STRIPS PUNCATION
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

		//AFTER PRINTING MIS-SPELLED WORD
		//check that the string is longer then 0 before checking
		//if the tree contains it.
		//if it does not contain it, then print it
		if (strlen(line) > 0 && !hashTable.Contains(line))
		{
			std::cout << line << std::endl;
		}
	}
	
	//callingh the Printable function
	std::cout << std::endl << "Hastable:" << std::endl;

	hashTable.PrintTable();


	int i;
	cin >> i;
	return 0;
}