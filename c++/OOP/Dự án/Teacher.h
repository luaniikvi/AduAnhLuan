#pragma once

#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

// kế thừa từ Person
class Teacher :virtual public Person {
protected:
    std::string teacherID = ""; // MSGV
    std::string subjectID = ""; // Mã môn dạy
    long salary = 0L; // Lương
public:
    //Constructor default
    Teacher():
        Person("", 0, Gender::Other),
        teacherID(""), subjectID(""), salary(0L)
    {}
    //Constructor có tham số
    Teacher(const std::string& teacherID, const std::string subjectID, long salary):
        teacherID(teacherID), subjectID(subjectID), salary(salary)
    {}
    Teacher(const std::string& name, int age, Gender gender,
            const std::string& teacherID, const std::string subjectID, long salary):
        Person(name, age, gender),
        teacherID(teacherID), subjectID(subjectID), salary(salary)
    {}
    // Lấy ID của obj
    std::vector<std::string> GetID(){
        return {this->teacherID};
    }
    // Hàm nhập riêng của Teacher
    void TeacherInput() {
        std::cout << "--Teacher Info--\n";
        std::cout << "MSGV: ";       teacherID =      assureStr(teacherID);
        std::cout << "Mã môn dạy: "; subjectID =      assureStr(subjectID);
        std::cout << "Lương: ";      std::cin >> salary; std::cin.ignore();
    }
    // Nhập thông tin cho Teacher
    void Input() override {
        Person::Input();
        TeacherInput();
    }
    // Hàm xuất riêng của Teacher
    void TeacherInfo() {
        std::cout << "--Teacher Info--\n";
        std::cout << "MSGV: "       << teacherID << std::endl;
        std::cout << "Mã môn dạy: " << subjectID << std::endl;
        std::cout << "Lương: "      << salary    << std::endl;
    }
    // Xuất thông tin của Teacher
    void ShowInfo() override {
        Person::ShowInfo();
        TeacherInfo();
    }
    // Hàm chỉnh sửa riêng của Teacher
    void TeacherEdit() {
        int choice;
        std::string line;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. MSGV\n";
            std::cout << "2. Mã môn dạy\n";
            std::cout << "3. Lương\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 3);
            switch (choice) {
                case 1:
                    std::cout << "MSGV: ";
                    teacherID = assureStr(teacherID);
                    break;
                case 2:
                    std::cout << "Mã môn dạy: ";
                    subjectID = assureStr(subjectID);
                    break;
                case 3:
                    std::cout << "Lương: ";
                    std::cin  >> salary;
                    std::cin.ignore();
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
    // Chỉnh sửa thông tin của Teacher
    void Edit() override {
        Person::Edit();
        TeacherEdit();
    }
};

#endif