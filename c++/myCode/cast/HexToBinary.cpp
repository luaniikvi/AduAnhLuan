#include<iostream>
using namespace std;
// bảng chuyển đổi từ hệ 16 sang hệ 2
string hexToBinary(char hex) {
    switch(hex) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': case 'a': return "1010";
        case 'B': case 'b': return "1011";
        case 'C': case 'c': return "1100";
        case 'D': case 'd': return "1101";
        case 'E': case 'e': return "1110";
        case 'F': case 'f': return "1111";
        case '.': return ".";
        default: return "";
    }
}

string convToBinary(string hex)
{
    string binary = "";
    for (int i = 0; i < hex.length(); ++i) {
        binary += hexToBinary(hex[i]);
    }
    return binary;
}
int main()
{
    string hex;
    cout << "Nhap so he 16:  ";
    getline(cin, hex);
    string binary = convToBinary(hex);
    cout << "He 2 tuong ung: " << binary;
}