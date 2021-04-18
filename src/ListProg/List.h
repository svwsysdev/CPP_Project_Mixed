#pragma once

class List {

private:
	typedef struct Node
	{
		int data;
		Node* next;
	}*nodePtr;

	nodePtr head;
	nodePtr currNode;
	nodePtr tempNode;

public:
	List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void PrintList();
};



