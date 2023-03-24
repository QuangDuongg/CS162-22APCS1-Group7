#pragma once
#include "Function.h"

//Login
void inputPassword(password* pass, istream& inPass, int& size)
{
    size =0;
    string line = "";
    getline(inPass, line);
    line = "";
    while (getline(inPass, line))
    {
        stringstream inputString(line);
        getline(inputString, pass[size].type, ',');
        getline(inputString, pass[size].name, ',');
        getline(inputString, pass[size].ID, ',');
        getline(inputString, pass[size].password,'\r');
        line = "";
        ++size;
    }
}
void login(password* pass, int size)
{
    string username, userpass;
    cout << "Enter your username: " << endl;
    cin.ignore();
    getline(cin, username, '\n');
    cout << "Enter your password: " << endl;
    getline(cin, userpass, '\n');
    bool existID=0;
    for (int i=0; i<size; ++i)
    {
        if (pass[i].ID==username)
        {
            if (pass[i].password==userpass)
            {
                cout << "Successfully login" << endl;
                return;
            }
            else
            {
                cout << "Wrong password, try again" << endl;
                return;
            }
        }
    }
    if (existID==0)
    {
        cout << "This username does not exist" << endl;
        return;
    }
}
//Display Information
void readinInfoForStaff(Staff* staffinfo, int& size) {
	size = 0;
	ifstream fin;
	fin.open("Staffinfo.csv");
	if (fin.is_open()) {
		while(!fin.eof()){
			getline(fin, staffinfo[size].username, ',');
			getline(fin, staffinfo[size].ID, ',');
			getline(fin, staffinfo[size].Firstname, ',');
			getline(fin, staffinfo[size].Lastname, ',');
			fin >> staffinfo[size].gender;
			fin.ignore();
			fin >> staffinfo[size].birth.day;
			fin.ignore();
			fin >> staffinfo[size].birth.month;
			fin.ignore();
			fin>> staffinfo[size].birth.year;
			fin.ignore();
			getline(fin, staffinfo[size].email, ',');
			fin >> staffinfo[size].SocialID;
			fin.ignore(1000, '\n');
			++size;
		}
	}
}

void displayStaffInfo(Staff* staffinfo, int size, string username) {
	for (int i = 0; i < size; ++i) {
		if (username == staffinfo[i].username) {
			cout << "Welcome! User: " << staffinfo[i].username << endl;
			cout << "ID: " << staffinfo[i].ID << endl;
			cout << "First name: " << staffinfo[i].Firstname << "   " << "Last name: " << staffinfo[i].Lastname << endl;
			if (staffinfo[i].gender)
				cout << "Gender: male" << endl;
			else
				cout << "Gender: female" << endl;
			cout << "Date of birth: " << staffinfo[i].birth.day << "/" << staffinfo[i].birth.month << "/" << staffinfo[i].birth.year << endl;
			cout << "Email: " << staffinfo[i].email << endl;
			cout << "Social ID: " << staffinfo[i].SocialID << endl;
			cout << endl;
		}
	}
}

void readinInfoForStudent(Student* info, int& size) {
	size = 0;
	ifstream fin;
	fin.open("Studentinfo.csv");
	if (fin.is_open()) {
		while(!fin.eof()) {
			fin >> info[size].No;
			fin.ignore();
			getline(fin, info[size].ID, ',');
			getline(fin, info[size].Firstname, ',');
			getline(fin, info[size].Lastname, ',');
			fin >> info[size].gender;
			fin.ignore();
			fin >> info[size].birth.day;
			fin.ignore();
			fin >> info[size].birth.month;
			fin.ignore();
			fin >> info[size].birth.year;
			fin.ignore();
			fin >> info[size].SocialID;
			fin.ignore(1000, '\n');
			++size;
		}
	}
}

void displayStudentInfo(Student* info, int size, string username) {
	for (int i = 0; i < size; ++i) {
		if (username == info[i].ID) {
			cout << "Welcome! User: " << info[i].ID << endl;
			cout << "ID: " << info[i].ID << endl;
			cout << "First name: " << info[i].Firstname << "   " << "Last name: " << info[i].Lastname << endl;
			if (info[i].gender)
				cout << "Gender: male" << endl;
			else
				cout << "Gender: female" << endl;
			cout << "Date of birth: " << info[i].birth.day << "/" << info[i].birth.month << "/" << info[i].birth.year << endl;
			cout << "Social ID: " << info[i].SocialID << endl;
			cout << endl;
		}
	}
}

//Change Password
//void inputPassword(password* pass, istream& inPass, int& size);(1st Part of Function Login)
void updateFilePassword(password* pass, int size, ofstream& outp){
    outp << "Type of user,Name,Username,Password" << endl;
    for (int i = 0; i < size; i++){
        outp << pass[i].type << ",";
        outp << pass[i].name << ",";
        outp << pass[i].ID << ",";
        outp << pass[i].password << endl;
    }
}
bool checkPW(password *pass, int size, string recentPW, string username){
    for (int i = 0; i < size; i++){
        if (pass[i].ID == username){
            if (pass[i].password == recentPW) return true;
        }
    }
    return false;
    return 0;
}
void updatePassword(password* pass, int size, string newPW, string username){
    for (int i = 0; i < size; i++){
        if (pass[i].ID == username){
            pass[i].password = newPW;
            return;
        }
    }
}
void CheckAndCreat(password* pass, int size, string username, ofstream& outp){
    string recentPW;
    cout << "Please enter the password recently." << endl;
    getline(cin, recentPW, '\n');
    while (checkPW(pass, size, recentPW, username) == 0){
        cout << "Wrong password, try again!" << endl;
        getline(cin, recentPW, '\n');
    }
    cout << "Please enter a new password!" << endl;
    string newPW;
    getline(cin, newPW, '\n');
    while (newPW == recentPW){
        cout << "Password used, please enter another password!" << endl;
        getline(cin, newPW, '\n');
    }
    updatePassword(pass, size, newPW, username);
    updateFilePassword(pass, size, outp);
    cout << "Successfully change password!" << endl;
}