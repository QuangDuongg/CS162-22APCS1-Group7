#pragma once
#include "Function.h"
void AddACourseToSemester(Semester& s)
{
	Course* c = s.Coursehead;
	if (!c)
	{
		c = new Course;
		cout << "Course's id:";
		getline(cin, c->id);
		cout << "Course's name: ";
		getline(cin, c->name);
		cout << "Class's name: ";
		getline(cin, c->classname);
		cout << "Teacher's name: ";
		getline(cin, c->teachername);
		cout << "Number of credits: ";
		cin >> c->numofcredit;
		cout << "Max student: ";
		cin >> c->maxStudent;
		cout << "Day of the week: ";
		getline(cin, c->dayofweek);
		cout << "Session: ";
		getline(cin, c->session);
		c->next = nullptr;
	}
	else
	{
		while (c->next)
			c = c->next;
		c->next = new Course;
		c = c->next;
		cout << "Course's id:";
		getline(cin, c->id);
		cout << "Course's name: ";
		getline(cin, c->name);
		cout << "Class's name: ";
		getline(cin, c->classname);
		cout << "Teacher's name: ";
		getline(cin, c->teachername);
		cout << "Number of credits: ";
		cin >> c->numofcredit;
		cout << "Max student: ";
		cin >> c->maxStudent;
		cout << "Day of the week: ";
		getline(cin, c->dayofweek);
		cout << "Session: ";
		getline(cin, c->session);
		c->next = nullptr;
	}
}