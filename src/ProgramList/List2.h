//--------------------------------------
//---- Programming 622 Assignment 2 ----
//---- BSc I.T. Year 2 Semester 2   ----
//---- Name: Sean van Wyk           ----
//---- Student No. 401912237        ----
//--------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <istream>

/// <summary>
/// Class template InputData declared as new data type.
/// </summary>
/// <typeparam name="InputData"></typeparam>
template<class InputData>

/// <summary>
/// Node structure declared, these are elements of the linked list.
/// </summary>
/// <typeparam name="InputData"></typeparam>
struct Node
{
	// Members declared for each node.
	// Member data declared as InputData Type.
	// Node* is declared as a pointer.
	InputData data;
	Node* next;
};

/// <summary>
/// Class template InputData declared as new data type.
/// </summary>
/// <typeparam name="InputData"></typeparam>
template<class InputData>

/// <summary>
/// MyLinkedList class is declared and defined.
/// Private members are declared with all the pointers required.
/// Public members are declared with the functions to carry out the tasks.
/// </summary>
/// <typeparam name="InputData"></typeparam>
class MyLinkedList {

	// Pointers declared as private.
private:
	Node<InputData>* head;
	Node<InputData>* currNode;
	Node<InputData>* TrailingNode;

	// Functions declared as public.
public:
	MyLinkedList();
	void DeleteNode(InputData delData);
	void SearchNode(InputData searchData);
	void InsertNode(InputData insertData);
	void PrintList();
};

/// <summary>
/// Class template InputData declared as new data type.
/// </summary>
/// <typeparam name="InputData"></typeparam>
template <class InputData>

/// <summary>
/// MyLinkedList instantiates the list initially will null values.
/// </summary>
/// <typeparam name="InputData"></typeparam>
MyLinkedList<InputData>::MyLinkedList()
{
	// Nodes created with null values initially.
	head = NULL;
	currNode = NULL;
	TrailingNode = NULL;
}

template <class InputData>

/// <summary>
/// SearchNode is to traverse the linked list and see if the inputValues exists in the linked list.
/// </summary>
/// <typeparam name="InputData"></typeparam>
/// <param name="searchData"></param>
void MyLinkedList<InputData>::SearchNode(InputData searchData)
{


	// Declaring a new pointer to use as our search pointer.
	Node<InputData>* searchPtr = NULL;

	// Pre-define where we want to start in the list. 
	// Here I set it to the start of the list.
	TrailingNode = head;
	currNode = head;

	// Declare string for output message.
	std::string outputmessage = " ";

	// Create loop with condition to continue to loop until we find the value.
	// Or until we reach the end of the linked list with no result.
	while (currNode != NULL && currNode->data != searchData)
	{
		// Traversal of the linked list is done, to search for the node data inputValues.
		TrailingNode = currNode;
		currNode = currNode->next;
	}
	// Condition of current node checked to determine the output.
	if (currNode == NULL)
	{
		// Output if value is not found in the linked list.
		outputmessage = "----| Data Couldn't Be Found!\n----| Where Data Input Is:: " + searchData;
	}
	else
	{
		// Output if value is found in the linked list.
		outputmessage = "----| Data Exists!\n----| Where Data Input Is: " + searchData;
	}
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << outputmessage << std::endl;
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	// Remove the search pointer from memory allocation, for cleanup purposes.
	delete searchPtr;
}

template <class InputData>

/// <summary>
/// DeleteNode is to traverse the linked list and remove an item specified.
/// </summary>
/// <typeparam name="InputData"></typeparam>
/// <param name="removeData">is inputValues data to delete from linked list.</param>
void MyLinkedList<InputData>::DeleteNode(InputData removeData)
{


	// Declare a new delete pointer. 
	Node<InputData>* delPtr = NULL;

	// Pre-define where we want to start in the list. 
	// Here I set it to the start of the list.
	TrailingNode = head;
	currNode = head;

	// Declare string for output message.
	std::string outputmessage = " ";

	// Create loop with condition to continue to loop until we find the value.
	// Or until we reach the end of the linked list with no result.
	while (currNode != NULL && currNode->data != removeData)
	{
		TrailingNode = currNode;
		currNode = currNode->next;
	}
	// Condition of current node checked to determine the output.
	if (currNode == NULL)
	{
		// Output if value is not found in the linked list.
		outputmessage = "----| Data Not Deleted! Does Not Exist!\n----| Where Data Input Is: " + removeData;
	}
	else
	{
		// Output if value is found in the linked list.
		// I set the delete pointer to current node where result was found.
		delPtr = currNode;

		// I then move the current pointer to next.
		currNode = currNode->next;

		// I move the trailing pointer to the current node.
		TrailingNode->next = currNode;

		// Condition created if the delPtr is on the head node.
		if (delPtr == head)
		{
			// Here I set the new head node as the next node in the list.
			head = head->next;

			// Set the trailing node to null
			TrailingNode = NULL;
		}
		outputmessage = "----| The Data Was Successfully Deleted!\n----| Where Data Input Is: " + removeData;
	}
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << outputmessage << std::endl;
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	// Remove the delete pointer from memory allocation, for cleanup purposes.
	delete delPtr;
}

template <class InputData>

/// <summary>
/// PrintList is used to display all the linked list elements or members.
/// </summary>
/// <typeparam name="InputData"></typeparam>
void MyLinkedList<InputData>::PrintList()
{


	// Set the start point from where we want to print the list.
	currNode = head;

	// Print the list to cout. To view.
	std::cout << std::endl;
	std::cout << "----| Linked List |------------------" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	// Create loop to traverse the list and get each data member to display.
	if (currNode != NULL) {
		do
		{
			std::cout << "----| " << currNode->data << std::endl;
			currNode = currNode->next;
		} while (currNode != NULL);
	}
	else
	{
		std::cout << "----| List Is Empty!!!" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
}

template <class InputData>

/// <summary>
/// InsertNode is used to add members in order to the linked list.
/// </summary>
/// <typeparam name="InputData"></typeparam>
/// <param name="insertData"></param>
void MyLinkedList<InputData>::InsertNode(InputData insertData)
{


	// Declare newNode which we will use to insert it at a specific point in order.
	// I specified the data as the inputValues data from the user, and next as null initially.
	Node<InputData>* newNode = new Node<InputData>;
	newNode->next = NULL;
	newNode->data = insertData;

	// Set start position.
	currNode = head;

	// Conditional sattement to check if the list is empty.
	if (head == NULL)
	{
		// If List is empty the newnode will become the new head node.
		head = newNode;

		// Output message of success if a new list has been created.
		std::cout << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << std::endl;
		std::cout << "----| New List Created With Data Input!" << std::endl;
		std::cout << "----| Where Data Input Is: " << insertData << std::endl;
		std::cout << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		// If the list is not empty we search for the its location first.
		// Here I set the start point.
		currNode = head;

		// Trailing node set to Null for now.
		TrailingNode = NULL;

		// Here I traverse the linked list.
		while (currNode != NULL)
		{
			// Condition checks the current node and comapres it to the new node.
			if (currNode->data >= newNode->data)
			{
				// If the current node is equal or greater it will exit the loop.
				break;
			}
			else
			{
				// If the condition is not yet met it will continue to traverse the linked list.
				TrailingNode = currNode;
				currNode = currNode->next;
			}
		}
		// Conditional statment if the current node is the head node and insert must be done.
		if (currNode == head)
		{
			// Here I insert the newnode as the head node.
			newNode->next = head;
			head = newNode;
		}
		else
		{
			// If the new node must be inserted in between two nodes we set the new node to current.
			newNode->next = currNode;

			// After the new node is now set as current node i patch the linked list abck together,
			// With the trailing node to now point at the new node inserted.
			TrailingNode->next = newNode;
		}
		// Output message of succesful insertion into an existing list.
		std::cout << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << std::endl;
		std::cout << "----| Data Successfully Inserted!" << std::endl;
		std::cout << "----| Where Data Input Is: " << insertData << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << std::endl;
	}
}