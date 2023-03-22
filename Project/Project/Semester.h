#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
struct Semester
{
	Semester* next;
	string schoolyear;
	int index_semester;
	Date start;
	Date end;
	Course* Coursehead = nullptr;
};
