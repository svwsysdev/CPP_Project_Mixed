

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

long final;

int ConvertToDec(vector<int> binaryInput, long total, int power);


int main()
{
menuselect:
	system("CLS");
	std::cout << "------------- Main Menu -------------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "----| 1. Binary To Decimal     |-----" << std::endl;
	std::cout << "----| 2. Exit                  |-----" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "----| Select An Option: ";
	bool exitval = false;
	string input;
	cin >> input;
	while (exitval != true) {
		if (input == "1") {

		addbinary:
			final = 0;
			system("CLS");
			std::cout << endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| Enter A Binary Value: ";
			cin >> input;
			vector<int> binaryInput(input.begin(), input.end());
			int power = binaryInput.size();
			for (int i = 0; i < binaryInput.size(); i++)
			{
				binaryInput[i] = input[i] - '0';
			}
			int counter = binaryInput.size();
			ConvertToDec(binaryInput, 1, counter - 1);
			std::cout << endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| Decimal Output: "<<final<<endl;
			std::cout << endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| 1. Convert Another Value\n";
			std::cout << "----| 2. Go Back\n";
			std::cout << endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << endl;
			std::cout << "----| Select An Option: ";
			std::cin >> input;
			if (input == "1") 
			{
				
				goto addbinary;		
			}
			else 
			{
				
				goto menuselect;
			}
		}
		else if (input == "2") 
		{
			exitval = true;
		}
		else 
		{
			goto menuselect;
		}
	}
}



int ConvertToDec(vector<int> binaryInput, long total, int power)
{
	int base = 2;
	if (power + 1 == binaryInput.size())
	{
		total = 1;
	}
	else
	{
		if (power >= 0)
		{
			total *= base;
		}
	}
	final += total * binaryInput[power];
	if (power == 0) 
	{
		return final;
	}
	power--;
	ConvertToDec(binaryInput, total, power);
}




