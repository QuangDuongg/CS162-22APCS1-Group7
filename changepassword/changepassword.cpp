#include "FunctionChangePassword.h"

int main(){
    ifstream inp;
    ofstream outp;
    inp.open("Password.csv");
    cout << inp.is_open();
    cout << "MENU" << endl;
    cout << "Press 3 to change password." << endl;
    int choice, size;
    cin >> choice;
    cin.ignore(100, '\n');

    string username;
    cout << "Enter the username(cai nay do minh da dang nhap vao nen se co bien nho username nhe!)" << endl;
    getline(cin, username, '\n');
//Pass data from csv file to array "pass".  
    password pass[200];
    inputPassword(pass, inp, size);
    inp.close();
//ChangePassword
    if (choice == 3){
        outp.open("Password.csv");
        cout << outp.is_open();
        CheckAndCreat(pass, size, username, outp);
        outp.close();
    }
    return 0;
}
