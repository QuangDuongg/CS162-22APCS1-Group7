//
//  menu.cpp
//  
//
//  Created by Nguyễn Bạch Trường Giang on 25/03/2023.
//

#include "menu.hpp"

int stu1menu(){
    int choice;
    cout << "1. View personal info.\n2.Change password.\n3.View your scoreboard.\n4.View your courses.\n5.Exit.\n";
    cout << "Input a number according to what you want to do among the above: ";
    cin >> choice;
    return choice;
}//menu sau login

int staff1menu(){
    int choice;
    cout << "1. View personal info.\n2.Change password.\n3.Work on school year data\n4.Exit.\n";
    cout << "Input a number according to what you want to do among the above: ";
    cin >> choice;
    return choice;
}//menu sau login

int menuSchoolYear(){
    cout << "1. Create school year.\n2.View school year\n3.Exit.\n";
    cout << "Input a number according to what you want to do among the above: ";
    cin >> choice;
    return choice;
}
int menuCreateSY(){
    int choice;
    cout << "1. Create classes.\n2.Create semesters.\n3.Create courses.\n4.Exit.\n";
    cout << "Input a number according to what you want to do among the above: ";
    cin >> choice;
    return choice;
}

int menuViewSY(string& filename){
    
    //cout all school year
    string year;
    cout << "Which one do you want to view (input with the format yearyear): ";
    cin.ignore();
    getline(cin, year, '\n');
    filename = year+"txt";
    
    cout << "1.View classes.\n2.View semesters.\n;
    
    cout << "Input a number according to what you want to do among the above: ";
    cin >> choice;
    return choice;
}
