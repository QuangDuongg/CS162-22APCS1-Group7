#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
#include "Class.h"
struct Semester
{
	string semes; // Fall, Spring, Summer
	Semester* semesternext;
	int index_semester;
	Date start;
	Date end;
	Course* Coursehead = nullptr;
};
