// test driver code goes here
#include <iostream>
#include <cstring>
#include "MyString.h"
#include <string>
using namespace std;

//=====================================================
// Sean Jennings
// 3/1/2019
// Programming 2, Assignment #5
// Description: MyString
//=====================================================

MyString testFunc(MyString);

int main()
{
	//showing various methods of initializing MyStrings and outputting each case
	MyString S1;				//uses default constructor
	cout << "\n===Demonstrating outputting a null ptr (S1 = null ptr;)===\n";
	cout << "EXPECTED OUTCOME: the program will not crash\n";
	cout << "OUTPUT: " << S1 << endl;
	cout << "...the program is still running:\n\n";
	
	MyString S2("String 2");	//uses c-string constructor
	cout << "===Demonstrating outputting string initialized using the c-string constructor===\n";
	cout << "OUTCOME: " << S2 << endl << endl;	
	
	MyString S3 = "String 3";	//uses c-string constructor
	cout << "===Demonstrating outputting string using other initialization method for c-string constructor===\n";
	cout << "OUTCOME: " << S3 << endl << endl;

	MyString S4(S2);			//uses copy constructor so now S4 say "String 2"
	cout << "\n===Demonstrating outputting initialization using the copy constructor (S4(S2))===\n";
	cout << "OUTCOME: " << S4 << endl << endl;

	MyString S5;
	S5 = S2 + S3;
	cout << "\n===Demonstrating Addition of Two Strings (S5 = S2 + S3)===\n";
	cout << "OUTPUT: " << S5 << endl;

	S5 = S2 + " " + S3;
	cout << "\n===Now Demonstrating the same addition but with a space between the two strings(S5 = S2 + '' '' + S3)===\n";
	cout << "OUTPUT: " << S5 << endl;
	
	S5 = S2 + S3 + S3;
	cout << "\n===Now Demonstrating the same addition but with 3 strings all together (S5 = S2 + S3 + S3)===\n";
	cout << "OUTPUT: " << S5 << endl << endl;

	cout << "===Demonstrating the compare operator for different strings(S2 == S3)===";
	if (S2 == S3)
		cout << "\nThe strings are equal.\n\n";
	else
		cout << "\nThe strings are not equal.\n\n";

	cout << "===Now demonstrating the compare operator for the same strings (S4 == S2; S4 was previously assigned S2)===";
	if (S4 == S2)
		cout << "\nThe strings are equal.\n\n";
	else
		cout << "\nThe strings are not equal.\n\n";

	MyString S6;
	cout << "\n===Demonstrating the compare operator works for two null ptrs (S1 == S6)===";
	if (S1 == S6)
		cout << "\nThe strings are equal.\n\n";
	else
		cout << "\nThe strings are not equal.\n\n";

	cout << "===Demonstrating the compare operator works for one null ptr and one populated c-string (S1 == S2)===";
	if (S1 == S2)
		cout << "\nThe strings are equal.\n\n";
	else
		cout << "\nThe strings are not equal.\n\n";
	
	MyString S7;
	S1 = S1 + S7;
	cout << "\n===Demonstrating the addition operator of 2 null ptrs (S1 = S1 + S7)===";
	cout << "\nOUTPUT of S1: " << S1 << endl;

	S7 = S7 + S2;
	cout << "\n===Demonstrating the addition operator of 1 null ptr and 1 populated c-string being assigned to a null ptr (S7 = S7 + S2)===";
	cout << "\nOUTPUT of S7: " << S7 << endl;

	S2 = S1 + S2;
	cout << "\n===Demonstrating the addition operator of 1 null ptr and 1 populated c-string being assigned to a populated c-string (S2 = S1 + S2)===";
	cout << "\nOUTPUT of S2: " << S2 << endl;

	S2 = S1;
	cout << "\n===Demonstrating the overloaded assignment operator for assigning c-string null ptr to an already populated c-string(S2 = S1)===";
	cout << "\nOUTPUT of S2: " << S2;

	S2 = testFunc(S2);
	cout << "\nReturned S2: " << S2;

	cout << "\n\n****The program has finished. Now running destructors for each initialized MyString.****";
	return 0;
}

//======================================================
// testFunc: just for testing sending and receiving MyString from a function
// parameters: MyString
// return type: MyString
//======================================================
MyString testFunc(MyString input)
{
	input = "String 2";
	cout << "\n===Demonstrating passing and returning a MyString to and from a function (passing S2, reassigning it to: String 2, then returning it)===";

	return input;
}