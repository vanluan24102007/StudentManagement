#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student(
    string studentId,
    string fullName,
    int age,
    string gender,
    string email,
    double averageScore
) {
    this->studentId = studentId;
    this->fullName = fullName;
    this->age = age;
    this->gender = gender;
    this->email = email;
    this->averageScore = averageScore;
}

// Getters
string Student::getStudentId() const {
    return studentId;
}

string Student::getFullName() const {
    return fullName;
}

int Student::getAge() const {
    return age;
}

string Student::getGender() const {
    return gender;
}

string Student::getEmail() const {
    return email;
}

double Student::getAverageScore() const {
    return averageScore;
}

// Setters
void Student::setFullName(string fullName) {
    this->fullName = fullName;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGender(string gender) {
    this->gender = gender;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAverageScore(double averageScore) {
    this->averageScore = averageScore;
}

// Display
void Student::displayInfo() const {
    cout << "Student ID: " << studentId << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Email: " << email << endl;

    cout << "Average Score: "
        << fixed << setprecision(2)
        << averageScore << endl;
}