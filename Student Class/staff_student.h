#ifndef STAFF_STUDENT_H_
#define STAFF_STUDENT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "staff.h"
#include "student.h"

using namespace std;

class student_staff {
private:
	vector<student> students;
	vector<staff> staffMembers;

	void ReadStudentData(const string& filename);
	void ReadStaffData(const string& filename);
public:
	student_staff();

	void Highest_GPA(student* students, int size);
	vector<student> N_of_UnderGrad(student* students, int size);
	void Same_Hire_Year(staff* staffArray, int size);

};



#endif
