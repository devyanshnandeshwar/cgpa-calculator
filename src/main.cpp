#include <iostream>
#include <vector>
#include "../include/course.h"

using namespace std;

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
    }

    cout << "\nCourse details entered:\n";
    for (const auto &c : courses)
    {
        cout << c.name << " | Credits: " << c.credits << " | Grade: " << c.grade << endl;
    }

    return 0;
}