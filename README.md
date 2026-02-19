# DIGITAL-ATTENDANCE-SYSTEM
Digital Attendance System - EEE227 MID SEM
# Digital Attendance System (C++)

## Course Information
Name:IBRAHIM HAMZA
ID:01243746D
Name:COMBEY YVES YAO
ID:01243747D
- Course Title: Introduction to C++ Programming  
- Course Code:EEE227  
- Programme: HND Electrical Engineering (Level 200)  
- Assessment Type:Mid-Semester Capstone Project  
- Platform:Windows (Offline First)  
- Development Environment:VS Code  
- Version Control:GitHub  

---

## Project Description
The Digital Attendance System is a console-based application developed using C++ to replace traditional paper-based attendance systems used in lecture halls.

The system is designed for hour-based lectures and allows lecturers to digitally manage student attendance, reduce delays, prevent loss of records, and generate reliable attendance summaries.  
All records are stored using text files, ensuring data persistence even after the program is closed.

---

## Features

### Student Management
- Register students using **Name** and **Index Number**
- View all registered students
- Search for a student by index number
- Automatically save and load student records from file

### Attendance Session Management
- Create lecture attendance sessions with:
  - Course code
  - Date
  - Start time
  - Duration (hours)
- Mark attendance for each student
- Attendance statuses:
  - **P** – Present
  - **A** – Absent
  - **L** – Late

### Reports and Summary
- Display attendance list for a session
- Generate summary counts of:
  - Present students
  - Absent students
  - Late students

### File Storage
- Student records stored in `students.txt`
- Attendance sessions saved as:
