#include "MyFunction.h"
int main(){
    int choice;
    cout << "MENU" << endl;
    cout << "Press 1 to login." << endl;
    cin >> choice;
    if (choice == 1){
        //Log in1
        ifstream inp;
        inp.open("Password.csv");
        password pass[200];
        int size;
        inputPassword(pass, inp, size);
        string username;
        login(pass, size, username, choice);
        //MENU after logging in
        if (choice == 1){
            cout << "MENU" << endl;
            cout << "Press 1 to display information." << endl;
            cout << "Press 2 to change password." << endl;
            cin >> choice;
            cin.get();
            //Display Information if press 1
            //Change Password if press 2
            if (choice == 2){
                ofstream outp;
                outp.open("Password.csv");
                CheckAndCreat(pass, size, username, outp);
                outp.close();
            }
            inp.close();
        }
    }
    return 0;
}
