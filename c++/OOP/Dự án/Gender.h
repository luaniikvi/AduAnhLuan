#pragma once

#ifndef GENDER_H
#define GENDER_H

#include <string>

enum struct Gender {
    Male   = 1, // Nam
    Female = 2, // Nữ
    Other  = 0  // Khác
};

std::string getMsg(Gender g){
    if(g == Gender::Male) return "Nam";
    if(g == Gender::Female) return "Nữ";
    return "Khác";
}

void InputGender(Gender &g)
{
    
}

#endif