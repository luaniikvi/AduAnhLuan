#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Gender.h"
#include "stringwork.h"
#include <vector>

// base class
class Person{
protected:
    std::string name; // Họ tên
    short age; // Tuổi
    Gender gender; // Giới tính
public:
    // Constructor default
    Person() :
        name(""), age(0),
        gender(Gender::Other)
    {}
    // Constructor có tham số
    Person(const std::string& name, int age, Gender gender):
        name(name), age(age), gender(gender) {}
    // Nhập thông tin của Person
    virtual void Input() {
        std::cout << "--Person Info--\n";
        std::string line;
        std::cout << "Họ và tên: ";
        name = assureStr(name);
        age = assureInt("Tuổi", 0, 150);
        InputGender(gender);
    }
    // Xuất thông tin của Person
    virtual void ShowInfo() {
        std::cout << "--Person Info--\n";
        std::cout << "Họ tên: " << name << std::endl;
        std::cout << "Tuổi: " << age << std::endl;
        std::cout << "Giới tính: " << getMsg(gender) << std::endl; 
    }
    // Chỉnh sửa thông tin của Person
    virtual void Edit() {
        int choice;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. Họ tên\n";
            std::cout << "2. Tuổi\n";
            std::cout << "3. Giới tính\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 3);
            switch (choice) {
                case 1:
                    std::cout << "Họ tên: ";
                    name = assureStr(name);
                    break;
                case 2:
                    age = assureInt("Tuổi", 0, 150);
                    break;
                case 3:
                    
                    InputGender(gender);
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }

    virtual std::vector<std::string> GetID() = 0;

    virtual ~Person()       = default;
};

#endif