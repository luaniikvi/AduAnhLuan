#pragma once

#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Teacher.h"

// Student + Teacher
class TeachingAssistant : public Student, public Teacher {
protected:
    /* data */
public:
    // Constructor default
    TeachingAssistant():
        Person("", 0, Gender::Other),
        Student("", 0, Gender::Other, "", "", 0.0),
        Teacher("", 0, Gender::Other, "", "", 0L)
    {}
    // Constructor có tham số

    TeachingAssistant(const std::string& name, int age, Gender gender,
                      const std::string& studentID, const std::string& SsubjectID, double gpa,
                      const std::string& teacherID, const std::string& TsubjectID, long salary):
        Student(name, age, gender, studentID, SsubjectID, gpa),
        Teacher(name, age, gender, teacherID, TsubjectID, salary)
    {}
    // Lấy ID của obj
    std::vector<std::string> GetID() {
        return {this->studentID,this->teacherID};
    }
    // Nhập thông tin của obj
    void Input() override {
        Student::Input();
        TeacherInput();
    }
    // Xuất thông tin của obj
    void ShowInfo() override {
        Student::ShowInfo();
        TeacherInfo();
    }
    // Chỉnh sửa thông tin của obj
    void Edit() override {
        Student::Edit();
        TeacherEdit();
    };
};

#endif