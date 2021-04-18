//--------------------------------------
//---- Programming 622 Assignment 2 ----
//---- BSc I.T. Year 2 Semester 2   ----
//---- Name: Sean van Wyk           ----
//---- Student No. 401912237        ----
//--------------------------------------
#include <iostream>
#include <string>
#include <cstdlib>
#include <istream>

// Here the header file List2.h needed for the linked list.
#include "List2.h"


using namespace std;

//void IdentifyDataType()
//{
//
//	//int a = 5;
//	int controlA;
//
//	double a = 56.23;
//	double controlB;
//
//
//	//char a = 'D';
//	char controlC = 'D';
//
//	//string a = "hey there delilah";
//	string controlE;
//
//
//	//bool a = false;
//	bool controlF;
//
//	if (typeid(a).name() == typeid(controlA).name())
//	{
//		cout << "Printed char:" << endl;
//		cout << typeid(controlA).name() << endl;
//		cout << typeid(a).name() << endl;
//	}
//	if (typeid(a).name() == typeid(controlB).name())
//	{
//		cout << "Printed char:" << endl;
//		cout << typeid(controlB).name() << endl;
//		cout << typeid(a).name() << endl;
//	}
//	if (typeid(a).name() == typeid(controlC).name())
//	{
//		cout << "Printed char:" << endl;
//		cout << typeid(controlC).name() << endl;
//		cout << typeid(a).name() << endl;
//	}
//	if (typeid(a).name() == typeid(controlF).name())
//	{
//		cout << "Printed Bools:" << endl;
//		cout << typeid(controlF).name() << endl;
//		cout << typeid(a).name() << endl;
//	}
//	if (typeid(a).name() == typeid(controlE).name())
//	{
//		cout << "Printed Strings:" << endl;
//		cout << typeid(controlE).name() << endl;
//		cout << typeid(a).name() << endl;
//	}
//}


int main()
{
	bool exit = false;
	MyLinkedList<string> linkedList;
menuselect:
	system("CLS");
	std::cout << "------------- Main Menu -------------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "----| 1. View List             |-----" << std::endl;
	std::cout << "----| 2. Add Member To List    |-----" << std::endl;
	std::cout << "----| 3. Remove Member To List |-----" << std::endl;
	std::cout << "----| 4. Search For A Member   |-----" << std::endl;
	std::cout << "----| 5. Exit                  |-----" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "----| Select An Option: ";
	string tempInput;
	int controldata = 0;
	//getline(cin, tempInput);
	std::cin >> tempInput;

	while (exit != true)
	{
		if (tempInput != to_string(0))
		{
			if (tempInput == to_string(1))
			{
				linkedList.PrintList();
				goto backmenu;
			}
			else if (tempInput == to_string(2))
			{
			addanothernode:
				system("CLS");
				std::cout << "----| Please enter a value: ";
				//getline(cin, tempInput);
				std::cin >> tempInput;
				linkedList.InsertNode(tempInput);
				std::cout << "----| 1. Add\n";
				std::cout << "----| 2. Go Back\n";
				std::cout << "----| 3. Exit\n";
				//getline(cin, tempInput);
				std::cin >> tempInput;
				if (tempInput == to_string(1))
				{
					goto addanothernode;
				}
				else if (tempInput == to_string(2))
				{
					goto menuselect;
				}
				else if (tempInput == to_string(3))
				{
					exit = true;
				}
				else
				{
					goto menuselect;
				}
			}
			else if (tempInput == to_string(3))
			{
				std::cout << "----| Please enter a value: ";
				//getline(cin, tempInput);
				std::cin >> tempInput;
				linkedList.DeleteNode(tempInput);
				goto backmenu;
			}
			else if (tempInput == to_string(4))
			{
				std::cout << "----| Please enter a value: ";
				//getline(cin, tempInput);
				std::cin >> tempInput;
				linkedList.SearchNode(tempInput);
				goto backmenu;
			}
			else if (tempInput == to_string(5))
			{
				exit = true;
			}
			else {

				goto menuselect;
			}


		backmenu:
			std::cout << "----| 1. Go Back\n";
			std::cout << "----| 2. Exit\n";
			//getline(cin, tempInput);
			std::cin >> tempInput;
			if (tempInput == to_string(1))
			{
				goto menuselect;
			}
			else if (tempInput == to_string(2))
			{
				exit = true;
			}
			else
			{
				goto menuselect;
			}
		}
		else
		{
			std::cin.clear(); //clear bad inputValues flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard inputValues
			std::cout << "Invalid input; please re-enter.\n";

		}
	}

	return 0;
}
