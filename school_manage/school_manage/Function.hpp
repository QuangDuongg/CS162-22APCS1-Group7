//
//  Function.hpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 25/03/2023.
//

#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>
#include "Struct.hpp"

//void inputPassword(Password* pass, istream& inPass, int& size);
//void login(Password* pass, int size);
void staffUpdate(Staff*& staff, Account*& account);
void infoStaff(Staff*& staff);
void infoAcc(Account*& account);
void inputPassword(Account*& pass);
int login(Account* pass, string username, string password);
#endif /* Function_hpp */
