/* Interface of the class Person */

/*
Gustavsson, Christopher
CS A250
November 05, 2015

Project1
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	// Constructor
	Person();

	// setName
	void setName(const string& newFirstName, const string& newLastName);

	// getLastName
	string getLastName() const;

	// getName
	void getName(string& first, string& last) const;

	// printName
	void printName() const;

	// Destructor
	~Person();

private:
	string lastName;
	string firstName;
};


#endif