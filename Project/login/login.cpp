#include "FunctionLogin.h"

void inputPassword(password* pass, istream& inPass, int& size);
void login(password* pass, int size);

int main() {
    int choice;
    cout << "MENU" << endl;
    cout << "Press 1 to login." << endl;
    cin >> choice;

    ifstream inp;
    inp.open("Password.csv");
    password pass[200];
    int size;
    inputPassword(pass, inp, size);
    if (choice==1)
        login(pass, size);
    inp.close();
    return 0;
}
