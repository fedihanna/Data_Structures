#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;


//********CONSTRUCTING A NODE
//nodes have 2 parts
//one part holds a number
//the other holds data
struct node
{
int data;
node *next; //pointer to the next node
};

//********LIST OF FUNCTIONS
bool isEmpty(node *head);
char menu();
void insertAsFirstLetter(node *head, node *tail, int data);
void insert(node *head, node *tail, int data);
void removeLetter(node *head, node *tail, int data);
void displaySet(node *current);
void exitAndSave();
void exitWithoutSaving();


//*****IS EMPTY
bool isEmpty(node *head)
{

}


//*******MENU
char menu()
{
	char choice;

	cout << "EDIT \n";
	cout << "Please enter one of the following letters then press ENTER: \n";
	cout << "I \n";
	cout << "D \n";
	cout << "V \n";
	cout << "G \n";
	cout << "L \n";
	cout << "S \n";
	cout << "E \n";
	cout << "Q \n";

	cin >> choice;
	return choice;
}


//****INSERT AS FIRST LETTER
void insertAsFirstLetter(node *head, node *tail, int data)
{

}


//******INSERT
void insert(node *head, node *tail, int data)
{

}


//*****REMOVE LETTER
void removeLetter(node *head, node *tail, int data)
{

}


//*****DISPLAY SET
void displaySet(node *current)
{

}


//******EXIT AND SSAVE
void exitAndSave()
{

}


//*********EXIT WITHOUT SAVING
void exitWithoutSaving()
{

}


//****MAIN
int main(int argc, char** argv)
{
	vector<string> text;
	string input, output;
	int n;
	int m;






	return 0;
}