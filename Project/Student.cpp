#include "Student.h"

// default constructor
Student::Student()
{
	studentID = 0;
	numberOfCourses = 0;
	tuitionWasPaid = false;
}

// setStudentInfo
void Student::setStudentInfo(const string& newFirstName, const string& newLastName, int newIDNumber, bool newTuitionWasPaid, const vector<Course>& newCourse)
{
	setName(newFirstName, newLastName);
	studentID = newIDNumber;
	tuitionWasPaid = newTuitionWasPaid;
	coursesEnrolled = newCourse;
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return static_cast<int>(coursesEnrolled.size());
}

// getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
	int totalCredits = 0;
	int size = getNumberOfCourses();
	
	for (int i = 0; i < size; i++)
	{
		totalCredits += coursesEnrolled.at(i).getCourseCredits();
	}
	return totalCredits;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// isEnrolledInCourse
bool Student::isEnrolledInCourse(const string& courseNo) const
{
	int size = getNumberOfCourses();

	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (courseNo == coursesEnrolled.at(i).getCourseNumber())
				return true;
		}
	}
	return false;
}

// getGpa
double Student::getGpa() const
{
	double totalPoints = 0.0;
	double gradePerCourse = 0.0;
	int creditHours = 0;
	char letterGrade;
	int size = getNumberOfCourses();

	for (int i = 0; i < size; i++)
	{
		letterGrade = coursesEnrolled.at(i).getCourseGrade();
		creditHours = coursesEnrolled.at(i).getCourseCredits();

		switch (letterGrade)
		{
		case 'A':
			gradePerCourse = 4.00 * creditHours;
			break;

		case 'B':
			gradePerCourse = 3.00 * creditHours;
			break;

		case 'C':
			gradePerCourse = 2.00 * creditHours;
			break;
		}

		totalPoints += gradePerCourse;
	}

	return (totalPoints / getCreditsEnrolled());
}

// billingAmount
double Student::billingAmount(double rate) const
{
	return getCreditsEnrolled() * rate;
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << studentID << " - ";
	printName();
}

// printStudentInfo (overloaded)
void Student::printStudentInfo(double tuitionRate) const
{
	cout << "Student Name: ";
	printName();
	cout << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses enrolled: " << getNumberOfCourses() << endl;
	cout << endl;

	cout << setw(14) << left << "Course No" << setw(13) << left << "Course Name" << setw(9) << left << "Credits" << "Grade" << endl;

	int numOfCourses = getNumberOfCourses();

	if (tuitionWasPaid)
	{
		for (int i = 0; i < numOfCourses; i++)
		{
			cout << setw(14) << left << coursesEnrolled.at(i).getCourseNumber() << setw(17) << left << coursesEnrolled.at(i).getCourseName()
				<< setw(8) << left << coursesEnrolled.at(i).getCourseCredits() << coursesEnrolled.at(i).getCourseGrade() << endl;
		}

		cout << endl;
		cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		cout << "Current Term GPA: " << fixed << setprecision(2) << getGpa() << endl;
	}
	else
	{
		for (int i = 0; i < numOfCourses; i++)
		{
			cout << setw(14) << left << coursesEnrolled.at(i).getCourseNumber() << setw(17) << left << coursesEnrolled.at(i).getCourseName()
				<< setw(6) << left << coursesEnrolled.at(i).getCourseCredits() << "***" << endl;
		}

		cout << endl;
		cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		cout << "*** Grades are being held for not paying the tuition. ***" << endl;
		cout << "Amount Due: " << "$" << billingAmount(tuitionRate) << endl;
	}

	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
}

// getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled() const
{
	return coursesEnrolled;
}

//printStudentInfoToFile
void Student::printStudentInfoToFile(ofstream& out, double tuitionRate)
{
	out << "Student Name: ";
	string first, last;
	getName(first, last);
	out << last << ", " << first << endl;
	out << endl;

	out << "Student ID: " << studentID << endl;
	out << "Number of courses enrolled: " << getNumberOfCourses() << endl;
	out << endl;

	out << setw(14) << left << "Course No" << setw(13) << left << "Course Name" << setw(9) << left << "Credits" << "Grade" << endl;

	int numOfCourses = getNumberOfCourses();

	if (tuitionWasPaid)
	{
		for (int i = 0; i < numOfCourses; i++)
		{
			out << setw(14) << left << coursesEnrolled.at(i).getCourseNumber() << setw(17) << left << coursesEnrolled.at(i).getCourseName()
				<< setw(8) << left << coursesEnrolled.at(i).getCourseCredits() << coursesEnrolled.at(i).getCourseGrade() << endl;
		}

		out << endl;
		out << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		out << "Current Term GPA: " << fixed << setprecision(2) << getGpa() << endl;
	}
	else
	{
		for (int i = 0; i < numOfCourses; i++)
		{
			out << setw(14) << left << coursesEnrolled.at(i).getCourseNumber() << setw(17) << left << coursesEnrolled.at(i).getCourseName()
				<< setw(6) << left << coursesEnrolled.at(i).getCourseCredits() << "***" << endl;
		}

		out << endl;
		out << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		out << "*** Grades are being held for not paying the tuition. ***" << endl;
		out << "Amount Due: " << "$" << billingAmount(tuitionRate) << endl;
	}

	out << endl;
	out << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	out << endl;
}

// destructor
Student::~Student()
{

}