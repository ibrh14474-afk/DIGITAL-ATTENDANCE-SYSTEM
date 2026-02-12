#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    string indexNumber;

    Student() {}

    Student(string n, string idx) {
        name = n;
        indexNumber = idx;
    }

    void display() {
        cout << "Name: " << name << " | Index Number: " << indexNumber << endl;
    }
};

#endif
