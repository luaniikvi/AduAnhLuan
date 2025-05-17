#include<string>
using namespace std;
string decimalToBinary(int num) {
    if (num == 0) return "0";

    std::string binary;
    while (num > 0) {
        binary = std::to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}