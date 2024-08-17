#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

student::student()
	:sfname(""), slname(""), sid(0), sbday(""), GPA(0.0), sstartyear(0), completecredit(0), program('\0'){}

student::student(const string& fn, const string& ln, int id, string dob, float sgpa, int sy, int c, char p)
	:sfname(fn), slname(ln), sid(id), sbday(dob), GPA(sgpa), sstartyear(sy), completecredit(c), program(p){}

string student::getFname() const{
	return sfname;
}

void student::setFname(const string& fn){
	sfname=fn;
}

string student::getLname() const{
	return slname;
}

void student::setLname(const string& ln){
	slname=ln;
}

int student::getSID() const{
	return sid;
}

void student::setSID(int id){
	sid=id;
}

string student::getBday() const{
	return sbday;
}

void student::setBday(const string& dob){
	sbday=dob;
}

float student::getGPA() const{
	return GPA;
}

void student::setGPA(float sgpa){
	GPA=sgpa;
}

int student::getStartyear() const{
	return sstartyear;
}

void student::setStartyear(int sy){
	sstartyear=sy;
}

int student::getCredit() const{
	return completecredit;
}

void student::setCredit(int c){
	completecredit=c;
}

char student::getProgram() const{
	return program;
}

void student::setProgram(char p){
	program=p;
}

bool student::CompleteProgram() const{
    int requiredCredit;
    switch (program) {
        case 'B':
            requiredCredit = 140;
            break;
        case 'M':
            requiredCredit = 16;
            break;
        case 'P':
            requiredCredit = 12;
            break;
        default:
            requiredCredit = 0;
            break;
    }
    return completecredit >= requiredCredit;
}

string student::StudentStatus(float sgpa) const{
	if (sgpa >=3.5){
		return "A+";
	} else if (sgpa >= 3 && sgpa < 3.5){
		return "A";
	} else if (sgpa >= 2.5 && sgpa < 3){
		return "B";
	} else if (sgpa >= 2 && sgpa < 2.5){
		return "C";
	} else
		return "D";
}

void student::Savetostudents(const vector<student>& studentsVector, const string& filename) {
    ofstream outFile(filename, ios::app);

    if (outFile.is_open()) {
        for (const auto& s : studentsVector) {
            outFile << "Name: " << s.getFname() << " " << s.getLname() << "\n";
            outFile << "Student ID: " << s.getSID() << "\n";
            outFile << "Date of Birth: " << s.getBday() << "\n";
            outFile << "GPA: " << s.getGPA() << "\n";
            outFile << "Start Year: " << s.getStartyear() << "\n";
            outFile << "Completed Credits: " << s.getCredit() << "\n";
            outFile << "Program: " << s.getProgram() << "\n";
            outFile << "Program Completion: " << (s.CompleteProgram() ? "Yes" : "No") << "\n";
            outFile << "Student Status: " << s.StudentStatus(s.getGPA()) << "\n\n";
        }

        outFile.close();
        cout << "Student information saved to " << filename << endl;
    } else {
        cerr << "Unable to open the file: " << filename << endl;
    }
}

void student::Print_Std_Info() const {
    cout << "Name: " << sfname << " " << slname << endl;
    cout << "Student ID: " << sid << endl;
    cout << "Date of Birth: " << sbday << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Start Year: " << sstartyear << endl;
    cout << "Completed Credits: " << completecredit << endl;
    cout << "Program: " << program << endl;
    cout << "Program Completion: " << (CompleteProgram() ? "Yes" : "No") << endl;
    cout << "Student Status: " << StudentStatus(GPA) << endl;
}
