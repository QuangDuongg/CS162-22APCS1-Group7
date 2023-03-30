//
//  Class.cpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 26/03/2023.
//

#include "Class.hpp"
bool existClass(schoolyear* sy, string classname)
{
    while (sy->next)
    {
        while (sy->chead)
        {
            if (sy->chead->classname == classname)
                return 1;
            sy->chead = sy->chead->classnext;
        }
        sy = sy->next;
    }
    return 0;
}

void createClass(schoolyear*& sy){
    ofstream classinp;
    string classadress = "data/schoolyear/";
    schoolyear* tmpyear = sy;
    Class* latestClass = 0;
    while (tmpyear->next)
        tmpyear = tmpyear->next;
    
    classadress += tmpyear->scyear + "/class.txt";
    classinp.open(classadress,ios::app);
    
    Class* curclass = tmpyear->chead;
    while (curclass->classnext)
        curclass = curclass->classnext;
    latestClass = curclass;
    
    cout << "Input class names (0 to stop): " << endl;
    string tmp = "";
    getline(cin,tmp,'\n');
    while (tmp != "0")
    {
        if (existClass(sy, tmp)==0){
            if (classinp.is_open()){
                classinp << tmp << "\n";}
            else cout << "Cant open to save classes.\n";
            curclass->classname = tmp;
            curclass->classnext = new Class;
            curclass = curclass->classnext;
            curclass->classnext = nullptr;}
        else cout << "This class has been input before. Please input again.\n";
        getline(cin,tmp,'\n');
    }
    curclass = latestClass;
    cout << endl;
    cout << "Please input the path to your the file containing information of students from each class respectively.\n";
    classinp.close();
    
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
        student.close();
    }
    saveClassToFile(tmpyear);
}

void saveClassToFile(schoolyear* sy){
   
    Class* curclass = sy->chead;
    while (curclass->classnext)
    {
        string address = "data/schoolyear/"+ sy->scyear+"/class/"+curclass->classname+".csv";
        ofstream fout;
        fout.open(address);
        fout << curclass->classname << endl;
        Student* curstudent = curclass->stuhead;
        while (curstudent->stunext)
        {
            fout << curstudent->no << ',' << curstudent->stuID << ',' << curstudent->stulname << ',' << curstudent->stufname << ',';
            if (curstudent->gender==1) fout << "Nam,";
            else fout << "Nữ,";
            fout << curstudent->stubirth.day << '/' << curstudent->stubirth.month << '/' << curstudent->stubirth.year << ',';
            fout << curstudent->stupID;
            curstudent = curstudent->stunext;
        }
        fout.close();
        curclass = curclass->classnext;
    }
}

void readOldClassFile(schoolyear*& sy, istream& oldsy){
    string line ="";
    sy = new schoolyear;
    sy->chead = new Class;
    Class* curclass = sy->chead;
    schoolyear* curyear = sy;
    while (!oldsy.eof())
    {
        oldsy >> curyear->scyear;
        curyear->next = new schoolyear;
        curyear = curyear->next;
        curyear->next = nullptr;
    }
    
    curyear = sy;
    while (curyear->next)
    {
        string address = "data/schoolyear/" + curyear->scyear + "/class.txt";
        ifstream oldclass;
        oldclass.open(address);
        if (oldclass.is_open()){
            while (!oldclass.eof())
            {
                oldclass >> curclass->classname;
                curclass->classnext = new Class;
                curclass = curclass->classnext;
                curclass->classnext = nullptr;
            }
        }
        else cout << "Cant open file " << address << endl;
        oldclass.close();
        curyear = curyear->next;
    }
    
    curyear = sy;
    curclass = sy->chead;
    while (curyear->next)
    {
        while (curclass->classnext){
            string address = "data/schoolyear/"+ curyear->scyear+"/class/"+curclass->classname+".csv";
            ifstream oldclass;
            oldclass.open(address);
            
            if (oldclass.is_open())
            {
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
            oldclass.close();
            curclass = curclass->classnext;
        }
        curyear = curyear->next;
    }
}
