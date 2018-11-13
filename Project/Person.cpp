/* Implementation of the class Person */

#include "Person.h"

// Constructor
Person::Person()
{
	lastName = "N/A";
	firstName = "N/A";
}

// setName
void Person::setName(const string& newFirstName, const string& newLastName)
{
	lastName = newLastName;
	firstName = newFirstName;
}

// getLastName
string Person::getLastName() const
{
	return lastName;
}

// getName
void Person::getName(string& first, string& last) const
{
	first = firstName;
	last = lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

// Destructor
Person::~Person()
{

}
