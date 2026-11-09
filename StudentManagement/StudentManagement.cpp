#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

#include "StudentManager.h"
#include "FileManager.h"

using namespace std;

// Read integer
int readInt(const string& message) {

    string input;
    int value;
    char extra;

    while (true) {

        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra)) {
            return value;
        }

        cout << "Invalid input! Please enter an integer." << endl;
    }
}

// Read double
double readDouble(const string& message) {

    string input;
    double value;
    char extra;

    while (true) {

        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra) && isfinite(value)) {
            return value;
        }

        cout << "Invalid input! Please enter a valid number." << endl;
    }
}

// Read non-empty string
string readNonEmptyString(const string& message) {

    string value;

    while (true) {

        cout << message;
        getline(cin, value);

        if (!value.empty() &&
            value.find_first_not_of(" \t\r\n") != string::npos) {
            return value;
        }

        cout << "This field cannot be empty!" << endl;
    }
}

// Read age
int readAge() {

    int age;

    do {
        age = readInt("Enter Age: ");

        if (age <= 0) {
            cout << "Age must be greater than 0!" << endl;
        }

    } while (age <= 0);

    return age;
}

// Read score
double readScore() {

    double score;

    do {
        score = readDouble("Enter Average Score: ");

        if (score < 0 || score > 10) {
            cout << "Score must be between 0 and 10!" << endl;
        }

    } while (score < 0 || score > 10);

    return score;
}

// Add Student
void addStudent(StudentManager& manager) {

    cout << "\n===== ADD STUDENT =====" << endl;

    string studentId = readNonEmptyString("Enter Student ID: ");
    string fullName = readNonEmptyString("Enter Full Name: ");
    int age = readAge();
    string gender = readNonEmptyString("Enter Gender: ");
    string email = readNonEmptyString("Enter Email: ");
    double averageScore = readScore();

    Student student(
        studentId,
        fullName,
        age,
        gender,
        email,
        averageScore
    );

    manager.addStudent(student);
}

// Update Student
void updateStudent(StudentManager& manager) {

    cout << "\n===== UPDATE STUDENT =====" << endl;

    string studentId = readNonEmptyString("Enter Student ID to update: ");

    if (manager.findStudentById(studentId) == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    string fullName = readNonEmptyString("Enter New Full Name: ");
    int age = readAge();
    string gender = readNonEmptyString("Enter New Gender: ");
    string email = readNonEmptyString("Enter New Email: ");
    double averageScore = readScore();

    manager.updateStudent(
        studentId,
        fullName,
        age,
        gender,
        email,
        averageScore
    );
}

// Main
int main() {

    StudentManager manager;

    const string filename = "students.txt";

    int choice;

    do {

        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student By ID" << endl;
        cout << "4. Search Student By Name" << endl;
        cout << "5. Update Student" << endl;
        cout << "6. Delete Student" << endl;
        cout << "7. Sort Students By Name" << endl;
        cout << "8. Sort Students By Score (Ascending)" << endl;
        cout << "9. Sort Students By Score (Descending)" << endl;
        cout << "10. Display Statistics" << endl;
        cout << "11. Save Data" << endl;
        cout << "12. Load Data" << endl;
        cout << "0. Exit" << endl;

        choice = readInt("Enter your choice: ");

        switch (choice) {

        case 1:
            addStudent(manager);
            break;

        case 2:
            manager.displayStudents();
            break;

        case 3: {
            string studentId =
                readNonEmptyString("Enter Student ID: ");

            manager.searchStudentById(studentId);
            break;
        }

        case 4: {
            string name =
                readNonEmptyString("Enter Student Name: ");

            manager.searchStudentsByName(name);
            break;
        }

        case 5:
            updateStudent(manager);
            break;

        case 6: {
            string studentId =
                readNonEmptyString("Enter Student ID to delete: ");

            manager.deleteStudent(studentId);
            break;
        }

        case 7:
            manager.sortStudentsByName();
            break;

        case 8:
            manager.sortStudentsByScore(true);
            break;

        case 9:
            manager.sortStudentsByScore(false);
            break;

        case 10:
            manager.displayStatistics();
            break;

        case 11:
            FileManager::saveToFile(
                manager.getStudents(),
                filename
            );
            break;

        case 12: {
            vector<Student> loadedStudents;

            if (FileManager::loadFromFile(loadedStudents, filename)) {
                manager.setStudents(loadedStudents);
            }

            break;
        }

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}