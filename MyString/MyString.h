#pragma once

#include <cstring>
#include <iostream>
using namespace std;

// MyString class declaration goes here

class MyString;											//declaration for the class
ostream & operator << (ostream& ptr, const MyString&);	//overloaded output operator

class MyString
{
private:
	char * string;							//ptr to a char for each class


public:
	MyString();								//default constructor (set string = null ptr)
	MyString(const char*);					//c-string constructor
	MyString(const MyString&);				//copy constroctor
	
	~MyString();							//destructor
	MyString operator = (const MyString&);	//overloaded = (assignment operator)
	MyString operator + (const MyString&);	//overloaded +
	bool operator == (const MyString&);		//overloaded ==
	const char* c_str() const;				//return's the internal c-string ptr of the class as a const pointer (only for over loaded output operator so it doesn't have to be a friend)
};