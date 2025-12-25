#include <iostream>
#include <vector>
#include "../include/course.h"

using namespace std;

int gradeToPoint(char grade)
{
    switch (grade)
    {
    case 'S':
        return 10;
    case 'A':
        return 9;
    case 'B':
        return 8;
    case 'C':
        return 7;
    case 'D':
        return 6;
    case 'E':
        return 5;
    case 'F':
        return 0;
    default:
        return -1; // Invalid grade
    }
}

int main()
{
    int n;
    vector<Course> courses;

    int totalCredits = 0;
    int totalGradePoints = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Course c;

        cout << "\nEnter course " << i + 1 << " details\n";
        cout << "Course name: ";
        cin >> c.name;

        cout << "Credits: ";
        cin >> c.credits;

        cout << "Grade (S/A/B/C/D/F): ";
        cin >> c.grade;
        c.grade = toupper(c.grade);

        int gradePoint = gradeToPoint(c.grade);
        int courseGradePOints = c.credits * gradePoint;

        totalCredits += c.credits;
        totalGradePoints += gradePoint * c.credits;

        courses.push_back(c);
    }

    double cgpa = 0.0;
    if (totalCredits > 0)
    {
        cgpa = (double)totalGradePoints / totalCredits;
    }

    cout << "\n------ Result Summary ------\n";
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}