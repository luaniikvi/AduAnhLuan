#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

// kế thừa từ Person
class Student :virtual public Person {
protected:
    std::string studentID = ""; // MSSV
    std::string subjectID = ""; // Mã môn học
    double gpa = 0.0;
public:
    // Constructor default
    Student():
        Person("", 0, Gender::Other),
        studentID(""), subjectID(""), gpa(0.0)
    {}
    // Constructor có tham số
    Student(const std::string& studentID, const std::string& subjectID, double gpa):
        studentID(studentID), subjectID(subjectID), gpa(gpa)
    {}
    Student(const std::string& name, int age, Gender gender,
            const std::string& studentID, const std::string& subjectID, double gpa):
        Person(name, age, gender),
        studentID(studentID), subjectID(subjectID), gpa(gpa)
    {} 
    // Lấy ID của Student
    std::vector<std::string> GetID() {
        return {this->studentID};
    }
    // Hàm nhập riêng của Student
    void StudentInput() {
        std::cout << "--Student Info--\n";
        std::cout << "MSSV: ";       studentID  =  assureStr(studentID);
        std::cout << "Mã môn học: "; subjectID  =  assureStr(subjectID);
        std::cout << "GPA: ";        std::cin >> gpa; std::cin.ignore();
    }
    // Nhập thông tin của Student
    void Input() override {
        Person::Input();
        StudentInput();
    }
    // Hàm xuất riêng của Student
    void StudentInfo() {
        std::cout << "--Student Info--\n";
        std::cout << "MSSV: "       << studentID << std::endl;
        std::cout << "Mã môn học: " << subjectID << std::endl;
        std::cout << "GPA: "        << gpa       << std::endl;
    }
    // Xuất thông tin của Student
    void ShowInfo() override {
        Person::ShowInfo();
        StudentInfo();
    }
    // Hàm chỉnh sửa riêng của Student
    void StudentEdit() {
        int choice;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. MSSV\n";
            std::cout << "2. Mã môn học\n";
            std::cout << "3. GPA\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 3);
            switch (choice) {
                case 1:
                    std::cout << "MSSV: ";
                    studentID = assureStr(studentID);
                    break;
                case 2:
                    std::cout << "Mã môn học: ";
                    subjectID = assureStr(subjectID);
                    break;
                case 3:
                    std::cout << "GPA: ";
                    std::cin  >> gpa;
                    std::cin.ignore();
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
    // Chỉnh sửa thông tin của Student
    void Edit() override {
        Person::Edit();
        StudentEdit();
    }
};

#endif