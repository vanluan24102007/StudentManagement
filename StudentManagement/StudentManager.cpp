#include "StudentManager.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;

// Validate student information
namespace {

    bool isValidStudent(const Student& student) {

        if (student.getStudentId().empty() ||
            student.getFullName().empty() ||
            student.getGender().empty() ||
            student.getEmail().empty()) {
            cout << "Student information cannot be empty!" << endl;
            return false;
        }

        if (student.getAge() <= 0) {
            cout << "Age must be greater than 0!" << endl;
            return false;
        }

        if (!isfinite(student.getAverageScore()) ||
            student.getAverageScore() < 0 ||
            student.getAverageScore() > 10) {
            cout << "Score must be between 0 and 10!" << endl;
            return false;
        }

        size_t atPosition = student.getEmail().find('@');
        size_t dotPosition = student.getEmail().find('.', atPosition);

        if (atPosition == string::npos ||
            dotPosition == string::npos ||
            atPosition == 0 ||
            dotPosition <= atPosition + 1 ||
            dotPosition == student.getEmail().length() - 1) {
            cout << "Invalid email format!" << endl;
            return false;
        }

        return true;
    }

}

// Add Student
bool StudentManager::addStudent(const Student& student) {

    if (!isValidStudent(student)) {
        return false;
    }

    if (findStudentById(student.getStudentId()) != -1) {
        cout << "Student ID already exists!" << endl;
        return false;
    }

    students.push_back(student);

    cout << "Student added successfully!" << endl;
    return true;
}

// Find Student By ID
int StudentManager::findStudentById(const string& studentId) const {

    for (int i = 0; i < static_cast<int>(students.size()); i++) {

        if (students[i].getStudentId() == studentId) {
            return i;
        }
    }

    return -1;
}

// Display Students
void StudentManager::displayStudents() const {

    if (students.empty()) {
        cout << "Student list is empty!" << endl;
        return;
    }

    cout << "\n===== STUDENT LIST =====" << endl;

    for (const Student& student : students) {
        student.displayInfo();
        cout << "----------------------" << endl;
    }
}

// Search By ID
void StudentManager::searchStudentById(const string& studentId) const {

    int index = findStudentById(studentId);

    if (index == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "\n===== SEARCH RESULT =====" << endl;
    students[index].displayInfo();
}

// Search By Name
void StudentManager::searchStudentsByName(const string& name) const {

    if (name.empty()) {
        cout << "Search name cannot be empty!" << endl;
        return;
    }

    bool found = false;

    cout << "\n===== SEARCH RESULT =====" << endl;

    for (const Student& student : students) {

        if (student.getFullName().find(name) != string::npos) {
            student.displayInfo();
            cout << "----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

// Update Student
bool StudentManager::updateStudent(
    const string& studentId,
    const string& fullName,
    int age,
    const string& gender,
    const string& email,
    double averageScore
) {

    int index = findStudentById(studentId);

    if (index == -1) {
        cout << "Student not found!" << endl;
        return false;
    }

    Student updatedStudent(
        studentId,
        fullName,
        age,
        gender,
        email,
        averageScore
    );

    if (!isValidStudent(updatedStudent)) {
        return false;
    }

    students[index].setFullName(fullName);
    students[index].setAge(age);
    students[index].setGender(gender);
    students[index].setEmail(email);
    students[index].setAverageScore(averageScore);

    cout << "Student updated successfully!" << endl;

    return true;
}

// Delete Student
bool StudentManager::deleteStudent(const string& studentId) {

    int index = findStudentById(studentId);

    if (index == -1) {
        cout << "Student not found!" << endl;
        return false;
    }

    students.erase(students.begin() + index);

    cout << "Student deleted successfully!" << endl;

    return true;
}

// Sort By Name
void StudentManager::sortStudentsByName() {

    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getFullName() < b.getFullName();
        }
    );

    cout << "Students sorted by name!" << endl;
}

// Sort By Score
void StudentManager::sortStudentsByScore(bool ascending) {

    sort(students.begin(), students.end(),
        [ascending](const Student& a, const Student& b) {

            if (ascending) {
                return a.getAverageScore() < b.getAverageScore();
            }

            return a.getAverageScore() > b.getAverageScore();
        }
    );

    cout << "Students sorted by score!" << endl;
}

// Statistics
void StudentManager::displayStatistics() const {

    if (students.empty()) {
        cout << "No student data available!" << endl;
        return;
    }

    double totalScore = 0;
    double highestScore = students[0].getAverageScore();
    double lowestScore = students[0].getAverageScore();

    for (const Student& student : students) {

        double score = student.getAverageScore();

        totalScore += score;

        if (score > highestScore) {
            highestScore = score;
        }

        if (score < lowestScore) {
            lowestScore = score;
        }
    }

    double averageScore = totalScore / students.size();

    cout << "\n===== STUDENT STATISTICS =====" << endl;

    cout << "Total Students: " << students.size() << endl;

    cout << fixed << setprecision(2);

    cout << "Average Score: " << averageScore << endl;
    cout << "Highest Score: " << highestScore << endl;
    cout << "Lowest Score: " << lowestScore << endl;
}

// Get Students
const vector<Student>& StudentManager::getStudents() const {
    return students;
}

// Replace Student List
void StudentManager::setStudents(const vector<Student>& newStudents) {
    students = newStudents;
}