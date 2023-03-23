#pragma once
#include "Year.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "Function.h"
#include "Class.h"

struct Class {
	string classname;
	Student* stuhead;
	Class* classnext;
};