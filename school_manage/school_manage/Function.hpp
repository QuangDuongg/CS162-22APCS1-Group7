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

void inputPassword(Password* pass, istream& inPass, int& size);
void login(Password* pass, int size);

#endif /* Function_hpp */
