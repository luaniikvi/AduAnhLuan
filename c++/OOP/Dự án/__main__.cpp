// Code by nhóm 8

#include <iostream>
#include "Menu.cpp"
#include "SchoolMember.h"

int main(){
    while(true) {
        PrintMenu();
        int option = GetOption(0,4); if(option == 0) break;

        Do(option);
    }
    return 0;
}