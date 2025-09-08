// Code by nhóm 8

#pragma once

#ifndef CLUBLEADER_H
#define CLUBLEADER_H

#include "ClubMember.h"
#include "Teacher.h"

//ClubMember + Teacher
class ClubLeader : public ClubMember, public Teacher
{
protected:
    std::string role = "";
public:
    ClubLeader(){};
    ~ClubLeader(){};

    std::vector<std::string> GetID(){
        return {this->studentID,this->teacherID};
    }

    void Input(){};
    void ShowInfo(){};
    void Edit(){};
};

#endif