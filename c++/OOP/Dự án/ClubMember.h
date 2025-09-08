// Code by nhóm 8

#pragma once

#ifndef CLUBMEMBER_H
#define CLUBMEMBER_H

#include "Student.h"

// kế thừa từ Student
class ClubMember : public Student
{
protected:
    std::string clubName = "";
public:
    ClubMember(){};
    
    std::vector<std::string> GetID(){
        return {this->studentID};
    }

    void Input(){};
    void ShowInfo(){}
    void Edit(){};
};

#endif