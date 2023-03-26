#include "MyFunction.h"

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
    cout << "Please enter the password recently:" << endl;
    getline(cin, recentPW, '\n');
    while (checkPW(pass, size, recentPW, username) == 0){
        cout << "Wrong password, try again!" << endl;
        getline(cin, recentPW, '\n');
    }
    cout << "Please enter a new password:" << endl;
    string newPW;
    getline(cin, newPW, '\n');
    while (newPW == recentPW){
        cout << "Password used, please enter another password:" << endl;
        getline(cin, newPW, '\n');
    }
    updatePassword(pass, size, newPW, username);
    // outp.open("Password.csv");
    updateFilePassword(pass, size, outp);
    // outp.close();
    cout << "Successfully change password!" << endl;
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
bool isExistID(string username, password* pass, int size){
    for (int i = 0; i < size; i++){
        if (pass[i].ID == username) return true;
    }
    return false;
}
void login(password* pass, int size, string& username, int& choice)
{
    string userpass;
    cin.ignore();
    cout << "Enter your username: " << endl;
    getline(cin, username, '\n');
    while(isExistID(username, pass, size) == 0){
        cout << "This username does not exist, try again" << endl;
        cout << "Enter your username: " << endl;
        cin.ignore();
    }
    cout << "Enter your password: " << endl;
    getline(cin, userpass, '\n');
    while (choice != 0)
    {
        for (int i = 0; i < size; ++i)
        {
            if (pass[i].ID == username){
                if (pass[i].password == userpass)
                {
                    cout << "Successfully login" << endl;
                    return;
                }
            }
        }
        cout << "Wrong password, try again" << endl;
        cout << "If you want to stop enter password, press 0 else enter 1" << endl;
        cin >> choice;
        if (choice == 0){
            choice = 0;
            break;
        }
        cout << "Enter your password: " << endl;
        cin.ignore();
        getline(cin, userpass, '\n');
    }
}


