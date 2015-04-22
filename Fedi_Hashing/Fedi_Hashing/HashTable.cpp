#include "LinkList.cpp";
#define PRIME_NUM 31

//https://computinglife.wordpress.com/2008/11/20/why-do-hash-functions-use-prime-numbers/
// primes are un-divisible by any other numbers, this includes 2


//Hash table class to hash strings and store them
//in an array of Link Lists
class HashTable
{

private:
	//Pointer to an array of Link List
	LinkList * hashTable;

	//Function to return a strings hashed value.
	int Hash(char * data)
	{
		int sum = 0;

		for (int i = 0; i < strlen(data); i++)
		{
			sum += data[i];
		}
		//prime number used is 31
		//returning a remainder of it
		return sum % PRIME_NUM;
	}


	//http://www.algolist.net/Data_structures/Hash_table/Chaining
public:
//***HASH TABLE
	//making a new array of LinkLists for the hashTable to use with 31 elememnts
	HashTable()
	{
		hashTable = new LinkList[PRIME_NUM];
	}

//***INSERT
	void Insert(char * data)
	{
		//declare index to hold a hashed strings value
		//inserting the data in the array of link lists 
		//at the index of the hashed strings value, which is an integer
		int index = Hash(data);
		hashTable[index].Insert(data);
	}


//***BOOL CONTAINS
	//search function baby!!
	bool Contains(char * data)
	{
		//declare index to return hash string value
		//using Contains function to go through hashTable array
		int index = Hash(data);
		return hashTable[index].Contians(data);
	}

//****PRINT
	void PrintTable(){

		//prints every link list in hashtable
		for (int i = 0; i < PRIME_NUM; i++){
		std:cout << i << ": ";
			hashTable[i].PrintList();
		}
	}
};