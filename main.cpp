#include <iostream>
#include <vector>
#include "student.h"
#include "session.h"

using namespace std;

int main() {
    vector<Student> students;

    // Load students from file at startup
    Student::loadFromFile(students);

    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Index Number\n";
        cout << "4. Create Attendance Session\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, index;

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Index Number: ";
            cin >> index;

            students.push_back(Student(name, index));
            Student::saveToFile(students);

            cout << "Student registered successfully.\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students registered yet.\n";
            } else {
                cout << "\nRegistered Students:\n";
                for (const auto& s : students) {
                    s.display();
                }
            }
        }

        else if (choice == 3) {
            string searchIndex;
            bool found = false;

            cout << "Enter Index Number to search: ";
            cin >> searchIndex;

            for (const auto& s : students) {
                if (s.getIndexNumber() == searchIndex) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            if (students.empty()) {
                cout << "No students available. Register students first.\n";
            } else {
                AttendanceSession session;
                session.createSession();

                vector<string> indexes;
                for (const auto& s : students) {
                    indexes.push_back(s.getIndexNumber());
                }

                session.markAttendance(indexes);
                session.displayAttendance();
                session.displaySummary();
                session.saveToFile();

                cout << "Attendance session saved successfully.\n";
            }
        }

        else if (choice == 0) {
            cout << "Exiting system. Goodbye!\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
