#pragma once

#ifndef RESEACHER_H
#define RESEACHER_H

#include "Student.h"

// kế thừa từ Student
class Researcher : public Student
{
protected:
    std::string fieldOfReaserch = "";
    std::string nameOfIntructor = "";
    
public:
    Researcher(){};

    ~Researcher(){};
};

#endif