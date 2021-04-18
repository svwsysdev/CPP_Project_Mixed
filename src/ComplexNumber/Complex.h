#pragma once
#include <iostream>

using namespace std;

class Complex
{
private:
	// Declaring the public variables we require.
	// We use them in the Complex operators to calculate complex numebrs.
	float realNumber;
	float imaginaryNumber;
	float realNumTemp;
	float imaginaryNumTemp;
public:
	// Here the complex function is instantiated and variables are initialized.
	Complex() : realNumber(0), imaginaryNumber(0), realNumTemp(0), imaginaryNumTemp(0) { }

	friend istream& operator >> (istream& in, Complex& complexInput);
	friend ostream& operator << (ostream& out, const Complex& complexOutput);

	friend ostream& operator << (ostream& out, const Complex& complexOutput)
	{
		out << "--------------------------------------------" << endl;
		out << "----| Final Answer: " << complexOutput.realNumber << "+" << complexOutput.imaginaryNumber << "i" << endl;
		out << "--------------------------------------------" << endl;
		out << endl;
		return out;
	}
	friend istream& operator >> (istream& in, Complex& complexInput)
	{
		std::cout << "----| Please enter a real number: ";
		in >> complexInput.realNumber;
		std::cout << "----| Please enter an imaginary number: ";
		in >> complexInput.imaginaryNumber;
		return in;
	}

	// Here I overload the operator with complexNumInput. 
	// This is to do the caluclation for addition of complex numbers.
	Complex operator + (Complex complexNumInput)
	{
		Complex temp;
		temp.realNumber = realNumber + complexNumInput.realNumber;
		temp.imaginaryNumber = imaginaryNumber + complexNumInput.imaginaryNumber;
		system("CLS");
		cout << "--------------------------------------------" << endl;
		cout << endl;
		cout << "----| Complex Number Expression Entered:" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "----| (" << realNumber << " + " << imaginaryNumber << "i) + (" << complexNumInput.realNumber << " + " << complexNumInput.imaginaryNumber << "i)" << endl;
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "----| Calculation:" << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;
		cout << "----| Step 1: (" << realNumber << " + " << complexNumInput.realNumber << ") + (" << imaginaryNumber << "i + " << complexNumInput.imaginaryNumber << "i)" << endl;
		cout << endl;
		cout << "----| Step 2: (" << temp.realNumber << ") + (" << temp.imaginaryNumber << "i)" << endl;
		cout << endl;
		return temp;
	}

	// Here I overload the operator with complexNumInput.
	// This is to do the caluclation for multiplication of complex numbers.
	Complex operator * (Complex complexNumInput)
	{
		Complex temp;
		system("CLS");
		cout << "--------------------------------------------" << endl;
		cout << endl;
		cout << "----| Complex Number Expression Entered:" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "----| (" << realNumber << " + " << imaginaryNumber << "i) * (" << complexNumInput.realNumber << " + " << complexNumInput.imaginaryNumber << "i)" << endl;
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "----| Calculation:" << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;
		temp.realNumTemp = realNumber * complexNumInput.imaginaryNumber;
		temp.imaginaryNumTemp = imaginaryNumber * complexNumInput.realNumber;
		cout
			<< "----| Step 1: (" << realNumber
			<< " * " << complexNumInput.realNumber
			<< " - " << imaginaryNumber
			<< " * " << complexNumInput.imaginaryNumber
			<< ") + (" << realNumber
			<< " * " << complexNumInput.imaginaryNumber
			<< " + " << imaginaryNumber
			<< " * " << complexNumInput.realNumber
			<< ")i"
			<< endl;
		temp.realNumber = realNumber * complexNumInput.realNumber;
		temp.imaginaryNumber = imaginaryNumber * complexNumInput.imaginaryNumber;
		cout
			<< "----| Step 2: (" << temp.realNumber
			<< " - " << temp.imaginaryNumber
			<< ") + (" << temp.realNumTemp
			<< " + " << temp.imaginaryNumTemp << ")i"
			<< endl;
		temp.realNumber = temp.realNumber - temp.imaginaryNumber;
		temp.imaginaryNumber = temp.realNumTemp + temp.imaginaryNumTemp;
		cout
			<< "----| Step 3: (" << temp.realNumber
			<< ") + (" << temp.imaginaryNumber << ")i"
			<< endl;
		cout << endl;
		return temp;
	}
};