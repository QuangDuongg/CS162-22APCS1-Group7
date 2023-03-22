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
void CheckAndCreat(password* pass, int size, string username, ofstream& outp);
void updateFilePassword(password* pass, int size, ofstream& outp);