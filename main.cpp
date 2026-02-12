#include <iostream>
#include <vector>
#include "student.h"
#include "session.h"

using namespace std;

// Global vectors
vector<Student> students;
vector<AttendanceSession> sessions;

// ================= STUDENT FUNCTIONS =================

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

// ================= SESSION FUNCTIONS =================

void createSession() {
    string course, date, time;
    int duration;

    cout << "Enter course code: ";
    cin >> course;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    cout << "Enter start time: ";
    cin >> time;

    cout << "Enter duration (minutes): ";
    cin >> duration;

    sessions.push_back(
        AttendanceSession(course, date, time, duration)
    );

    cout << "Session created successfully!" << endl;
}

void viewSessions() {
    if (sessions.empty()) {
        cout << "No sessions created yet." << endl;
        return;
    }

    for (int i = 0; i < sessions.size(); i++) {
        cout << "\nSession " << i + 1 << endl;
        sessions[i].displaySession();
    }
}

// ================= MAIN MENU =================

int main() {
    int choice;

    do {
        cout << "\n==============================" << endl;
        cout << " DIGITAL ATTENDANCE SYSTEM " << endl;
        cout << "==============================" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Create Attendance Session" << endl;
        cout << "4. View Sessions" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: createSession(); break;
            case 4: viewSessions(); break;
            case 0: cout << "Exiting system..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
