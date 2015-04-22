#include <iostream>
#include "stdafx.h"
using namespace std;

//********CONSTRUCTING A NODE
//nodes have 2 parts
//one part holds a number
//the other holds data
struct node
{
	int number;
	node *next; //pointer to the next node
};

//******LIST OF FUNCTIONS WE ARE USING
bool isEmpty(node *head); //checking to see if the node is empty
char menu(); //what buttons we will press
void insertAsFirstElement(node *&head, node *&last, int number); //when we insert, we point to the first, last and number assigned 
void insert(node *&head, node *&last, int number); //same as above...first, last and number
void remove(node *&head, node *&last, int number); // " " " "
void showList(node *current); //we want to show the current list


//*****BOOL isEmpty
bool isEmpty(node *head)
{
	//want to see if the list is empty when we start off
	//if its empty return true
	//if it has values in it, return false
	if (head == NULL)
		return true;
	else
		return false;
}

//******CHAR MENU
char menu()
{
	//controls for user to add, remove, show list and Exit
	char choice;

	cout << "Menu \n";
	cout << "1. Add Item.\n";
	cout << "2. Remove an item. \n";
	cout << "3. Show the list.\n";
	cout << "4. Exit\n";

	cin >> choice; //register the choices
	return choice; //return what the user presses
}

//******INSERT AS FIRST ELEMENT
//must be able to see first and last node plus the number assigned to it
void insertAsFirstElement(node *&head, node *&last, int number)
{
	//creating a temporary node
	//pointing to a new number
	//the temp pointer is referencing a number which is assigned by "int number"
	//the next node will be NULL 
	//after everything is inserted, the head is set to temp and the last is set to temp
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;
}

//******INSERT
//must be able to see first and last node plus the number assigned to it
void insert(node *&head, node *&last, int number)
{
	//checking to see if the list is empty
	if (isEmpty(head))
		insertAsFirstElement(head, last, number);
	else
	{
		//if the list is not empty
		//insert a new node
		//have the pointer assign a number to it
		//the next node will be null
		//set previous node to the last value
		//which makes the last node a temporary node
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

//*****REMOVE
//removing head node, last node and number assigned to node
void remove(node *&head, node *&last, int number)
{
	//if the list is empty
	//display "The list is already empty"
	if(isEmpty(head))
		cout << "the list is already empty.\n";

	//if there is an item in the list
	//make the head equal the last
	//delete the head 
	//making the head and last NUll
	else if (head == last)
	{
		delete head;
		head == NULL;
		last == NULL;
	}

	//if there is more than one item in the list
	//you create a temp node....which equals head
	//the head will be the next node
	//then you delete the temp head
	else
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
	
}

//******SHOW LIST
//showing the list after something is inserted or removed
void showList(node *current)
{
	if (isEmpty(current))
		cout << "The list is empty\n";

	//if it has values it will display "the list contains ...."
	//then we loop through ...
	//while the list is showing a value
	//display the current list 
	//current node will be the value of the next.
	else
	{
		cout << "the list contains: \n";

		while (current != NULL)
		{
			cout << current->number << endl;
			current = current->next;
		}
	}

}




//********MAIN
//starts off as NULL because there is nothing in the list
int main()
{

	node *head = NULL;
	node *last = NULL;
	char choice;
	int number;


	do{

		choice = menu();

		switch (choice)
		{
			//when you press "1"
		case '1': cout << "please enter a number:";
			cin >> number;
			insert(head, last, number);
			break;

			//when you press "2"
		case '2': remove(head, last, number);
			break;

			//when you press "3"
		case '3': showList(head);
			break;
		default: cout << "System exit \n";
		}

		//goes to default....telling you to press "4"
	} while (choice != '4');

	return 0;
}