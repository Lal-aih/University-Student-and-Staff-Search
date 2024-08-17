#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include <vector>

using namespace std;

class staff{
private:
	string efname;
	string elname;
	int eid;
	int hiredate;
	int bonus;
	int salary;
public:
	staff();
	staff(const string& fn, const string& ln, int id, int doh, float b, float s);

	string getFname() const;
	void setFname(const string& fn);
	string getLname() const;
	void setLname(const string& ln);
	int getEID() const;
	void setEID(int id);
	int getDate() const;
	void setDate(int doh);
	int getBonus() const;
	void setBonus(float b);
	int getSalary() const;
	void setSalary(float s);
	void Print_Stf_Info() const;
	float Calculate_Salary();
	void Savetostaff(const vector<staff>& staff, const string& filename);
};



#endif
