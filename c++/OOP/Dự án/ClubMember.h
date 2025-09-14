#pragma once

#ifndef CLUBMEMBER_H
#define CLUBMEMBER_H

#include "Student.h"

// kế thừa từ Student
class ClubMember : public Student {
protected:
    std::string clubName = ""; // Tên câu lạc bộ
public:
    // Constructor default
    ClubMember():
        Student("", 0, Gender::Other, "", "", 0.0),
        clubName("") 
    {}
    // Constructor có tham số
    ClubMember(const std::string& name, int age, Gender gender,
               const std::string& studentID, const std::string& subjectID, double gpa,
               const std::string& clubName):
        Student(name, age, gender, studentID, subjectID, gpa),
        clubName(clubName)
    {}
    // Lấy ID của Club Member
    std::vector<std::string> GetID(){
        return {this->studentID};
    }
    // Nhập thông tin của Club Member
    void ClubMemberInput() {
        std::cout << "--ClubMember Info--\n";
        std::cout << "Câu lạc bộ: "; clubName = assureStr(clubName);
    }
    void Input() override{
        Student::Input();
        ClubMemberInput();
    }
    // Xuất thông tin của Club Member
    void ClubMemberInfo() {
        std::cout << "--ClubMember Info--\n";
        std::cout << "Câu lạc bộ: " << clubName << std::endl;
    }
    void ShowInfo() override{
        Student::ShowInfo();
        ClubMemberInfo();
    }
    // Chỉnh sửa thông tin của Club Member
    void Edit() override{
        Student::Edit();
        int choice;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. Câu lạc bộ\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 1);
            switch (choice) {
                case 1:
                    std::cout << "Câu lạc bộ: ";
                    clubName = assureStr(clubName);
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
};

#endif