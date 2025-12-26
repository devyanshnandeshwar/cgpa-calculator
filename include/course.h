/**
 * @file course.h
 * @brief Header file defining Course structure and grade conversion function
 *
 * This file contains the Course data structure used to store course information
 * and declares the grade-to-point conversion function.
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

/**
 * @struct Course
 * @brief Represents a single course with its details
 *
 * This structure holds information about a course including:
 * - Course name (e.g., "Mathematics", "Physics")
 * - Number of credits (weightage of the course)
 * - Letter grade obtained (S, A, B, C, D, E, F)
 */
struct Course
{
    string name; // Name of the course
    int credits; // Credit hours for the course
    char grade;  // Letter grade (S/A/B/C/D/E/F)
};

/**
 * @brief Converts a letter grade to its corresponding grade point
 * @param grade The letter grade (S/A/B/C/D/E/F)
 * @return Integer grade point (10 for S, 9 for A, ..., 0 for F)
 */
int gradeToPoint(char grade);

#endif