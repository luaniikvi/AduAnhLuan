// Code by nhóm 8

#pragma once

#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

// kế thừa từ Person
class Staff : virtual public Person
{
protected:
    std::string staffID = "";
    std::string job = "";
    std::string roomNumber = "";
    long salary = 0l;
public:
    Staff(){};
    
    std::vector<std::string> GetID(){
        return {this->staffID};
    } 

    void Input(){};
    void ShowInfo(){}
    void Edit(){};
};

#endif