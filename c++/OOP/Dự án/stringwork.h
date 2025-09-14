#pragma once
#ifndef STRINGWORK_H
#define STRINGWORK_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

// assureStr(string): xử lý chuỗi nhập vào 
std::string assureStr(std::string& str);

// assureInt(string, message, begin, end): xử lý số nhập vào
int assureInt(const std::string& msg, const int begin, const int end);

// trim(string): xóa khoảng trắng đầu/cuối
std::string trim(const std::string& str);

// isNumber(string): kiểm tra chuỗi có phải toàn số hay không
bool isNumber(const std::string& str);

#endif
