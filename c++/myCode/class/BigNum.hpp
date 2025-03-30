#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class BigInteger {
private:
    std::vector<int> digits;  // Store digits in reverse order for easier calculations
    bool negative;            // Sign flag

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            negative = false;
        }
    }

public:
    // Constructor from string
    BigInteger(const std::string& str = "0") {
        negative = false;
        digits.clear();
        
        int start = 0;
        if (str[0] == '-') {
            negative = true;
            start = 1;
        }
        
        for (int i = str.length() - 1; i >= start; i--) {
            digits.push_back(str[i] - '0');
        }
        removeLeadingZeros();
    }

    // Addition operator
    BigInteger operator+(const BigInteger& other) const {
        if (negative != other.negative) {
            if (negative) {
                BigInteger temp = *this;
                temp.negative = false;
                return other - temp;
            }
            BigInteger temp = other;
            temp.negative = false;
            return *this - temp;
        }

        BigInteger result;
        result.negative = negative;
        result.digits.clear();
        
        int carry = 0;
        size_t maxSize = std::max(digits.size(), other.digits.size());
        
        for (size_t i = 0; i < maxSize || carry; i++) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        
        return result;
    }

    // Subtraction operator
    BigInteger operator-(const BigInteger& other) const {
        if (other.negative) {
            BigInteger temp = other;
            temp.negative = false;
            return *this + temp;
        }
        if (negative) {
            BigInteger temp = other;
            temp.negative = true;
            return *this + temp;
        }

        // If this < other, result will be negative
        if (digits.size() < other.digits.size() ||
            (digits.size() == other.digits.size() && 
             std::lexicographical_compare(digits.rbegin(), digits.rend(),
                                        other.digits.rbegin(), other.digits.rend()))) {
            BigInteger temp = other - *this;
            temp.negative = true;
            return temp;
        }

        BigInteger result;
        result.digits.clear();
        
        int borrow = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            int diff = digits[i] - borrow;
            if (i < other.digits.size()) diff -= other.digits[i];
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            result.digits.push_back(diff);
        }
        
        result.removeLeadingZeros();
        return result;
    }

    // Multiplication operator
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result("0");
        
        for (size_t i = 0; i < other.digits.size(); i++) {
            int carry = 0;
            BigInteger temp;
            temp.digits.resize(i, 0);  // Add trailing zeros
            
            for (size_t j = 0; j < digits.size() || carry; j++) {
                int prod = carry;
                if (j < digits.size()) 
                    prod += digits[j] * other.digits[i];
                
                temp.digits.push_back(prod % 10);
                carry = prod / 10;
            }
            
            result = result + temp;
        }
        
        result.negative = negative != other.negative;
        result.removeLeadingZeros();
        return result;
    }

    // Division operator
    BigInteger operator/(const BigInteger& other) const {
        if (other == BigInteger("0")) {
            throw std::runtime_error("Division by zero");
        }

        BigInteger abs_dividend = *this;
        BigInteger abs_divisor = other;
        abs_dividend.negative = false;
        abs_divisor.negative = false;

        if (abs_dividend < abs_divisor) {
            return BigInteger("0");
        }

        std::string result;
        BigInteger current;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            current = current * BigInteger("10") + BigInteger(std::to_string(digits[i]));
            int x = 0;
            while (current >= abs_divisor) {
                current = current - abs_divisor;
                x++;
            }
            result += std::to_string(x);
        }

        BigInteger quotient(result);
        quotient.negative = negative != other.negative;
        quotient.removeLeadingZeros();
        return quotient;
    }

    // Comparison operators
    bool operator<(const BigInteger& other) const {
        if (negative != other.negative) return negative;
        if (digits.size() != other.digits.size())
            return negative ? (digits.size() > other.digits.size()) : 
                            (digits.size() < other.digits.size());
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i])
                return negative ? (digits[i] > other.digits[i]) : 
                                (digits[i] < other.digits[i]);
        }
        return false;
    }

    bool operator==(const BigInteger& other) const {
        return negative == other.negative && digits == other.digits;
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    // String conversion
    std::string toString() const {
        std::string result;
        if (negative) result += "-";
        for (int i = digits.size() - 1; i >= 0; i--) {
            result += std::to_string(digits[i]);
        }
        return result;
    }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& bi) {
        os << bi.toString();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& bi) {
        std::string str;
        is >> str;
        bi = BigInteger(str);
        return is;
    }
};