#include "staff.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


staff::staff()
	:efname(""), elname(""), eid(0), hiredate(0), bonus(0), salary(0){}

staff::staff(const string& fn, const string& ln, int id, int doh, float b, float s)
    :efname(fn), elname(ln), eid(id), hiredate(doh), bonus(b), salary(s){}

string staff::getFname() const{
	return efname;
}

void staff::setFname(const string& fn){
	efname=fn;
}

string staff::getLname() const{
	return elname;
}

void staff::setLname(const string& ln){
	elname=ln;
}

int staff::getEID() const{
	return eid;
}

void staff::setEID(int id){
	eid=id;
}

int staff::getDate() const{
	return hiredate;
}

void staff::setDate(int date){
	hiredate=date;
}

int staff::getBonus() const{
	return bonus;
}

void staff::setBonus(float b){
	bonus=b;
}

int staff::getSalary() const{
	return salary;
}

void staff::setSalary(float s){
	salary=s;
}

float staff::Calculate_Salary(){
	float new_salary = salary + salary*(bonus/100);
	return new_salary;
}


void staff::Savetostaff(const vector<staff>& staffVector, const string& filename) {
    ofstream outFile(filename, ios::app);

    if (outFile.is_open()) {
        for (const auto& s : staffVector) {
            outFile << "Name: " << s.getFname() << " " << s.getLname() << "\n";
            outFile << "Employee ID: " << s.getEID() << "\n";
            outFile << "Date of Hiring: " << s.getDate() << "\n";
            outFile << "Bonus: " << s.getBonus() << "\n";
            outFile << "Salary: " << s.getSalary() << "\n\n";
        }

        outFile.close();
        cout << "Staff information saved to " << filename << endl;
    } else {
        cerr << "Unable to open the file: " << filename << endl;
    }
}

void staff::Print_Stf_Info() const {
    cout << "Name: " << efname << " " << elname << endl;
    cout << "Employee ID: " << eid << endl;
    cout << "Hiring date: " << hiredate << endl;
    cout << "Bonus: " << bonus << "\n";
    cout << "Salary: " << salary << "\n\n";
}
