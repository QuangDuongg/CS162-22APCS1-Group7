#include <iostream>
#include <string>
using namespace std;
struct Class {
	string classname;
	Student* stuhead;
	Class* classnext;
};
//Struct for Scoreboard
struct Scoreboard
{
	// 60 student - course 
	float totalmark;
	float finalmark;
	float othermark;
	float midtermmark;
};
//Struct for Course
struct Course
{
	string id;
	string name;
	string classname;
	string teachername;
	int numofcredit;
	int maxStudent = 50; //by default
	string dayofweek;
	string session;
	Course* next;

};
//Struct for Password
struct password{
    string type;
    string name;
    string ID;
    string password;
};
//Struct for Semester
struct Semester
{
	string semes; // Fall, Spring, Summer
	Semester* semesternext;
	int index_semester;
	Date start;
	Date end;
	Course* Coursehead = nullptr;
};
//Struct for Data
struct Date
{
	int day;
	int month;
	int year;
};
//Struct for Student
struct Student
{
	int No;
	string ID;
	string Firstname;
	string Lastname;
	bool gender;	// 1: male, 0: female
	Date birth;
	unsigned long SocialID;
	Student* stunext;
};
//Struct for SchoolYear
struct SchoolYear {
	string schoolyear; // 2022-2023
	Class* classhead;
	Semester* semesterhead;
};