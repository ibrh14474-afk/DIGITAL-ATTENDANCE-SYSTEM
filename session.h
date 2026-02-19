#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class AttendanceSession {
public:
    // Week 2 (unchanged)
    string courseCode;
    string date;
    string startTime;
    int duration;

    AttendanceSession() {}

    AttendanceSession(string c, string d, string t, int dur) {
        courseCode = c;
        date = d;
        startTime = t;
        duration = dur;
    }

    void displaySession() {
        cout << "Course Code: " << courseCode << endl;
        cout << "Date: " << date << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }

    // 🔵 Week 3 additions (ONLY THESE)
    map<string, string> attendance;

    void markAttendance(string indexNumber);
    void displayAttendance();
    void displayAttendanceSummary();
};

#endif
