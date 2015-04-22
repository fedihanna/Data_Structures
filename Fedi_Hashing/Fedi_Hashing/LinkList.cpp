#include <iostream>
#include <string.h>
using namespace std;

//******CODE TAKEN FROM LINK LIST ASSIGNMNET 

//********CONSTRUCTING A NODE
//nodes have 2 parts
//one part holds a data
//the other holds data
struct node
{
	char * data;
	node *next; //pointer to the next node
};

class LinkList
{
private:
	node *head = NULL;
	node *last = NULL;


public:
	//******INSERT
	//used as internal to the linkList class
	//must be able to see first and last node plus the data assigned to it
	void Insert(char * data)
	{
		//checking to see if the list is empty
		if (head == NULL)
		{
			node *temp = new node;
			temp->data = data;
			temp->next = NULL;
			head = temp;
			last = temp;
		}
		else
		{
			//if the list is not empty
			//insert a new node
			//have the pointer assign a data to it
			//the next node will be null
			//set previous node to the last value
			//which makes the last node a temporary node
			node *temp = new node;
			temp->data = data;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
	}

	//Method to advance through the list,
	//checking if data provided equals the data
	//at any given node.
	bool Contians(char * data)
	{
		node *temp = new node;
		temp = head;

		while (temp != NULL)
		{
			if (strcmp(temp->data, data) == 0)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

//****PRINTLIST
	void PrintList()
	{
		node *temp = new node;
		temp = head;

		while (temp != NULL)
		{
			//printing every node in the link list 
			//seperating them with 5 spaces
			std::cout << temp->data << "     ";

			temp = temp->next;
		}

		std::cout << std::endl;
	}
};