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
    // Constructor default
    ResearchAssistant():
        Researcher("", 0, Gender::Other, "", "", 0.0, "", ""),
        Teacher("", 0, Gender::Other, "", "", 0L)
    {}
    // Constructor có tham số
    ResearchAssistant(const std::string& name, int age, Gender gender,
                      const std::string& studentID, const std::string& SsubjectID, double gpa,
                      const std::string& fieldOfResearch, const std::string& nameOfInstructor,
                      const std::string& teacherID, const std::string& TsubjectID, long salary):
        Researcher(name, age, gender, studentID, SsubjectID, gpa, fieldOfResearch, nameOfInstructor),
        Teacher(teacherID, TsubjectID, salary)
    {}
    // Lấy ID của ResearchAssistant
    std::vector<std::string> GetID() {
        return {this->studentID,this->teacherID};
    }
    // Nhập thông tin của ResearchAssistant
    void Input() override {
        Researcher::Input();
        TeacherInput();
    }
    // Xuất thông tin của ResearchAssistant
    void ShowInfo() override {
        Researcher::ShowInfo();
        TeacherInfo();
    }
    // Chỉnh sửa thông tin của ResearchAssistant
    void Edit() override {
        Researcher::Edit();
        TeacherEdit();
    };
};

#endif