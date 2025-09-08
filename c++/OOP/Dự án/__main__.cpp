// Code by nhóm 8

#include <iostream>
#include "Menu.cpp"
#include "SchoolMember.h"

main(){
    while(true){
        PrintMenu();
        int option = GetOption(0,4); if(!option) break;

        Do(option);
    }
    return 0;
}