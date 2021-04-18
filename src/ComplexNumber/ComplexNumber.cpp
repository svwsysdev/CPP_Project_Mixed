
#include <iostream>

#include "Complex.h"

using namespace std;

int main() {
	// A input variable declared.
	string input;
	// Instantiating the Complex class.
	Complex complexOrderPairFirst, complexOrderedPairSecond, result;
menuselect:
	system("CLS");
	std::cout << "---------------- Main Menu -----------------" << std::endl;
	std::cout << "----| To Calculate The Complex No.    |-----" << std::endl;
	std::cout << "----| Please Select an Operator       |-----" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "----| 1. Addition (+)                 |-----" << std::endl;
	std::cout << "----| 2. Multiplication (*)           |-----" << std::endl;
	std::cout << "----| 3. Show Examples                |-----" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "----| 4. Exit                         |-----" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "----| Select An Option: ";
	bool exitval = false;
	cin >> input;
	while (exitval != true)
	{
		if (input == "1")
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| First complex number. " << endl;
			std::cout << "--------------------------------------------" << std::endl;
			cin >> complexOrderPairFirst;
			std::cout << endl;
			std::cout << "----| Second complex number. " << endl;
			std::cout << "--------------------------------------------" << std::endl;
			std::cin >> complexOrderedPairSecond;
			result = complexOrderPairFirst + complexOrderedPairSecond;
			std::cout << result;
		}
		else if (input == "2")
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| First complex number. " << endl;
			std::cout << "--------------------------------------------" << std::endl;
			cin >> complexOrderPairFirst;
			std::cout << endl;
			std::cout << "----| Second complex number. " << endl;
			std::cout << "--------------------------------------------" << std::endl;

			std::cin >> complexOrderedPairSecond;
			result = complexOrderPairFirst * complexOrderedPairSecond;
			std::cout << result;
		}
		else if (input == "3")
		{
			std::cout << endl;
			std::cout << "-------------------- Examples --------------------" << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << "----| Addition: (a+bi)+(c+di)               |-----" << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << "----| Multiply: (a+bi)*(c+di)               |-----" << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << "----| Selecting an operator will change the |-----" << std::endl;
			std::cout << "----| operator between each ordered pair.   |-----" << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
		}
		else if (input == "4")
		{
			exitval = true;
		}
		else
		{
			goto menuselect;
		}
	backmenu:
		std::cout << endl;
		std::cout << "----| 1. Go Back\n";
		std::cout << "----| 2. Exit\n";
		std::cout << endl;
		std::cout << "----| Please enter a value: ";
		std::cin >> input;
		if (input == "1")
		{
			goto menuselect;
		}
		else if (input == "2")
		{
			exitval = true;
		}
		else {
			goto menuselect;
		}
	}
	return 0;
}