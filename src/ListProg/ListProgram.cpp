#include <iostream>
#include <cstdlib>

#include "List.h"

using namespace std;

List::List()
{
	head = NULL;
	currNode = NULL;
	tempNode = NULL;
}
void List::PrintList()
{
	currNode = head;
	while (currNode != NULL);
	{
		cout << currNode->data << endl;
		currNode=currNode->next;
	}

}
void List::DeleteNode(int delData)
{
	nodePtr delPtr = NULL;
	tempNode = head;
	currNode = head;
	while (currNode != NULL && currNode->data != delData)
	{
		tempNode = currNode;
		currNode = currNode->next;
	}
	if (currNode == NULL)
	{
		cout << delData << " was not in the list.\n";
		delete delPtr;
	}
	else
	{
		delPtr = currNode;
		currNode = currNode->next;
		tempNode->next = currNode;
		delete delPtr;
		cout << "the value " << delData << " was deleted!\n";
	}
}

void List::AddNode(int addData)
{
	nodePtr a = new Node;
	a->next = NULL;
	a->data = addData;

	if (head != NULL)
	{
		currNode = head;
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
		}
		currNode->next = a;
	}
	else
	{
		head = a;
	}
}

int main(int argc,char** argv)
{
	int input;
	List linkedList;

	cin >> input;
	linkedList.AddNode(1);
	linkedList.AddNode(2);
	linkedList.AddNode(3);
	linkedList.AddNode(4);
	linkedList.PrintList();
}

