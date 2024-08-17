#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include "student.h"
#include "staff.h"
#include "staff_student.h"

using namespace std;

student_staff::student_staff(){
	ReadStudentData("student.txt");
	ReadStaffData("staff.txt");
}

void student_staff::ReadStudentData(const string& filename) {
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string fname, lname, dob;
        int id, sy, c;
        float gpa;
        char p;

        while (inFile >> fname >> lname >> id >> dob >> gpa >> sy >> c >> p) {
            students.emplace_back(fname, lname, id, dob, gpa, sy, c, p);
        }

        inFile.close();
    } else {
        cerr << "Unable to open the file: " << filename << endl;
    }
}

void student_staff::ReadStaffData(const string& filename) {
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string fname, lname;
        int id, doh;
        float b, s;

        while (inFile >> fname >> lname >> id >> doh >> b >> s) {
            staffMembers.emplace_back(fname, lname, id, doh, b, s);
        }

        inFile.close();
    } else {
        cerr << "Unable to open the file: " << filename << endl;
    }
}


void student_staff::Highest_GPA(student* students, int size) {
    double GPA = -1.0;
    int Index = -1;

    for (int i = 0; i < size; i++) {
        if (GPA < students[i].getGPA()) {
            Index = i;
            GPA = students[i].getGPA();
        }
    }

    if (Index != -1) {
        cout << "\nHighest GPA:\n";
        students[Index].Print_Std_Info();
    } else {
        cout << "\nNo student data available.\n";
    }
}

vector<student> student_staff::N_of_UnderGrad(student* students, int size) {
    vector<student> undergrads(students, students + size);

    auto endIt = remove_if(undergrads.begin(), undergrads.end(),
                                [](const student& s) { return s.getProgram() != 'B'; });

    undergrads.erase(endIt, undergrads.end());

    return undergrads;
}


void student_staff::Same_Hire_Year(staff* staffMembers, int size) {
    set<int> uniqueYears;

    for (int i = 0; i < size; i++) {
        int yearHired = staffMembers[i].getDate();
        if (uniqueYears.count(yearHired) > 0) {
            continue;
        }

        uniqueYears.insert(yearHired);

        cout << "\nHired in year " << yearHired << ":\n";

        for (int j = 0; j < size; j++) {
            if (staffMembers[j].getDate() == yearHired) {
                staffMembers[j].Print_Stf_Info();
            }
        }
    }
}
