#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <vector>
using namespace std;

class AttendanceSession {
public:
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
};

#endif
