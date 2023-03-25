

#ifndef Struct_hpp
#define Struct_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Teacher{
    string teaID;
    string teaname;
    bool gender; //1 male, 0 fem
    Date teabirth;
    unsigned teapID; //so CMND
};

struct Student{
    int no;
    string stuID;
    string stufname;
    string stulname;
    bool gender; //1 male, 0 female
    Date stubirth;
    unsigned stupID; //so CMND
    Student* stunext;
};

struct Class{
    string classname;
    Student* stuhead = nullptr;
    Class* classnext;
};

struct Course{
    string courseID;
    string coursename;
    string clname;
    Student* stu = nullptr;
    Teacher teach;
    int numofcredit;
    int maxStudent =50; //default;
    string dayofweek; //Mon-Tue-Wed-Thu-Fri-Sat
    string session; //Input S1 (7h30), S2 (9H30), S3 (13H30); S4 (15H30)
    Course* counext;
};

struct Semester{
    int schyear;
    int semindex;
    Date start;
    Date end;
    Course* couhead = nullptr;
};

struct schoolyear{
    int scyear;
    Class* chead=nullptr;
    Semester sem[3];
};

struct Password{
    string type;
    string name;
    string ID;
    string password;
};

#endif /* Struct_hpp */
