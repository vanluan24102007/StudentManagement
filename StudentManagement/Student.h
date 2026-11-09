#pragma once

#include <string>

class Student {
private:
    std::string studentId;
    std::string fullName;
    int age;
    std::string gender;
    std::string email;
    double averageScore;

public:
    Student(
        std::string studentId,
        std::string fullName,
        int age,
        std::string gender,
        std::string email,
        double averageScore
    );

    // Getters
    std::string getStudentId() const;
    std::string getFullName() const;
    int getAge() const;
    std::string getGender() const;
    std::string getEmail() const;
    double getAverageScore() const;

    // Setters
    void setFullName(std::string fullName);
    void setAge(int age);
    void setGender(std::string gender);
    void setEmail(std::string email);
    void setAverageScore(double averageScore);

    // Display
    void displayInfo() const;
};