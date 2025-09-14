#pragma once

#include <iostream>
#include <string>
#include "stringwork.h"

enum struct Gender {
    Male   = 1, // Nam
    Female = 2, // Nữ
    Other  = 0  // Khác
};

std::string getMsg(Gender g){
    switch(g){
        case Gender::Male:   return "Nam";
        case Gender::Female: return "Nữ";
        default:             return "Khác";
    }
}

void InputGender(Gender &g) {
    std::cout << "Giới tính (0: Khác, 1: Nam, 2: Nữ)\n";
    g = static_cast<Gender>(assureInt("Nhập giới tính",0,2));
}