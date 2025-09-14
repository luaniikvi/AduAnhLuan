#pragma once

#ifndef ADMINTEACHER_H
#define ADMINTEACHER_H

#include "Teacher.h"
#include "Staff.h"

//Teacher + Staff
class AdminTeacher : public Teacher, public Staff 
{
protected:
    std::string role = "";// vai trò, vd: trưởng khoa
    std::string managementScope = ""; // phạm vi quản lý, vd: khoa công nghệ thông tin
public:
    // Constructor default
    AdminTeacher():
        Staff("", 0, Gender::Other, "", "", "", 0L),
        Teacher("", "", 0L)
    {}
    // Constructor có tham số
    AdminTeacher(const std::string& name, int age, Gender gender,
                 const std::string& staffID, const std::string& job, const std::string& roomNumber, long Ssalary,
                 const std::string& teacherID, const std::string& TsubjectID, long Tsalary,
                 const std::string& role,const std::string managementScope):
        Staff(name, age, gender, staffID, job, roomNumber, Ssalary),
        Teacher(teacherID, TsubjectID, Tsalary),
        role(role), managementScope(managementScope)
    {}
    // Lấy ID của AdminTeacher
    std::vector<std::string> GetID() {
        return {this->staffID,this->teacherID};
    }
    // Nhập thông tin của AdminTeacher
    void AdminTeacherInput(){
        std::cout << "--AdminTeacher Info--" << std::endl;
        std::cout << "Vai trò: ";         role            = assureStr(role);
        std::cout << "Phạm vi quản lý: "; managementScope = assureStr(managementScope);
    }
    void Input() override {
        Staff::Input();
        TeacherInput();
        AdminTeacherInput();
    }
    // Xuất thông tin của AdminTeacher
    void AdminTeacherInfo(){
        std::cout << "--AdminTeacher Info--" << std::endl;
        std::cout << "Vai trò: " << role << std::endl;
        std::cout << "Phạm vi quản lý: " << managementScope << std::endl;
    }
    void ShowInfo() override {
        Staff::ShowInfo();
        TeacherInfo();
        AdminTeacherInfo();
    }
    // Chỉnh sửa thông tin của AdminTeacher
    void Edit() override {
        Staff::Edit();
        TeacherEdit();
        int choice;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. Vai trò\n";
            std::cout << "2. Phạm vi quản lý\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 2);
            switch (choice) {
                case 1:
                    std::cout << "Vai trò: ";
                    role = assureStr(role);
                    break;
                case 2:
                    std::cout << "Phạm vi quản lý: ";
                    managementScope = assureStr(managementScope);
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    };
};

#endif