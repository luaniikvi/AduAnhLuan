// Code by nhóm 8

#pragma once

#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H

#include "Researcher.h"
#include "Teacher.h"

class ResearchAssistant : public Researcher, public Teacher
{
private:
    /* data */
public:
    ResearchAssistant(){};
    std::vector<std::string> GetID(){
        return {this->studentID,this->teacherID};
    }

    void Input(){};
    void ShowInfo(){}
    void Edit(){};
};

#endif