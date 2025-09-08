#pragma once

#ifndef ADMINTEACHER_H
#define ADMINTEACHER_H

#include "Teacher.h"
#include "Staff.h"

//Teacher + Staff
class AdminTeacher : public Teacher, public Staff 
{
protected:
    std::string role = "";// vai trò, vd: trưởng khoa
    std::string managementScope = ""; // phạm vi quản lý, vd: khoa công nghệ thông tin
public:
    AdminTeacher(/* args */){};
    ~AdminTeacher(){};
};

#endif