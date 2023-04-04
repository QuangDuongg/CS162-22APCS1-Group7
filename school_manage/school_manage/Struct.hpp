

#ifndef Struct_hpp
#define Struct_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
// #include <filesystem>
// #include <direct.h>
using namespace std;


struct Date {
    int day;
    int month;
    int year;
};
struct Staff {
    string staID;
    string stausername;
    string staname;
    bool gender; //1 male, 0 fem
    Date stabirth;
    string stapID; //so CMND
    Staff* stanext;
};
//Name Course, scoreboard of a student

struct Score
{
    float total;
    float final;
    float midterm;
    float other;
};
struct ScoreofStu
{
    Score CSmark;
    string CSName = ""; //Course name
    ScoreofStu* CSnext;
};

struct Student {
    int no;
    string stuID = "";
    string stufname = "";
    string stulname = "";
    bool gender; //1 male, 0 female
    Date stubirth;
    string stupID = ""; //so CMND
    Student* stunext;
    ScoreofStu* CShead = nullptr;
};

struct Class {
    string classname="";
    Student* stuhead = nullptr;
    Class* classnext;
};

struct Course {
    string courseID = "";
    string coursename = "";
    string clname;
    Student* stu = nullptr;
    string teach;
    int numofcredit;
    int maxStudent = 50; //default;
    string dayofweek = ""; //Mon-Tue-Wed-Thu-Fri-Sat
    string session = ""; //Input S1 (7h30), S2 (9H30), S3 (13H30); S4 (15H30)
    Course* counext;
};

struct Semester {
    string schyear = "";
    int semindex;
    Date start;
    Date end;
    Course* couhead = nullptr;
    Semester* semnext;
};

struct schoolyear {
    string scyear = "";
    Class* chead = nullptr;
    Semester* sem=nullptr;
    schoolyear* next;
};

struct Account {
    string type = "";
    string name = "";
    string ID = "";
    string password = "";
    Account* next;
};

#endif
