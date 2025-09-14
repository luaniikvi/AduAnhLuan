#pragma once

#ifndef CLUBLEADER_H
#define CLUBLEADER_H

#include "ClubMember.h"

//ClubMember
class ClubLeader : public ClubMember
{
protected:
    std::string role = "";
public:
    // Constructor default
    ClubLeader():
        ClubMember("", 0, Gender::Other, "", "", 0.0, "")
    {}
    // Constructor có tham số
    ClubLeader(const std::string& name, int age, Gender gender,
               const std::string& studentID, const std::string& SsubjectID, double gpa,
               const std::string& clubName, const std::string role):
        ClubMember(name, age, gender, studentID, SsubjectID, gpa, clubName),
        role(role)
    {}
    // Lấy ID của ClubLeader
    std::vector<std::string> GetID() {
        return {this->studentID};
    }
    // Nhập thông tin của ClubLeader
    void ClubLeaderInput(){
        std::cout << "--ClubLeader Info--\n";
        std::cout << "Vai trò trong CLB: "; role = assureStr(role);
    }
    void Input() override {
        ClubMember::Input();
        ClubLeaderInput();
    }
    // Xuất thông tin của ClubLeader
    void ClubLeaderInfo(){
        std::cout << "--ClubLeader Info--\n";
        std::cout << "Vai trò trong CLB: " << this->role << std::endl;
    }
    void ShowInfo() override {
        ClubMember::ShowInfo();
        ClubLeaderInfo();
    }
    // Chỉnh sửa thông tin của ClubLeader
    void ClubLeaderEdit() {
        std::cout << "Vai trò trong CLB: "; role = assureStr(role);
    }
    void Edit() override {
        ClubMember::Edit();
        ClubLeaderEdit();
    };
};

#endif