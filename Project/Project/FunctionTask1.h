#include <iostream>
#include <string>
#include "Struct.h"
using namespace std;
//Function change password
void updateFilePassword(password* pass, int size, ofstream& outp);
bool checkPW(password *pass, int size, string recentPW, string username);
void updatePassword(password* pass, int size, string newPW, string username);
void CheckAndCreat(password* pass, int size, string username, ofstream& outp);
//Function login
void inputPassword(password* pass, istream& inPass, int& size);
void login(password* pass, int size, string& username, int& choice);
bool isExistID(string username, password* pass, int size);