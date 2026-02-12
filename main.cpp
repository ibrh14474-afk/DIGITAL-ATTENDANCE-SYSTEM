#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

vector<Student> students;

void registerStudent() {
    string name, index;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter index number: ";
    getline(cin, index);

    students.push_back(Student(name, index));
    cout << "Student registered successfully!" << endl;
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students registered yet." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". ";
        students[i].display();
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- STUDENT MANAGEMENT ---" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. View Students" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
        }
    } while (choice != 0);

    return 0;
}
