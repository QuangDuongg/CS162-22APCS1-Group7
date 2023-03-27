//
//  Class.cpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 26/03/2023.
//

#include "Class.hpp"

void createClass(schoolyear& sy){
    sy.chead = new Class;
    Class* curclass = sy.chead;
    cout << "Input class names (0 to stop): " << endl;
    string tmp = "";
    getline(cin,tmp,'\n');
    while (tmp != "0")
    {
        curclass->classname = tmp;
        curclass->classnext = new Class;
        curclass = curclass->classnext;
        curclass->classnext = nullptr;
        getline(cin,tmp,'\n');
    }
    curclass = sy.chead;
    cout << endl;
    cout << "Please input the path to your the file containing information of students from each class respectively.\n";
    
    while (curclass->classnext)
    {
        cout << curclass->classname << " file address: ";
        string filename;
        getline(cin, filename, '\n');
        ifstream student;
        student.open(filename);
        curclass->stuhead = new Student;
        Student* curstudent = curclass->stuhead;
        
        if(student.is_open())
        {
            string line = "";
            while (getline(student, line))
            {
                stringstream stuinfo(line);
                string tempno;
                getline(stuinfo, tempno, ',');
                curstudent->no = stoi(tempno);
                
                getline(stuinfo, curstudent->stuID,',');
                getline(stuinfo, curstudent->stulname, ',');
                getline(stuinfo, curstudent->stufname, ',');
                
                string gender;
                getline(stuinfo, gender, ',');
                if (gender=="Nam") curstudent->gender = 1;
                if (gender=="Nữ") curstudent->gender = 0;
                
                string day;
                getline(stuinfo, day, '/');
                curstudent->stubirth.day = stoi(day);
                
                string month;
                getline(stuinfo, month, '/');
                curstudent->stubirth.month = stoi(month);
                
                string year;
                getline(stuinfo, year, ',');
                curstudent->stubirth.year = stoi(year);
                
                getline(stuinfo, curstudent->stupID, '\r');
                line = "";
                curstudent->stunext = new Student;
                curstudent = curstudent->stunext;
                curstudent->stunext = nullptr;
            }
        }
        else
            cout << "Cant open student file for class " << curclass->classname << endl;
        curclass = curclass->classnext;
    }
    ofstream fout;
    fout.open(sy.scyear+"_class.csv");
    saveClassToFile(sy, fout);
}

void saveClassToFile(schoolyear sy, ostream& fout){
    Class* curclass = sy.chead;
    while (curclass->classnext)
    {
        fout << curclass->classname << endl;
        Student* curstudent = curclass->stuhead;
        while (curstudent->stunext)
        {
            fout << curstudent->no << ',' << curstudent->stuID << ',' << curstudent->stulname << ',' << curstudent->stufname << ',';
            if (curstudent->gender==1) fout << "Nam,";
            else fout << "Nữ,";
            fout << curstudent->stubirth.day << '/' << curstudent->stubirth.month << '/' << curstudent->stubirth.year << ',';
            fout << curstudent->stupID << endl;
            curstudent = curstudent->stunext;
        }
        int end = 0;
        fout << end << endl;
        curclass = curclass->classnext;
    }
}

void readOldClassFile(schoolyear*& sy, istream& oldsy){
    string line ="";
    sy = new schoolyear;
    schoolyear* curyear = sy;
    while (getline(oldsy, line))
    {
        string sy1, sy2;
        stringstream year(line);
        getline(year, sy1, '-');
        getline(year, sy2,'\r');
        curyear->scyear = sy1+'_'+sy2;
        ifstream oldclass;
        oldclass.open(sy1+'_'+sy2+"_class.csv");
        
        if (oldclass.is_open())
        {
            curyear->chead = new Class;
            Class* curclass = curyear->chead;
            string subline = "";
            while (getline(oldclass,subline))
            {
                stringstream oldcl(subline);
                getline(oldcl, curclass->classname, '\r');
                curclass->stuhead = new Student;
                Student* curstudent = curclass->stuhead;
                
                string stuline ="";
                while (getline(oldclass,stuline))
                {
                    stringstream student(stuline);
                    string no;
                    getline(student, no, ',');
                    if (no!="0")
                    {
                        int stuno = stoi(no);
                        curstudent->no = stuno;
                    }
                    else break;
                    
                    getline(student, curstudent->stuID,',');
                    getline(student, curstudent->stulname, ',');
                    getline(student, curstudent->stufname, ',');
                    
                    string gender;
                    getline(student, gender, ',');
                    if (gender=="Nam") curstudent->gender = 1;
                    if (gender=="Nữ") curstudent->gender = 0;
                    
                    string day;
                    getline(student, day, '/');
                    curstudent->stubirth.day = stoi(day);
                    
                    string month;
                    getline(student, month, '/');
                    curstudent->stubirth.month = stoi(month);
                    
                    string year;
                    getline(student, year, ',');
                    curstudent->stubirth.year = stoi(year);
                    
                    getline(student, curstudent->stupID, '\r');
                    stuline = "";
                    curstudent->stunext = new Student;
                    curstudent = curstudent->stunext;
                    curstudent->stunext = nullptr;
                }
                       
                subline = "";
                curclass->classnext = new Class;
                curclass = curclass->classnext;
                curclass->classnext = nullptr;
            }
        }
        else{
            cout << "Cant open file. " << endl;
        }
        line = "";
        curyear->next = new schoolyear;
        curyear = curyear->next;
        curyear->next = nullptr;
    }
    
}
