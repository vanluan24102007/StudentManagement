#pragma once

#include <vector>
#include <string>
#include "Student.h"

class StudentManager {
private:
    std::vector<Student> students;

public:
    // Add
    bool addStudent(const Student& student);

    // Find
    int findStudentById(const std::string& studentId) const;

    // Display
    void displayStudents() const;

    // Search
    void searchStudentById(const std::string& studentId) const;
    void searchStudentsByName(const std::string& name) const;

    // Update
    bool updateStudent(
        const std::string& studentId,
        const std::string& fullName,
        int age,
        const std::string& gender,
        const std::string& email,
        double averageScore
    );

    // Delete
    bool deleteStudent(const std::string& studentId);

    // Sort
    void sortStudentsByName();
    void sortStudentsByScore(bool ascending);

    // Statistics
    void displayStatistics() const;

    // File handling support
    const std::vector<Student>& getStudents() const;
    void setStudents(const std::vector<Student>& newStudents);
};