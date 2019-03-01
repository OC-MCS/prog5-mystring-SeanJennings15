// MyString implementation file
#include <iostream>
#include <cstring>
#include <cctype>
#include "MyString.h"
using namespace std;

//Overloaded Output Constructor

//======================================================
// operator <<: allows for output of MyStrings
// parameters: ostream& ptr, const MyString& other
// return type: returns an ostream for output
//======================================================
ostream& operator << (ostream& ptr, const MyString&other)
{
	if (other.c_str() == nullptr)
		ptr << "";
	else
		ptr << other.c_str();

	return ptr;
}

//Default Constructor

//======================================================
// MyString(): default constructor (sets string to a null ptr)
// parameters: none
// return type: none
//======================================================
MyString::MyString()
{
	cout << "\nUSING DEFAULT CONSTRUCTOR";
	string = nullptr;
}

//C-string Constructor

//======================================================
// MyString(const char* input): c-string constructor
// parameters: const char* input: input string as a constant
// return type: none
//======================================================
MyString::MyString(const char* input)			//const says it wont change the contents of your string/array being passed
{
	cout << "USING C-STRING CONSTRUCTOR\n";
	string = new char[strlen(input) + 1];
	strcpy_s(string, strlen(input) + 1, input);
}

//Copy Constructor

//======================================================
// MyString(): copy constructor
// parameters: const MyString& input
// return type: none
//======================================================
MyString::MyString(const MyString& input)			//const says it wont change the contents of your string/array being passed
{
	cout << "\nUSING COPY CONSTRUCTOR";
	string = new char[strlen(input.string) + 1];
	strcpy_s(string, strlen(input.string) + 1, input.string);
}

//Destructor

//======================================================
// ~MyString(): destructor
// parameters: none
// return type: none
//======================================================
MyString::~MyString()
{
	cout << "\nUSING DESTRUCTOR";
	delete[] string;
}

//Overloaded Assignment Operator

//======================================================
// operator = : allows for assigning MyStrings with the = sign
// parameters: const MyString& other
// return type: MyString
//======================================================
MyString MyString:: operator = (const MyString& other)		
{
	cout << "\nUsing overloaded assignment (=) operator";

	if (this != &other)
	{
		delete[] string;
		string = new char[strlen(other.string) + 1];
		//cout << "Size of other string: " << strlen(other.string) << endl;
		strcpy_s(string, strlen(other.string) + 1, other.string);
	}

	return *this;
}

//Overloaded + Operator

//======================================================
// operator + : allows for adding MyStrings with the + sign
// parameters: const MyString& other
// return type: MyString
//======================================================
MyString MyString:: operator + (const MyString& other)		//Overloaded + operator
{
	cout << "\nUsing overloaded addition (+) operator";
	MyString temp;
	
	if (other.string == nullptr && string == nullptr)
	{
		temp.string = new char[1];
		strcpy_s(temp.string, 1, "\0");
	}
	else if (other.string == nullptr)
	{
		int size = strlen(string) + 1;
		temp.string = new char[size];
		strcpy_s(temp.string, size, string);
		strcat_s(temp.string, size, "\0");
	}
	else if (string == nullptr)
	{
		int size = strlen(other.string) + 1;
		temp.string = new char[size];
		strcpy_s(temp.string, size, other.string);
		strcat_s(temp.string, size, "\0");
	}
	else
	{
		int size = strlen(string) + strlen(other.string) + 1;
		temp.string = new char[size];
		strcpy_s(temp.string, size, string);
		strcat_s(temp.string, size, other.string);
		strcat_s(temp.string, size, "\0");
	}

	return temp;
}

//Overloaded Compare (==) Operator

//======================================================
// operator == : allows for comparing MyStrings and returns a bool for their state
// parameters: const MyString& other
// return type: bool
//======================================================
bool MyString:: operator == (const MyString& other)		//Overloaded == operator
{
	cout << "\nUsing overloaded compare (==) operator";
	bool isEqual;

	if (other.string == nullptr || string == nullptr)
	{
		if (other.string == nullptr && string == nullptr)
			isEqual = true;
		else
			isEqual = false;
	}
	else
	{
		if (!strcmp(string, other.string))
			isEqual = true;
		else
			isEqual = false;
	}

	return isEqual;
}

//Get const pointer of MyString class pointer

//======================================================
// c_str(): grabs the local string ptr of the class and returns it as a const
// parameters: none
// return type: const char*
//======================================================
const char* MyString::c_str() const	//const on the end says it wont change and instance data passed to it
{
	return string;
}