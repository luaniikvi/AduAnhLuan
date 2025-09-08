#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

// kế thừa từ Person
class Student :virtual public Person
{
protected:
    std::string studentID = "";
    std::string subjectID = ""; // mã môn học
    double gpa = 0.0;
public:
    Student(){};

    ~Student(){};
};

#endif