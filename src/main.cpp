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

        courses.push_back(c);

        cout << "Grade Point: " << gradeToPoint(c.grade) << endl;
    }

    cout << "\nCourse details entered:\n";
    for (const auto &c : courses)
    {
        cout << c.name << " | Credits: " << c.credits << " | Grade: " << c.grade << endl;
    }

    return 0;
}