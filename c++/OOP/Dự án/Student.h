// Code by nhóm 8

#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

// kế thừa từ Person
class Student :virtual public Person
{
protected:
    std::string studentID = ""; // MSSV
    std::string subjectID = ""; // mã môn học
    double gpa = 0.0;
public:
    Student(){};

    std::vector<std::string> GetID(){
        return {this->studentID};
    }

    void Input(){};
    void ShowInfo(){};
    void Edit(){};
};

#endif