#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Staff {
	string username;
	string ID;
	string Firstname;
	string Lastname;
	bool gender;	// 1: male, 0: female
	Date birth;
	string email;
	unsigned long SocialID;
};

struct Student {
	int No;
	string ID;
	string Firstname;
	string Lastname;
	bool gender;	// 1: male, 0: female
	Date birth;
	unsigned long SocialID;
};

struct test {
	int n;
	string name;
};

void readinInfoForStaff(Staff* staffinfo, int& size);
void displayStaffInfo(Staff* staffinfo, int size,string username);
void readinInfoForStudent(Student* info, int& size);
void displayStudentInfo(Student* info, int size, string username);
