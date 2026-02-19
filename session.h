#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class AttendanceSession {
private:
    string courseCode;
    string date;
    string startTime;
    int duration; // in hours

    vector<string> studentIndexes;
    vector<char> attendanceStatus; // P, A, L

public:
    AttendanceSession() {}

    void createSession() {
        cout << "Course Code: ";
        cin >> courseCode;

        cout << "Date (YYYY-MM-DD): ";
        cin >> date;

        cout << "Start Time (HH:MM): ";
        cin >> startTime;

        cout << "Duration (hours): ";
        cin >> duration;
    }

    void markAttendance(const vector<string>& registeredIndexes) {
        for (const auto& index : registeredIndexes) {
            char status;
            cout << "Student " << index << " (P/A/L): ";
            cin >> status;

            studentIndexes.push_back(index);
            attendanceStatus.push_back(toupper(status));
        }
    }

    void displayAttendance() const {
        cout << "\nAttendance List\n";
        for (size_t i = 0; i < studentIndexes.size(); i++) {
            cout << studentIndexes[i]
                 << " - " << attendanceStatus[i] << endl;
        }
    }

    void displaySummary() const {
        int present = 0, absent = 0, late = 0;

        for (char s : attendanceStatus) {
            if (s == 'P') present++;
            else if (s == 'A') absent++;
            else if (s == 'L') late++;
        }

        cout << "\nSummary\n";
        cout << "Present: " << present << endl;
        cout << "Absent: " << absent << endl;
        cout << "Late: " << late << endl;
    }

    void saveToFile() const {
        string filename = "session_" + courseCode + "_" + date + ".txt";
        ofstream file(filename);

        file << courseCode << endl;
        file << date << endl;
        file << startTime << endl;
        file << duration << endl;

        for (size_t i = 0; i < studentIndexes.size(); i++) {
            file << studentIndexes[i]
                 << "," << attendanceStatus[i] << endl;
        }

        file.close();
    }
};

#endif
