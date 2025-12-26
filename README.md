# CGPA Calculator (C++)

Command-line CGPA calculator in C++ that collects course details, computes CGPA using weighted grade points, saves results to a file, and supports searching and sorting operations.

## Features

- Capture course name, credits, and letter grade (S/A/B/C/D/E/F)
- Convert letter grades to grade points (S=10 ... F=0)
- Compute total credits, total grade points, and CGPA (weighted average)
- Display course-wise table plus summary stats
- Save results to `data/student.txt` and read them back
- Search courses by name; sort by credits or by grade points
- Modular structure with clear comments for learning/reference

## Project Structure

```
cgpa-calculator/
├─ include/
│  └─ course.h         # Course struct and gradeToPoint declaration
├─ src/
│  └─ main.cpp         # Program entry and core logic
├─ data/
│  └─ student.txt      # Output file (created/overwritten by program)
└─ README.md
```

## CGPA Formula

CGPA = (Sum of (Course Credits × Grade Points)) / (Total Credits)

## Requirements

- C++17-compatible compiler (tested with g++)
- POSIX-like shell (commands below assume bash)

## Build and Run

```bash
# Clone
git clone https://github.com/<your-username>/cgpa-calculator.git
cd cgpa-calculator

# Build (include path is needed because main.cpp includes ../include)
g++ -std=c++17 -Iinclude src/main.cpp -o cgpa

# Run
./cgpa
```

The program writes output to `data/student.txt`; ensure the `data/` directory exists (it is present by default).

## Usage Flow

1. Enter the number of courses.
2. For each course, provide: course name, credits, and letter grade (S/A/B/C/D/E/F).
3. The program prints a table of courses, totals, and CGPA.
4. Data is saved to `data/student.txt` and then displayed back to you.
5. Choose an extra operation:
   - 1: Search a course by exact name (linear search)
   - 2: Sort courses by credits (descending)
   - 3: Sort courses by grade points (descending)

## Grade Scale

```
Grade : Points
S     : 10
A     : 9
B     : 8
C     : 7
D     : 6
E     : 5
F     : 0
```

## Notes

- Input is minimal; ensure grades are valid letters (S/A/B/C/D/E/F). Invalid grades return -1 and will affect calculations.
- The file is overwritten on each run; back it up if you need to keep older outputs.
- Sorting uses `std::sort` with custom comparators; searching is linear for simplicity.
