#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Print all courses alphanumerically
void printSortedCourses() {
    // Make sure there are courses
    bool hasCourses = false;

    // Vector to store all course numbers from the table
    vector<string> courseNumbers;

    // Get all course numbers from the hash table
    for (int i = 0; i < tableSize; ++i) {
        for (auto& course : table[i]) {
            courseNumbers.push_back(course.courseNumber);
            hasCourses = true;
        }
    }

    // If no courses are in the hash table, print error and return
    if (!hasCourses) {
        cout << "No courses found." << endl;
        return;
    }

    // Sort the course numbers
    sort(courseNumbers.begin(), courseNumbers.end());

    // For each sorted course number, find and print the course details
    for (const auto& courseNumber : courseNumbers) {
        Course* course = search(courseNumber);
        if (course) {
            // Print course details if found
            cout << course->courseNumber << ", " << course->courseName << endl;
        }
        else {
            cout << "Course " << courseNumber << " not found." << endl;
        }
    }
}


