#include <cstring>
#include <cctype>
#define  NULL 0
using namespace std;



//http://www.stoimen.com/blog/2012/07/03/computer-algorithms-balancing-a-binary-search-tree/
//http://math.hws.edu/eck/cs225/s03/binary_trees/
//http://codereview.stackexchange.com/questions/61671/binary-search-tree-c-implementation
//https://www.youtube.com/watch?v=FNeL18KsWPc .....this is a good one

//This is a simple node class.
class Node
{
public:
	char * data;
	Node * left;
	Node * right;
	short balance;

	//a node which calls on a char pointing the data
	//it is also implemted by a left, right, and balance(which is a value of 0)
	Node(char * data) : data(data), left(NULL), right(NULL), balance(0) {}
};

//******TREE
//This tree is comprised of nodes.
class Tree
{
private:
	Node * root;

public:
	//Tree implements root
	//root is always NULL at begining 
	Tree() : root(NULL) {}

	Node * GetRoot()
	{
		//returns root being used for this instance
		return this->root;
	}

//******INSERT FUNCTION
	//for calling from the class
	//calls on a char pointing to data and a boolean newnode
	void Insert(char * data, bool &newnode)
	{
		//calls on Static void Insert
		//calls on root node
		//calls on ToLower Function (changes data to lower case letters)
		Insert(root, ToLower(data), newnode);
	}


//*******STATIC INSERT
	//calling recursively..this is why we hand it a newnode
	//This Insert method gets called according to a lexicographical comparison.
	//So, 'a' would be greater than 'z' ..etc
	//When called recursively, we hand this either the right or the left node of the current node.
	static void Insert(Node *&node, char * data, bool &newnode)
	{

		try
		{
			//NULL when the very first node is inserted
			//Also NULL when called when using recursion and enough times to have reached a new branch
			if (node == NULL)
			{
				node = new Node(data);
				newnode = true;
			}
			//If the data being inserted equals the nodes data
			//then it is duplicate
			//false so it doesnt display it twice
			else if (data == node->data)
			{
				newnode = false;
			}
			//this determines wether we navigate to left or right side to current node...gets process going 
			//if b is geater than a ...this will run
			else if (strcmp(data, node->data) > 0)
			{
				//Call the "Static Insert method" again and still able to link to the left node
				Insert(node->left, data, newnode);

				//If this method is successfully inserted, we check the balance variable
				//of this node and balance it accordingly.
				if (newnode)
				{
					//checking balance of the node and balancing it 
					switch (node->balance)
					{
						//has left node (no right node)
					case -1:
						//calling on balanceLeftSide function
						balanceLeftSide(node);
						newnode = false;
						break;

						//Balanced
					case 0:
						node->balance = -1;
						break;

						//has right node (no left node)
					case 1 :
						node->balance = 0;
						newnode = false;
						break;
					}
				}
			}
			//if data is less than "node->data' then this block will run
			else
			{
				//Call the "Static Insert method" again using the right node
				Insert(node->right, data, newnode);
				
				//if a newnode
				//newnode must be balanced
				//so it repeats process..case-1, 0, 1
				if (newnode)
				{
					switch (node->balance)
					{
					case -1:
						node->balance = 0;
						newnode = false;
						break;

					case 0:
						node->balance = 1;
						break;

					case 1:
						//calling on balanceRightSide function
						balanceRightSide(node);
						newnode = false;
						break;
					}
				}
			}
		}
		catch (...)
		{
		}	
	}


//*******BALANCE RIGHT SIDE
	static void balanceRightSide(Node *&node)
	{
		try
		{
			//node pointing to address of right 
			//node is now at right
			Node *&right = node->right;

			//must balance the right side
			switch (right->balance)
			{
			case 1:
				//node is balanced
				//have the right see the balance node
				//calls on the SwapRight function 
				node->balance = 0;
				right->balance = 0;
				SwapRight(node);
				break;

			case -1:
				//pointer subleft is seeing the right node ...which also sees the left
				Node *subleft = right->left;

				//when the subleft is balanced
				switch (subleft->balance)
				{
					//right node is now in the root node position 
				case 0:
					node->balance = 0;
					right->balance = 0;
					break;

					//the left node is now in right side 
				case -1:
					node->balance = 0;
					right->balance = 1;
					break;

					//the right node is now in left side 
				case 1:
					node->balance = -1;
					right->balance = 0;
					break;
				}
				//subleft is now balanced and it is root node
				//this is why its value is 0
				subleft->balance = 0;

				//calling on SwapLeft Function
				SwapLeft(right);

				//calling on SwapRight Function
				SwapRight(node);
				break;
			}
		}
		catch (...)
		{
		}
	}


//*****BALANCE LEFT SIDE
	static void balanceLeftSide(Node *&node)
	{
		try
		{
			//first thing it does is get the left node
			Node *&left = node->left;

		
			switch (left->balance)
			{
				//this is confirming the tree is a straight line and needs balancing
			case -1:
				//node is balanced
				//have the left see the balance node
				//calls on the SwapLeft function 
				node->balance = 0;
				left->balance = 0;
				SwapLeft(node);
				break;

			case 1:
				//pointer subleft is seeing the left node ...which also sees the right
				Node *subright = left->right;

				//when the subright is balanced
				switch (subright->balance)
				{
				case 0:
					//left node is now in the root node position 
					node->balance = 0;
					left->balance = 0;
					break;

					//the left node is now in right side 
				case -1:				
					node->balance = 0;
					left->balance = 1;
					break;

					//the right node is now in left side
				case 1:
					node->balance = -1;
					left->balance = 0;
					break;
				}
			
				subright->balance = 0;

				//calling on SwapRight Function
				SwapRight(left);

				//calling on SwapLeft Function
				SwapLeft(node);
				break;
			}
		}
		catch (...)
		{
		}
	}


//*******SWAP LEFT
	static void SwapLeft(Node *&node)
	{
		try
		{
			//make a pointer to the original left
			//new left is now pointing to the original right node
			//the left nodes right node is now pointing to the new node
			//assign the node left to hold on to the connection 
			Node *left = node->left;
			node->left = left->right;
			left->right = node;
			node = left;
		}
		catch (...)
		{
		}
	}

	//*******SWAP RIGHT
	static void SwapRight(Node *&node)
	{
		try
		{
			//make a pointer to the original right
			//new right is now pointing to the original left node
			//the right nodes left node is now pointing to the new node
			//assign the node right to hold on to the connection 
			Node *right = node->right;
			node->right = right->left;
			right->left = node;
			node = right;
		}
		catch (...)
		{
		}
	}


//******BOOL CONTAINS
	bool Contains(char * data)
	{
		bool found = false;
		return Contains(root, ToLower(data), found);
	}


//******STATIC BOOL CONTAINS
	//using recursion to look for a string
	static bool Contains(Node *&node, char * data, bool &found)
	{
		try
		{
			if (found) //if found return true with recursion
			{
				return found;
			}
			else if (node == NULL)
			{
				return false;
			}
			else if (strcmp(data, node->data) == 0) //we found the record
			{
				found = true;
				return found;
			}

			//if the lexicographical comparison is less then the data that is already the current node
			//...go left
			else if (strcmp(data, node->data) > 0)
			{
				return Contains(node->left, data, found);
			}

			else //else go right
			{
				return Contains(node->right, data, found);
			}
		}
		catch (...)
		{

		}
	}


	//making all characters lowercase 
	//because capital letters have a greater ASCII value
	char * ToLower(char * data)
	{
		int i = 0;

		//pointer to c, which will be converted to lowercase
		char * c = new char[512];

		//pointer to the data 
		//when data does not equal to 0
		while (*(data + i) != 0)
		{
			//"toupper" doing the conversion
			c[i] = toupper(data[i]);
			i++;
		}

		//'\0' is the null termination character. It marks the end of the string. 
		//Without it, the computer has no way to know how long that group of characters goes.
		//finally return the value of "c"
		c[i] = '\0';
		return c;
	}
};

















