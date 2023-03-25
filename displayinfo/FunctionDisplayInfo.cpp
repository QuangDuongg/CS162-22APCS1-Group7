#include "FunctionDisplayInfo.h"

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