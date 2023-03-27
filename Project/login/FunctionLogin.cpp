#include "FunctionLogin.h"

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


