#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
struct Scoreboard
{
	// 60 student - course 
	Student s[60]
	char fullname[200][60];
	float totalmark[60];
	float finalmark[60];
	float othermark[60];
	float midtermmark[60];
};
struct Course
{
	int id;
	char name[100];
	char teachername[100];
	int numofcredit;
	int maxStudent = 50; //by default
	char dayofweek[5];
	char section[5];

};