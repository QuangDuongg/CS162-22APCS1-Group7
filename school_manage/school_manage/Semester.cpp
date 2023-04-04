//
//  Semester.cpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 26/03/2023.
//

#include "Semester.hpp"


//khi mở app lên thì sẽ đọc một lượt hết các file đã lưu để có dữ liệu cũ nên mặc định ở đây đã có dữ liệu schoolyear mới nhất rồi nên không dò lại nữa, sy ở đây là pointer chỉ đến schoolyear mới nhất

void createSemester(schoolyear*& sy){
    fstream semester;
    semester.open("data/schoolyear/semester.txt",ios::in);
    
    string currentyear = sy->scyear;
    string yearline = "";
    string tmpyear;
    stringstream findyear;
    bool check=0;
    Semester* nowsem = 0;
    while (getline(semester, yearline))
    {
        tmpyear = "";
        stringstream findyear(yearline);
        getline(findyear, tmpyear, ',');
        cout << "Start: ";
        cout << yearline << " ";
        cout << tmpyear << endl;
        if (tmpyear==currentyear)
        {
            check=1;
            break;
        }
        else yearline = "";
    }
    cout << check << endl;
    if (check==1)
    {
        stringstream findyear(yearline);
        sy->sem = new Semester;
        Semester* cursem = sy->sem;
        cursem->schyear = tmpyear;
        string index;
        string throwaway;
        getline(findyear,throwaway,',');
        getline(findyear,index , ',');
        int semno = stoi(index);
        cursem->semindex = semno;
        cout << cursem ->semindex << endl;
        string sday, smonth, syear;
        getline(findyear,sday,'/');
        getline(findyear, smonth, '/');
        getline(findyear, syear, ',');
        
        cursem->start.day = stoi(sday);
        cursem->start.month = stoi(smonth);
        cursem->start.year = stoi(syear);
        
        string eday, emonth, eyear;
        getline(findyear,eday,'/');
        getline(findyear, emonth, '/');
        getline(findyear, eyear, '\r');
        
        cursem->end.day = stoi(eday);
        cursem->end.month = stoi(emonth);
        cursem->end.year = stoi(eyear);
        yearline = "";
        cursem->semnext = 0;
        while (getline(semester,yearline))
        {
            stringstream findyear(yearline);
            cursem->semnext = new Semester;
            cursem = cursem->semnext;
            cursem->semnext = nullptr;
            cursem->schyear = tmpyear;
            
            string bin;
            getline(findyear,bin,',');
            
            string index;
            getline(findyear,index , ',');
            int semno = stoi(index);
            cursem->semindex = semno;
            
            string sday, smonth, syear;
            getline(findyear,sday,'/');
            getline(findyear, smonth, '/');
            getline(findyear, syear, ',');
            
            cursem->start.day = stoi(sday);
            cursem->start.month = stoi(smonth);
            cursem->start.year = stoi(syear);
            
            string eday, emonth, eyear;
            getline(findyear,eday,'/');
            getline(findyear, emonth, '/');
            getline(findyear, eyear, '\r');
            
            cursem->end.day = stoi(eday);
            cursem->end.month = stoi(emonth);
            cursem->end.year = stoi(eyear);
            yearline = "";
        }
        nowsem = cursem;
    }
    else
    {
        sy->sem = new Semester;
        Semester* cursem = sy->sem;
        cursem->semindex =0;
        cursem->semnext = nullptr;
        nowsem = cursem;
    }
    
    semester.close();
    semester.open("data/schoolyear/semester.txt",ios::out|ios::app);
    if (semester.is_open()){
        if (nowsem->semindex==3) cout << "You have reached semester 3. Please create a new school year before create a new semester.\n";
        else{
            
            int index=1;
            if (!nowsem) index=1;
            else index = nowsem->semindex+1;
            cout << "You are creating semester " << nowsem->semindex+1 << "." << endl;
            nowsem->semnext = new Semester;
            nowsem = nowsem->semnext;
            nowsem->semnext = nullptr;
            cout << "The new semester is in school year ";
            nowsem->schyear = sy->scyear;
            cout << nowsem->schyear << endl;
            semester << nowsem->schyear << ',';
            nowsem->semindex = index;
            
        //    string address = "data/schoolyear/" + nowsem->schyear + "/" + to_string(nowsem->semindex);
        //        cout << address << '\n';
        //        if(mkdir(address.c_str()) == -1)
        //            cerr << "Error : " << strerror(errno) << '\n';
        //        else
        //            cout << "Semester Created!" << '\n';

            cout << "The new semester is semester " << nowsem->semindex << endl;
            semester << nowsem->semindex << ',';
            cout << "The start date of this semester is (dd/mm/yyyy): ";
            string start ="";
            getline(cin, start, '\n');
            
            string sday, smonth, syear;
            stringstream startdate(start);
            getline(startdate, sday, '/');
            getline(startdate, smonth, '/');
            getline(startdate, syear,'\n');
            
            nowsem->start.day = stoi(sday);
            nowsem->start.month = stoi(smonth);
            nowsem->start.year = stoi(syear);
            
            semester << nowsem->start.day << '/' << nowsem->start.month << '/' << nowsem->start.year << ',';
            
            cout << "The end date of this semester is (dd/mm/yyyy): ";
            string end ="";
            getline(cin, end,'\n');
            
            string eday, emonth, eyear;
            stringstream enddate(end);
            getline(enddate, eday, '/');
            getline(enddate, emonth, '/');
            getline(enddate, eyear);
            
            int enday = stoi(eday), enmonth = stoi(emonth), enyear = stoi(eyear);
            nowsem->end.day = enday;
            nowsem->end.month = enmonth;
            nowsem->end.year = enyear;
            
            semester << nowsem->end.day << '/' << nowsem->end.month << '/' << nowsem->end.year << "\n";
        }}
    else cout << "error" << endl;
    semester.close();
}


