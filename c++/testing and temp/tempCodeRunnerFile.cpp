#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to multiply a binary string by 2
string multiplyByTwo(string num) {
    string result;
    int carry = 0;
    
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = (num[i] - '0') * 2 + carry;
        result.push_back((digit % 10) + '0');
        carry = digit / 10;
    }
    
    if (carry > 0) {
        result.push_back(carry + '0');
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Helper function to add two binary strings
string addBinaryStrings(string a, string b) {
    string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.push_back((sum % 2) + '0');
        carry = sum / 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string hexToBinaryString(string hexStr) {
    // Remove 0x prefix if present
    if (hexStr.substr(0, 2) == "0x") {
        hexStr = hexStr.substr(2);
    }
    
    string binary = "0";
    
    for (char c : hexStr) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = 10 + (c - 'A');
        } else if (c >= 'a' && c <= 'f') {
            value = 10 + (c - 'a');
        } else {
            return "Invalid hexadecimal number";
        }
        
        // Multiply current binary by 16 (shift left by 4)
        for (int i = 0; i < 4; i++) {
            binary = multiplyByTwo(binary);
        }
        
        // Add the new value
        string temp = to_string(value);
        string valueBinary = "0";
        for (char bit : temp) {
            valueBinary = multiplyByTwo(valueBinary);
            if (bit == '1') {
                valueBinary = addBinaryStrings(valueBinary, "1");
            }
        }
        
        binary = addBinaryStrings(binary, valueBinary);
    }
    
    // Remove leading zeros
    size_t firstNonZero = binary.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        return binary.substr(firstNonZero);
    }
    return "0";
}

int main() {
    string hexStr;
    cin >> hexStr;
    cout << hexToBinaryString(hexStr) << endl;
    return 0;
}
