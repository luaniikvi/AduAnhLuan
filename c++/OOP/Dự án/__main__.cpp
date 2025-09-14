#include <iostream>
#include "Menu.cpp"
#include "stringwork.cpp"
#include "SchoolMember.h"

using namespace std;

main(){
    while(true){
        PrintMenu();
        int option = GetOption(0,4); if(!option) break;

        Do(option);
    }
    return 0;
}