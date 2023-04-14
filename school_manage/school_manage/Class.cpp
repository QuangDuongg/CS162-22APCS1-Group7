//
//  Class.cpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 26/03/2023.
//

#include "Class.hpp"

void update1StuClass(schoolyear*& sy)
{//sy o day la linked list
    string classname = "";
    cout << "Which class you want to change?";
    getline(cin, classname, '\n');
    
    while (classname != "0"){
        schoolyear* tmpsy = sy;
        Class* tmpclass =0;
        bool check = 0;
        while (tmpsy->next)
        {
            tmpclass = tmpsy->chead;
            while (tmpclass->classnext)
            {
                if (tmpclass->classname==classname) {
                    check = 1;
                    break;
                }
                else tmpclass = tmpclass->classnext;
            }
            if (check==1) break;
            else tmpsy = tmpsy->next;
        }
        
        int no;
        cout << "Input student No. you want to change: ";
        cin >> no;
        while (no!=0)
        {
            Student* curstudent = tmpclass->stuhead;
            for (int i=1; i<no; ++i)
                curstudent = curstudent->stunext;
            curstudent->no = no;
            cout << "Student ID: ";
            getline(cin,curstudent->stuID,'\n');
            
            cout << "Student's last and middle name: ";
            getline(cin,curstudent->stulname,'\n');
            
            cout << "Student's first name: ";
            getline(cin,curstudent->stufname,'\n');
            
            string gender = "";
            cout << "Student gender: ";
            getline(cin, gender, '\n');
            if (gender=="Nam" or gender=="1") curstudent->gender = 1;
            else curstudent->gender = 0;
            
            cout << "Student birth day, month and year respectively: ";
            cin >> curstudent->stubirth.day >> curstudent->stubirth.month >> curstudent->stubirth.year;
            
            cout << "Student's social personal ID: ";
            getline(cin, curstudent->stuID, '\n');
            
            cout << "Input student No. you want to change (0-stop): ";
            cin >> no;
        }
        ofstream fout;
        fout.open("..main/Data/SchoolYear/"+tmpsy->scyear+"/class/"+tmpclass->classname+".csv");
        if (fout.is_open()){
            fout << tmpclass->classname << endl;
            Student* curstudent = tmpclass->stuhead;
            while (curstudent->stunext)
            {
                fout << curstudent->no << ',' << curstudent->stuID << ',' << curstudent->stulname << ',' << curstudent->stufname << ',';
                if (curstudent->gender==1) fout << "Nam,";
                else fout << "Nữ,";
                fout << curstudent->stubirth.day << '/' << curstudent->stubirth.month << '/' << curstudent->stubirth.year << ',';
                fout << curstudent->stupID;
                curstudent = curstudent->stunext;
            }}
        else cout << "Cant open file " << "..main/Data/SchoolYear/"+tmpsy->scyear+"/class/"+tmpclass->classname+".csv" << endl;
        fout.close();
        cout << "Which class you want to change? (0-stop) ";
        getline(cin, classname, '\n');
    }
    
}
int checkDigit(string data)
{ // 2 là vừa chữ vừa số, 0 là toàn chữ, 1 là toàn số
    long n = data.length();
    int letter = 0, number = 0;
    for (int i=0; i<n; ++i)
    {
        if (isdigit(char(data[i]))==1) ++number;
        else ++letter;
    }
    if (number == n) return 1;
    if (letter == n) return 0;
    return 2;
}
bool existDataStuCourseClass(istream& file, string input, int linenum) //input la cai stuid a nha
{
    string line = "";
    for (int i=1; i<linenum; ++i)
    {
        getline(file, line);
        stringstream data(line);
        string throwaway = "";
        getline(data, throwaway, ',');
        string id = "";
        getline(data, id, ',');
        if (id == input) return 1;
        line = "";
    }
    return 0;
}
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
            int countline = 1;
            while (getline(student, line))
            {
                if (existDataStuCourseClass(student, line, countline)==0){
                    stringstream stuinfo(line);
                    string tempno;
                    getline(stuinfo, tempno, ',');
                    if (checkDigit(tempno)==1)
                        curstudent->no = stoi(tempno);
                    else {
                        curstudent->no = 0;
                        cout << "Student no of line " << countline << " is not valid.\n";
                        
                    }
                    
                    getline(stuinfo, curstudent->stuID,',');
                    if (checkDigit(curstudent->stuID)!=1){
                        curstudent->stuID = "";
                        cout << "Student ID of line " << countline << "is not valid.\n";
                    }
                    
                    getline(stuinfo, curstudent->stulname, ',');
                    if (checkDigit(curstudent->stulname)!=0)
                    {
                        curstudent->stulname = "";
                        cout << "Student's last name of line " << countline << "is not valid.\n";
                    }
                    
                    getline(stuinfo, curstudent->stufname, ',');
                    if (checkDigit(curstudent->stufname)!=0)
                    {
                        curstudent->stufname = "";
                        cout << "Student's first name of line " << countline << "is not valid.\n";
                    }
                    
                    string gender;
                    getline(stuinfo, gender, ',');
                    
                    if (gender=="Nam" or gender =="1") curstudent->gender = 1;
                    else if (gender=="Nữ" or gender=="0") curstudent->gender = 0;
                    else {
                        curstudent->gender = 0;
                        cout << "Student gender name of line " << countline << "is not valid.\n";
                    }
                    
                    string day;
                    getline(stuinfo, day, '/');
                    if (stoi(day))
                        curstudent->stubirth.day = stoi(day);
                    else{
                        curstudent->stubirth.day = 0;
                        cout << "Student birth day of line " << countline << "is not valid.\n";
                    }
                    
                    string month;
                    getline(stuinfo, month, '/');
                    if (stoi(month)) curstudent->stubirth.month = stoi(month);
                    else{
                        curstudent->stubirth.month = 0;
                        cout << "Student birth month of line " << countline << "is not valid.\n";
                    }
                    
                    string year;
                    getline(stuinfo, year, ',');
                    if (stoi(year)) curstudent->stubirth.year = stoi(year);
                    else {
                        curstudent->stubirth.year = 0;
                        cout << "Student birth year of line " << countline << "is not valid.\n";
                    }
                    
                    getline(stuinfo, curstudent->stupID, '\r');
                    if (checkDigit(curstudent->stupID)!=1) {
                        curstudent->stupID = "";
                        cout << "Student social ID of line " << countline << "is not valid.\n";
                    }
                }
                else cout << "This data of line " << countline << "is repeated.\n";
                line = "";
                ++countline;
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
            fout << curstudent->stupID << "\n";
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

//cái read old class file là làm ngay từ đầu á nên là tới khi view sẽ có sẵn student ròi khum cần đọc file lại
void viewStudentinClass(schoolyear* sy)
{
    schoolyear* viewsy = 0;
    Class* viewclass = 0;
    Student* viewstu= 0;
    string classname;
    cout << "Enter the class you want to view: ";
    getline(cin, classname, '\n');
    
    bool exist = 0;
    while (classname!="0")
    {
        viewsy = sy;
        while (viewsy->next)
        {
            viewclass = viewsy->chead;
            while (viewclass->classnext)
            {
                viewstu = viewclass->stuhead;
                if (viewclass->classname == classname)
                {
                    exist = 1;
                    while (viewstu->stunext)
                    {
                        cout << viewstu->no << ", ";
                        cout << viewstu->stuID << ", ";
                        cout << viewstu->stulname << " " << viewstu->stufname << ", ";
                        
                        if (viewstu->gender==1) cout << "Nam, ";
                        else cout << "Nữ, ";
                        
                        cout << viewstu->stubirth.day << "/" << viewstu->stubirth.month << "/" << viewstu->stubirth.year << ", ";
                        cout << viewstu->stupID << "\n";
                        viewstu = viewstu->stunext;
                    }
                    break;
                }
                else viewclass = viewclass->classnext;
            }
            if (exist ==1) break;
            else viewsy = viewsy->next;
        }
        if (exist==0) cout << "This class has not been added to our data.\n";
        cout << "If you want to view the students of another class, please enter the name of that class.\nIf you do not want to continue, please enter 0 to stop.\n";
        cin.ignore();
        getline(cin, classname, '\n');
    }
}
