#include <iostream>
#include "staff_student.h"
#include "student.h"
#include "staff.h"

using namespace std;

int main() {
    student_staff university;

    const int maxStaff = 100;
    staff staffArray[maxStaff];
    int staffCount=0;

    const int maxStudents = 100;
    student studentArray[maxStudents];
    int studentCount = 0;

    char choice;

    do {
        cout << "Enter information for a(n):\n";
        cout << "1. Student\n";
        cout << "2. Staff\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "\nEnter information for a student:\n";
                string fname, lname, dob;
                int id, sy, c;
                float gpa;
                char p;

                cout << "First Name: ";
                cin >> fname;
                cout << "Last Name: ";
                cin >> lname;
                cout << "Student ID: ";
                cin >> id;
                cout << "Date of Birth (YYYY): ";
                cin >> dob;
                cout << "GPA: ";
                cin >> gpa;
                while (gpa < 0 || gpa>4.4){
                	cout << "Invalid GPA, enter a number between 0 and 4.4.";
                	cin >> gpa;
                }
                cout << "Start Year: ";
                cin >> sy;
                cout << "Completed Credits: ";
                cin >> c;
                cout << "Program (B/M/P): ";
                cin >> p;
                while (p != 'B' && p != 'M' && p != 'P'){
                	cout << "Invalid program, enter B, M, or P.";
                	cin >> p;
                }
                student newStudent(fname, lname, id, dob, gpa, sy, c, p);
                studentArray[studentCount++] = newStudent;
                vector<student> students;
                students.push_back(newStudent);
                newStudent.Savetostudents(students, "student.txt");

                break;
            }
            case '2': {
                cout << "\nEnter information for a staff member:\n";
                string sfname, slname;
                int sid, doh;
                float b, stsalary;

                cout << "First Name: ";
                cin >> sfname;
                cout << "Last Name: ";
                cin >> slname;
                cout << "Staff ID: ";
                cin >> sid;
                cout << "Year of Hiring (YYYY): ";
                cin >> doh;
                cout << "Bonus Percentage: ";
                cin >> b;
                cout << "Salary: ";
                cin >> stsalary;

                staff newStaff(sfname, slname, sid, doh, b, stsalary);
                staffArray[staffCount++] = newStaff;
                vector<staff> staff;
                staff.push_back(newStaff);
                newStaff.Savetostaff(staff, "staff.txt");

                break;
            }
            case '3':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }

    } while (choice != '3');

    university.Highest_GPA(studentArray, studentCount);
    vector<student> undergrads = university.N_of_UnderGrad(studentArray, studentCount);
    cout << "\nNumber of undergraduate students: " << undergrads.size() << endl;
    university.Same_Hire_Year(staffArray, staffCount);

    return 0;
}
