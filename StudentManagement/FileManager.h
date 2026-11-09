#pragma once


#include <vector>
#include <string>
#include "Student.h"

class FileManager {
public:
    static bool saveToFile(
        const std::vector<Student>& students,
        const std::string& filename
    );

    static bool loadFromFile(
        std::vector<Student>& students,
        const std::string& filename
    );
};