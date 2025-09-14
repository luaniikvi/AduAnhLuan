#pragma once

#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

// kế thừa từ Person
class Staff : virtual public Person
{
protected:
    std::string staffID = ""; // MSNV (Mã số nhân viên)
    std::string job = ""; // Công việc
    std::string roomNumber = ""; // Số phòng
    long salary = 0l; // Lương
public:
    // Constructor default
    Staff():
        Person("", 0, Gender::Other),
        staffID(""), job(""), roomNumber(""), salary(0l)
    {}
    // Constructor có tham số
    Staff(const std::string& name, int age, Gender gender,
          const std::string& staffID, const std::string& job, const std::string& roomNumber, long salary):
        Person(name, age, gender),
        staffID(staffID), job(job), roomNumber(roomNumber), salary(salary)
    {} 
    // Lấy ID của Staff
    std::vector<std::string> GetID() {
        return {this->staffID};
    }
    // Hàm nhập riêng của Staff
    void StaffInput() {
        std::cout << "--Staff Info--\n";
        std::cout << "MSNV: ";      staffID =          assureStr(staffID);
        std::cout << "Công việc: "; job =                  assureStr(job);
        std::cout << "Số phòng: ";  roomNumber =    assureStr(roomNumber);
        std::cout << "Lương: ";     std::cin >> salary; std::cin.ignore();
    }
    // Nhập thông tin của Staff
    void Input() override {
        Person::Input();
        StaffInput();
    }
    // Hàm xuất riêng của Staff
    void StaffInfo() {
        std::cout << "--Staff Info--\n";
        std::cout << "MSNV: "      << staffID    << std::endl;
        std::cout << "Công việc: " << job        << std::endl;
        std::cout << "Số phòng: "  << roomNumber << std::endl;
        std::cout << "Lương: "     << salary     << std::endl;
    }
    // Xuất thông tin của Staff
    void ShowInfo() override {
        Person::ShowInfo();
        StaffInfo();
    }
    // Hàm chỉnh sửa riêng của Staff
    void StaffEdit() {
        int choice;
        std::string line;
        do {
            std::cout << "\nHãy nhập lựa chọn cần sửa\n";
            std::cout << "1. MSNV\n";
            std::cout << "2. Công việc\n";
            std::cout << "3. Số phòng\n";
            std::cout << "4. Lương\n";
            std::cout << "0. Trang kế tiếp\n";
            choice = assureInt("Lựa chọn", 0, 4);
            switch (choice) {
                case 1:
                    std::cout << "MSNV: ";
                    staffID = assureStr(staffID);
                    break;
                case 2:
                    std::cout << "Công việc: ";
                    job = assureStr(job);
                    break;
                case 3:
                    std::cout << "Số phòng: ";
                    roomNumber = assureStr(roomNumber);
                case 4:
                    std::cout << "Lương: ";
                    std::cin  >> salary;
                    std::cin.ignore();
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
    // Chỉnh sửa thông tin của Staff
    void Edit() override {
        Person::Edit();
        StaffEdit();
    }
};

#endif