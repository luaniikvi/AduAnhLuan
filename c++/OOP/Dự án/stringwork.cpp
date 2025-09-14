#include "stringwork.h"

// assureStr
std::string assureStr(std::string& str) {
    std::getline(std::cin, str);
    return trim(str);
}

// assureInt
int assureInt(const std::string& msg, const int begin, const int end) {
    std::string str;
    std::cout << msg << ": ";
    std::getline(std::cin, str);
    while(!isNumber(str) || stoi(str) < begin || stoi(str) > end){
        std::cout << "Không hợp lệ, vui lòng nhập lại!\n";
        std::cout << msg << ": ";
        std::getline(std::cin, str);
    }
    return stoi(str);
}

// trim
std::string trim(const std::string& str) {
    size_t fst = str.find_first_not_of(" \t\n\r");
    if (fst == std::string::npos) {
        return ""; // toàn là khoảng trắng
    }
    size_t lst = str.find_last_not_of(" \t\n\r");
    return str.substr(fst, lst - fst + 1);
}

// isNumber
bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    for (auto c : str) {
        if (!std::isdigit(c)) 
            return false;
    }
    return true;
}
