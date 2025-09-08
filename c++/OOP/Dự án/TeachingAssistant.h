#pragma once

#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Teacher.h"

// Student + Teacher
class TeachingAssistant : public Student, public Teacher
{
protected:
    /* data */
public:
    TeachingAssistant(){};
    ~TeachingAssistant(){};
};

#endif