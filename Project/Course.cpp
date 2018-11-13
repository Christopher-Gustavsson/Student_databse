#include "Course.h"

// default constructor
Course::Course()
{
	courseCredits = 0;
	courseGrade = '*';
}

// setCourseInfo
void Course::setCourseInfo(const string& newCourse, const string& newCourseNo, char newGrade, int newCourseCredits)
{
	courseName = newCourse;
	courseNo = newCourseNo;
	courseGrade = newGrade;
	courseCredits = newCourseCredits;
}

// printCourseInfo
void Course::printCourseInfo(bool paid) const
{
	if (paid)
	{
		cout << courseNo << setw(15) << courseName << setw(6) << courseCredits << setw(6) << courseGrade;
	}
	else
		cout << "*";
}

// getCourseCredits
int Course::getCourseCredits() const
{
	return courseCredits;
}

// getCourseNumber
string Course::getCourseNumber() const
{
	return courseNo;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCourseGrade
char Course::getCourseGrade() const
{
	return courseGrade;
}

// destructor
Course::~Course()
{

}
