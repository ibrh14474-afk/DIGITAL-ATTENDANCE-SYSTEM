#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
private:
    string name;
    string indexNumber;

public:
    Student() {}

    Student(string n, string idx) {
        name = n;
        indexNumber = idx;
    }

    string getName() const {
        return name;
    }

    string getIndexNumber() const {
        return indexNumber;
    }

    void display() const {
        cout << "Name: " << name
             << " | Index Number: " << indexNumber << endl;
    }

    // File operations
    static void saveToFile(const vector<Student>& students) {
        ofstream file("students.txt");

        for (const auto& s : students) {
            file << s.indexNumber << "," << s.name << endl;
        }

        file.close();
    }

    static void loadFromFile(vector<Student>& students) {
        ifstream file("students.txt");
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string idx, n;

            getline(ss, idx, ',');
            getline(ss, n);

            students.push_back(Student(n, idx));
        }

        file.close();
    }
};

#endif
