#include <string>
#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;

struct password {
    string type;
    string name;
    string ID;
    string password;
};

void inputPassword(password* pass, istream& inPass, int& size);
void login(password* pass, int size, int &index);
void viewinformation(password * pass, int index);
void changepassword(password* pass, int index);
int main()
{
    int choice = -1;
    ifstream inp;
    inp.open("Password.txt");
    password pass[200];
    int size;
    inputPassword(pass, inp, size);
    inp.close();
    while (choice != 0)
    {
        cout << "MENU" << endl;
        cout << "Press 1 to login." << endl;
        cout << "Press 2 if you forget the password or user name" << endl;
        cout << "Press 0 to extit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int index;
                login(pass, size,index);
                int sub_choice = -1;
                while (sub_choice != 0)
                {
                    cout << "MENU" << endl;
                    cout << "Press 1 to change password." << endl;
                    cout << "Press 2 to view personal information" << endl;
                    cout << "Press 0 to back" << endl;
                    cin >> sub_choice;
                    switch (sub_choice)
                    {
                    case 1:
                    {
                        int tmp;
                        changepassword(pass, index);
                        cout << "Enter 0 to back";
                        cin >> tmp;
                        if (tmp == 0)break;
                    }
                    case 2: 
                    {
                        int tmp;
                        viewinformation(pass, index);
                        cout << "\nEnter 0 to back";
                        cin >> tmp;
                        if (tmp == 0)break;

                    }
                    case 0: break;
                    }
                }
            }
            case 2:break;
            case 0: break;
            default: cout << "Invalid option. Please choose again" << endl; break;
        }
    }
    return 0;
}
void inputPassword(password* pass, istream& inPass, int& size)
{
    size = 0;
    string line = "";
    getline(inPass, line);
    line = "";
    while (getline(inPass, line))
    {
        stringstream inputString(line);
        getline(inputString, pass[size].type, ',');
        getline(inputString, pass[size].name, ',');
        getline(inputString, pass[size].ID, ',');
        getline(inputString, pass[size].password, '\r');
        line = "";
        ++size;
    }
}

void login(password* pass, int size, int & index)
{
    int sub_choice = -1;
    while (sub_choice != 0)
    {
        string username, userpass;
        cout << "Enter your username: " << endl;
        cin.ignore();
        getline(cin, username, '\n');
        cout << "Enter your password: " << endl;
        getline(cin, userpass, '\n');
        bool existID = 0;
        for (int i = 0; i < size; ++i)
        {
            if (pass[i].ID == username)
            {
                if (pass[i].password == userpass)
                {
                    index = i;
                    cout << "Successfully login" << endl;
                    return;
                }
                else
                {
                    cout << "Wrong password,Press 1 to try again or 0 to exit" << endl;
                    cin >> sub_choice;
                }
            }
        }
        if (existID == 0)
        {
            cout << "This username does not exist.Press 1 to try again or 0 to exit" << endl;
            cin >> sub_choice;
        }
    }
    return ;
}
void viewinformation(password* pass, int index)
{
    cout << "User name: " << pass[index].name;
    cout << "ID: " << pass[index].password;
}
void changepassword(password* pass, int index)
{
    string password, newpass;
    while (true)
    {
        cout << "Enter the current password: ";
        cin.ignore();
        getline(cin, password, '\n');
        if (password == pass[index].password)
        {
            cout << "Enter the new password: ";
            getline(cin, newpass, '\n');
            pass[index].password = newpass;
            cout << "Change password successfully" << endl;
            return;
        }
        else
        {
            cout << "Password incorrect. Try again.";
        }
    }
}
