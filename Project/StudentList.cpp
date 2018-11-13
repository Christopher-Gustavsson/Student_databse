#include "StudentList.h"



// default constructor
StudentList::StudentList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

// addStudent
void StudentList::addStudent(Student& newStudent)
{
	if (count == 0)
	{
		first = new Node(newStudent, NULL);
		last = first;
		count++;
	}
	else
	{
		first = new Node(newStudent, first);
		count++;
	}
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}

// printStudentByID
void StudentList::printStudentByID(int newID, double rate) const
{
	if (count == 0)
		cout << "List is epmty.";
	else
	{
		Node* current = first;
		bool found = false;

		while (current != NULL && !found)
		{
			if (current->getStudent().getID() == newID)
			{
				current->getStudent().printStudentInfo(rate);
				found = true;
			}
			else
				current = current->getNext();
		}
		if (!found)
			cout << "No student with the ID " << newID << " found in the list" << endl;
	}
}


// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNo) const
{
	if (count == 0)
		cout << "List is empty." << endl;
	else
	{
		Node* current = first;
		bool found = false;

		while (current != NULL)
		{
			if (current->getStudent().getNumberOfCourses() > 0)
			{
				if (current->getStudent().isEnrolledInCourse(courseNo))
				{
					current->getStudent().printStudentInfo();
					found = true;
				}
			}
			
			current = current->getNext();
		}

		if (!found)
			cout << "No student enrolled in " << courseNo << endl;
	}
}


// printStudentsByName
void StudentList::printStudentsByName(const string& newLastName) const
{
	if (count == 0)
		cout << "The list is empty." << endl;
	else
	{
		Node* current = first;
		bool found = false;

		while (current != NULL)
		{
			if (current->getStudent().getLastName() == newLastName)
			{
				current->getStudent().printStudentInfo();
				found = true;
			}

			current = current->getNext();
		}

		if (!found)
			cout << "No student with the last name " << newLastName << " is in the list." << endl;
	}
}


// printStudentsOnHold
void StudentList::printStudentsOnHold(double rate) const
{
	if (count == 0)
		cout << "The list is empty." << endl;
	else
	{
		Node* current = first;
		bool found = false;

		while (current != NULL)
		{
			if (!(current->getStudent()).isTuitionPaid())
			{
				current->getStudent().printStudentInfo();
				cout << fixed << setw(16) << "Amount due: " << "$" << current->getStudent().billingAmount(rate) << endl;
				found = true;
			}
			current = current->getNext();
		}
		
		if (!found)
			cout << "There are no students on hold" << endl;
	}
}


// printAllStudents
void StudentList::printAllStudents(double rate) const
{
	if (count == 0)
		cout << "The list is empty." << endl;
	else
	{
		Node* current = first;

		while (current != NULL)
		{
			current->getStudent().printStudentInfo(rate);
			current = current->getNext();
		}
	}
}


// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& outp, double tuitionRate) const
{
	if (count == 0)
		outp << "Cannot print. No students in the list." << endl;
	else
	{
		Node* current = first;
		while (current != NULL)
		{
			current->getStudent().printStudentInfoToFile(outp, tuitionRate);
			current = current->getNext();
		}
	}
}


// destroyStudentList
void StudentList::destroyStudentList()
{
		Node* current;
		while (first != NULL)
		{
			current = first;
			first = first->getNext();  
			delete current;
		}

	first = NULL;
	last = NULL;
	count = 0;
}


// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}
