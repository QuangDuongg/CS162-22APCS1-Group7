#include "Function.hpp"

int main() {
    
        int choice;
        cout << "MENU" << endl;
        cout << "Press 1 to login." << endl;
        cin >> choice;

        ifstream inp;
        inp.open("Password.csv");
        Password pass[200];
        int size;
        inputPassword(pass, inp, size);
        if (choice==1)
            login(pass, size);
        inp.close();
        return 0;
    
    return 0;
}
