#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Gender.h"

// base class
class Person
{
protected:
    std::string name;
    short age;
    Gender gender;
public:
    Person() = default;

    virtual void Input()    = 0;
    virtual void ShowInfo() = 0;
    virtual void Edit()     = 0;

    virtual ~Person()       = default;
};

#endif