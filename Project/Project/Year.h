#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
#include "Class.h";

struct SchoolYear {
	string schoolyear; // 2022-2023
	Class* classhead;
	Semester* semesterhead;
};