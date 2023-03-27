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
void login(password* pass, int size);
