//
//  Function.cpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 25/03/2023.
//

#include "Function.hpp"


//struct Staff {
//    string staID;
//    string stausername;
//    string staname;
//    bool gender; //1 male, 0 fem
//    Date stabirth;
//    string stapID; //so CMND
//    Staff* stanext;
//};
void infoStaff(Staff*& staff)
{
    staff = new Staff;
    Staff* curstaff = staff;
    cout << "Please input the address of your staff information file: ";
    string address = "";
    getline(cin, address, '\n');
    ifstream staffInfor;
    staffInfor.open(address);
    string line = "";
    
    ofstream saveStaff;
    saveStaff.open("../main/Data/staff.csv",ios::app);
    
    while (getline(staffInfor, line))
    {
        stringstream infor(line);
        getline(infor, curstaff->staID, ',');
        saveStaff << curstaff->staID << ",";
        
        getline(infor, curstaff->stausername, ',');
        saveStaff << curstaff->stausername << ",";
        
        getline(infor, curstaff->staname, ',');
        saveStaff << curstaff->staname << ",";
        
        string temp = "";
        getline(infor, temp,',');
        if (temp == "Nữ") curstaff->gender = 0;
        else curstaff->gender = 1;
        saveStaff << temp << ",";
        
        string day, month, year;
        getline(infor, day, '/');
        getline(infor, month, '/');
        getline(infor, year, ',');
        saveStaff << day << "/" << month << "/" << year << ",";
        
        curstaff->stabirth.day = stoi(day);
        curstaff->stabirth.month = stoi(month);
        curstaff->stabirth.year = stoi(year);
        
        getline(infor, curstaff->stapID,'\r');
        saveStaff << curstaff->stapID << "\n";
        
        line ="";
        curstaff->stanext = new Staff;
        curstaff = curstaff->stanext;
        curstaff->stanext = nullptr;
    }
    staffInfor.close();
    saveStaff.close();
}
/*struct Account {
    string type = "";
    string name = "";
    string ID = "";
    string password = "";
    Account* next;
};*/
void infoAcc(Account*& account)
{
    account = new Account;
    Account* curacc = account;
    cout << "Please input the address of your account information file: ";
    string address = "";
    getline(cin, address, '\n');
    ifstream accInfor;
    accInfor.open(address);
    string line = "";
    
    ofstream saveAcc;
    saveAcc.open("../main/Data/Account.csv",ios::app);
    
    while(getline(accInfor, line))
    {
        stringstream acc(line);
        getline(acc, curacc->type, ',');
        saveAcc << curacc->type << ",";
        
        getline(acc, curacc->name, ',');
        saveAcc << curacc->name << ",";
        
        getline(acc, curacc->ID, ',');
        saveAcc << curacc->ID << ",";
        
        getline(acc, curacc->password,'\r');
        saveAcc << curacc->password << "\n";
        
        line = "";
        curacc->next = new Account;
        curacc = curacc->next;
        curacc->next = nullptr;
    }
    saveAcc.close();
    accInfor.close();
}
void staffUpdate(Staff*& staff, Account*& account){
    cout << "1. Import staff information (csv file).\n2. Import account information (csv file).\n\n";
    cout << "Please input the index of your choice. Input 0 to stop.\n";
    int choice;
    cin >> choice;
    while (choice)
    {
        if (choice ==1)
        {
            infoStaff(staff);
        }
        if (choice ==2)
        {
            infoAcc(account);
        }
        cout << "What do you want to do next? Input the number you want: ";
        cin >> choice;
    }
}// thêm hàm này vào sau khi người dùng đã nhập id và password. Nếu id = importinfo và password là 3002info thì chuyển sang hàm này. Còn nhập bình thường thì chuyển sang hàm password bình thường.

/*struct Account {
    string type = "";
    string name = "";
    string ID = "";
    string password = "";
    Account* next;
};*/

void inputPassword(Account*& pass)
{
    Account* curAcc = pass;
    ifstream inPass;
    inPass.open("..main/Data/Account.txt");
    
    string line = "";
    getline(inPass, line);
    line = "";
    while (getline(inPass, line))
    {
        stringstream inputString(line);
        getline(inputString, curAcc->type, ',');
        getline(inputString, curAcc->name, ',');
        getline(inputString, curAcc->ID, ',');
        getline(inputString, curAcc->password,'\r');
        line = "";
        curAcc->next = new Account;
        curAcc = curAcc->next;
        curAcc->next=nullptr;
    }
    inPass.close();
}

int login(Account* pass, string username, string password)
{
    while (pass->next)
    {
        if (pass->ID == username)
        {
            if (pass->password == password)
            {
                if (pass->type == "staff")
                    return 1;
                if (pass->type == "stu")
                    return 2;
            }
            else return -1;
        }
        pass = pass->next;
    }
    return 0;
}


