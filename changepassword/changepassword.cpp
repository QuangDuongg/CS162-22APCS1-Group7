#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct password{
    string type;
    string name;
    string ID;
    string password;
};
void inputPassword(password* pass, istream& inPass, int& size);
bool checkPW(password *pass, int size, string recentPW, string username);
void updatePassword(password* pass, int size, string newPW, string username);
void CheckAndCreat(password* pass, int size, string username);
int main(){
    ifstream inp;
    inp.open("Password.csv");
    cout << "MENU" << endl;
    cout << "Press 3 to change password." << endl;
    int choice, size;
    cin >> choice;
    cin.ignore(100, '\n');
    string username;
    cout << "Enter the username(cai nay do minh da dang nhap vao nen se co bien nho username nhe!)" << endl;
    getline(cin, username, '\n');
    
    password pass[200];
    inputPassword(pass, inp, size);
    cout << size << ' ';
    if (choice == 3){
        CheckAndCreat(pass, size, username);
    }
    return 0;
}
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
bool checkPW(password *pass, int size, string recentPW, string username){
    for (int i = 0; i < size; i++){
        if (pass[i].ID == username){
            if (pass[i].password == recentPW) return true;
            else false;
        }
    }
}
void updatePassword(password* pass, int size, string newPW, string username){
    for (int i = 0; i < size; i++){
        if (pass[i].ID == username){
            pass[i].password = newPW;
            return;
        }
    }
}
void CheckAndCreat(password* pass, int size, string username){
    string recentPW;
        cout << "Please enter the password recently." << endl;
        getline(cin, recentPW, '\n');
        cin.ignore(100, '\n');
        cout << checkPW(pass, size, recentPW, username);
        while (checkPW(pass, size, recentPW, username) == 0){
            cout << checkPW(pass, size, recentPW, username);
            cout << "Wrong password, try again!" << endl;
            getline(cin, recentPW, '\n');
            cin.ignore(100, '\n');
        }
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
        cout << "Successfully change password!" << endl;
}