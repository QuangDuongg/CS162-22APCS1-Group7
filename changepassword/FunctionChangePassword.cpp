#include "FunctionChangePassword.h"

void updateFilePassword(password* pass, int size, ofstream& outp){
    outp << "Type of user,Name,Username,Password" << endl;
    for (int i = 0; i < size; i++){
        outp << pass[i].type << ",";
        outp << pass[i].name << ",";
        outp << pass[i].ID << ",";
        outp << pass[i].password << endl;
    }
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