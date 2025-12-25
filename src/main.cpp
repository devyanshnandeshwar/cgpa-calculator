#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "../include/course.h"

using namespace std;

// FUnction to convert grade to grade point
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

// Search function to find a course by name
// algorithm: linear search
// Time Complexity: O(n)
void searchCourse(const vector<Course> &courses, const string &key)
{
    bool found = false;

    for (const auto &c : courses)
    {
        if (c.name == key)
        {
            cout << "\nCourse Found: \n";
            cout << "Name: " << c.name
                 << ", Credits: " << c.credits
                 << ", Grade: " << c.grade << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nCourse not found. \n";
    }
}

bool sortByCredits(const Course &a, const Course &b)
{
    return a.credits > b.credits; // descending
}

bool sortByGradePoint(const Course &a, const Course &b)
{
    return gradeToPoint(a.grade) > gradeToPoint(b.grade);
}

int main()
{
    int n;
    vector<Course> courses;

    int totalCredits = 0;
    int totalGradePoints = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    // Input course details
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

    // Calculate CGPA
    double cgpa = 0.0;
    if (totalCredits > 0)
    {
        cgpa = (double)totalGradePoints / totalCredits;
    }

    // Display course-wise details
    cout << "\n----- Course Details -----\n";
    cout << left << setw(15) << "Course"
         << setw(10) << "Credits"
         << setw(10) << "Grade"
         << setw(15) << "Grade Points" << endl;

    for (const auto &c : courses)
    {
        cout << left << setw(15) << c.name
             << setw(10) << c.credits
             << setw(10) << c.grade
             << setw(15) << gradeToPoint(c.grade)
             << endl;
    }

    // Display result summary
    cout << "\n------ Result Summary ------\n";
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "CGPA: " << cgpa << endl;

    // Save data to file
    ofstream outFile("data/student.txt");

    if (outFile.is_open())
    {
        outFile << "Course Details\n";
        outFile << "==========================\n";

        for (const auto &c : courses)
        {
            outFile << c.name << " "
                    << c.credits << " "
                    << c.grade << "\n";
        }

        outFile << "\nTotal Credits: " << totalCredits << "\n";
        outFile << "Total Grade Points: " << totalGradePoints << "\n";
        outFile << fixed << setprecision(2);
        outFile << "CGPA: " << cgpa << "\n";

        outFile.close();
        cout << "\nData saved successfully to file.\n";
    }
    else
    {
        cout << "\nError opening file for writing.\n";
    }

    // Read data from file
    ifstream inFile("data/student.txt");

    if (inFile.is_open())
    {
        cout << "\n----- Stored File Data -----\n";
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "\nError opening file for reading. \n";
    }

    int choice;
    cout << "\n ----- Extra Operations ----- \n";
    cout << "1. Search course by name \n";
    cout << "2. Sort courses by credits \n";
    cout << "3. Sort courses by grade points \n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string key;
        cout << "Enter course name to search: ";
        cin >> key;
        searchCourse(courses, key);
    }
    else if (choice == 2)
    {
        sort(courses.begin(), courses.end(), sortByCredits);
        cout << "\nCourses sorted by credits: \n";

        for (const auto &c : courses)
        {
            cout << c.name << " | Credits: " << c.credits
                 << " | Grade: " << c.grade
                 << " | Grade Point: " << gradeToPoint(c.grade)
                 << endl;
        }
    }
    else if (choice == 3)
    {
        sort(courses.begin(), courses.end(), sortByGradePoint);
        cout << "\nCourses sorted by grade points: \n";

        for (const auto &c : courses)
        {
            cout << c.name << " | Credits: " << c.credits
                 << " | Grade: " << c.grade
                 << " | Grade Point: " << gradeToPoint(c.grade)
                 << endl;
        }
    }
    else
    {
        cout << "Invalid choice. \n";
    }

    return 0;
}
