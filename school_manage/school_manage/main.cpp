#include "Class.hpp"
#include "Semester.hpp"
int main() {
//    schoolyear sy;
//    sy.scyear = "2022_2023";
//    createClass(sy);
    schoolyear* sy=0;
    ifstream inp;
    inp.open("data/schoolyear/schoolyear.txt");
    
    sy = new schoolyear;
    schoolyear* curyear = sy;
    int count=0;
    if (inp.is_open())
    {
        string year = "";
        while (getline(inp,year))
        {
            stringstream yearline(year);
            getline(yearline, curyear->scyear, '\r');
            curyear->next = new schoolyear;
            curyear = curyear->next;
            curyear->next = nullptr;
            year = "";
            ++count;
        }
    }
    else cout << "Cant open file." << endl;
    curyear = sy;
    
    if (curyear->next->next!=nullptr)
    { while (curyear->next->next)
        curyear = curyear->next;}
    cout << curyear->scyear << endl;
    createSemester(curyear);
    inp.close();
//    readOldClassFile(sy, inp);
//    schoolyear* curyear = sy;
//    while (curyear->next)
//    {
//        cout << curyear->scyear << endl;
//        Class* curclass = curyear->chead;
//        while (curclass->classnext)
//        {
//            cout << curclass->classname << endl;
//            Student* curstu = curclass->stuhead;
//            while (curstu->stunext)
//            {
//                cout << curstu->no << "," << curstu->stuID << "," << curstu->stulname << "," << curstu->stufname << "," << curstu->gender << "," << curstu->stubirth.day << "/" << curstu->stubirth.month << "/" << curstu->stubirth.year << "," << curstu->stupID << endl;
//                curstu = curstu->stunext;
//            }
//            curclass = curclass->classnext;
//        }
//        curyear = curyear->next;
//    }
////
//        int choice;
//        cout << "MENU" << endl;
//        cout << "Press 1 to login." << endl;
//        cin >> choice;
//
//        ifstream inp;
//        inp.open("Password.csv");
//        Password pass[200];
//        int size;
//        inputPassword(pass, inp, size);
//        if (choice==1)
//            login(pass, size);
//        inp.close();
//        return 0;
    
    
    return 0;
}
