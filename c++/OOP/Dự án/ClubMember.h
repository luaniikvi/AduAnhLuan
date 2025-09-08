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
    ~ClubMember(){};
};

#endif