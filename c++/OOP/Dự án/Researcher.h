#pragma once

#ifndef RESEACHER_H
#define RESEACHER_H

#include "Student.h"

// kế thừa từ Student
class Researcher : public Student
{
protected:
    std::string fieldOfResearch = "";
    std::string nameOfInstructor = "";
    
public:
    // Constructor default
    Researcher():
        Student("", 0, Gender::Other, "", "", 0.0),
        fieldOfResearch(""), nameOfInstructor("")
    {}
    // Constructor có tham số
    Researcher(const std::string& fieldOfResearch, const std::string& nameOfInstructor):
        fieldOfResearch(fieldOfResearch), nameOfInstructor(nameOfInstructor)
    {}
    Researcher(const std::string& name, int age, Gender gender,
               const std::string& studentID, const std::string& subjectID, double gpa,
               const std::string& fieldOfResearch, const std::string& nameOfInstructor):
        Student(name, age, gender, studentID, subjectID, gpa),
        fieldOfResearch(fieldOfResearch), nameOfInstructor(nameOfInstructor)
    {} 
    // Lấy ID của Researcher
    std::vector<std::string> GetID() {
        return {this->studentID};
    }
    // Hàm nhập riêng của Researcher
    void ResearcherInput() {
        std::cout << "--Researcher Info--\n";
        std::cout << "Lĩnh vực nghiên cứu: "; fieldOfResearch = assureStr(fieldOfResearch);
        std::cout << "Người hướng dẫn: ";     nameOfInstructor = assureStr(nameOfInstructor);
    }
    // Nhập thông tin của Researcher
    void Input() override {
        Student::Input();
        ResearcherInput();
    }
    // Hàm xuất riêng của Researcher
    void ResearcherInfo() {
        std::cout << "--Researcher Info--\n";
        std::cout << "Lĩnh vực nghiên cứu: " << fieldOfResearch << std::endl;
        std::cout << "Người hướng dẫn: "     << nameOfInstructor << std::endl;
    }
    // Xuất thông tin của Researcher
    void ShowInfo() override {
        Student::ShowInfo();
        ResearcherInfo();
    }
    // Hàm chỉnh sửa riêng của Researcher
    void ResearcherEdit() {
        int choice;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. Lĩnh vực nghiên cứu\n";
            std::cout << "2. Người hướng dẫn\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 2);
            switch (choice) {
                case 1:
                    std::cout << "Lĩnh vực nghiên cứu: ";
                    fieldOfResearch = assureStr(fieldOfResearch);
                    break;
                case 2:
                    std::cout << "Người hướng dẫn: ";
                    nameOfInstructor = assureStr(nameOfInstructor);
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
    // Chỉnh sửa thông tin của Researcher
    void Edit() override {
        Person::Edit();
        ResearcherEdit();
    }
};

#endif