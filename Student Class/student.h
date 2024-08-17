#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <fstream>
#include <vector>

using namespace std;


class student{
private:
	string sfname;
	string slname;
	int sid;
	string sbday;
	float GPA;
	int sstartyear;
	int completecredit;
	char program;

public:
	student();
	student(const string& fn, const string& ln, int id, string dob, float sgpa, int sy, int c, char p);

	string getFname() const;
	void setFname(const string& fn);
	string getLname() const;
	void setLname(const string& ln);
	int getSID() const;
	void setSID(int id);
	string getBday() const;
	void setBday(const string& dob);
	float getGPA() const;
	void setGPA(float sgpa);
	int getStartyear() const;
	void setStartyear(int sy);
	int getCredit() const;
	void setCredit(int c);
	char getProgram() const;
	void setProgram(char p);
	bool CompleteProgram() const;
	string StudentStatus(float sgpa) const;
	void Print_Std_Info() const;
	void Savetostudents(const vector<student>& students, const string& filename);
};



#endif
