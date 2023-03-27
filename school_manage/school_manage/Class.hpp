//
//  Class.hpp
//  school_manage
//
//  Created by Nguyễn Bạch Trường Giang on 26/03/2023.
//

#ifndef Class_hpp
#define Class_hpp

#include <stdio.h>
#include "Struct.hpp"

void createClass(schoolyear& sy);
void saveClassToFile(schoolyear sy, ostream& fout);
void readOldClassFile(schoolyear*& sy, istream& oldsy);
#endif /* Class_hpp */
