#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
struct Date
{
	int day;
	int month;
	int year;
};
struct Student
{
	int No;
	string ID;
	string Firstname;
	string Lastname;
	bool gender;	// 1: male, 0: female
	Date birth;
	unsigned long SocialID;
};