// Code by nhóm 8

#pragma once

#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

// kế thừa từ Person
class Teacher :virtual public Person
{
protected:
    std::string teacherID = "";
    std::string subjectID = ""; // mã môn dạy
    long salary = 0L;
public:
    Teacher(){};

    std::vector<std::string> GetID(){
        return {this->teacherID};
    }

    void Input(){};
    void ShowInfo(){}
    void Edit(){};
};

#endif