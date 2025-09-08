// Code by nhóm 8

#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Gender.h"
#include <vector>

// base class
class Person
{
protected:
    std::string name;
    short age;
    Gender gender;
public:
    Person(){
        name = "none";
    }

    virtual void Input()    = 0;
    virtual void ShowInfo() = 0;
    virtual void Edit()     = 0;

    virtual std::vector<std::string> GetID() = 0;

    virtual ~Person()       = default;
};

#endif