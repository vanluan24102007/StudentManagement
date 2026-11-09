#include "FileManager.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Save Students
bool FileManager::saveToFile(
    const vector<Student>& students,
    const string& filename
) {

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file for saving!" << endl;
        return false;
    }

    for (const Student& student : students) {

        file << quoted(student.getStudentId()) << ' '
            << quoted(student.getFullName()) << ' '
            << student.getAge() << ' '
            << quoted(student.getGender()) << ' '
            << quoted(student.getEmail()) << ' '
            << student.getAverageScore() << '\n';
    }

    if (!file.good()) {
        cout << "Error while writing file!" << endl;
        return false;
    }

    file.close();

    cout << "Data saved successfully!" << endl;

    return true;
}

// Load Students
bool FileManager::loadFromFile(
    vector<Student>& students,
    const string& filename
) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file for loading!" << endl;
        return false;
    }

    vector<Student> loadedStudents;

    string studentId;
    string fullName;
    string gender;
    string email;

    int age;
    double averageScore;

    while (
        file >> quoted(studentId)
        >> quoted(fullName)
        >> age
        >> quoted(gender)
        >> quoted(email)
        >> averageScore
        ) {

        loadedStudents.emplace_back(
            studentId,
            fullName,
            age,
            gender,
            email,
            averageScore
        );
    }

    if (!file.eof()) {
        cout << "File contains invalid data!" << endl;
        return false;
    }

    students = loadedStudents;

    file.close();

    cout << "Data loaded successfully!" << endl;

    return true;
}