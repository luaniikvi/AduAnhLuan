#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef string BigInt;
int comp(const BigInt &bi1, const BigInt &bi2);
BigInt add(const BigInt &bi1, const BigInt &bi2);
BigInt subtract(const BigInt &bi1, const BigInt &bi2);
BigInt multiplyBigIntWithInt(const BigInt &bigInt, int smallInt);
BigInt multiply(const BigInt &bi1, const BigInt &bi2);
BigInt divideBigIntWithInt(const BigInt &bigInt, int smallInt);
BigInt modBigIntWithInt(const BigInt &bigInt, int smallInt);
BigInt divide(const BigInt &bi1, const BigInt &bi2);
BigInt mod(const BigInt &bi1, const BigInt &bi2);
int main()
{
    BigInt bi1 = "12345678901234567890";
    BigInt bi2 = "12345678901234567891";
    int si = 12345;
    cout << comp(bi1, bi2) << "\n";
    cout << add(bi1, bi2) << "\n";
    cout << subtract(bi1, bi2) << "\n";
    cout << multiplyBigIntWithInt(bi1, si) << "\n";
    cout << divideBigIntWithInt(bi1, si) << "\n";
    cout << modBigIntWithInt(bi1, si) << "\n";
    cout << divide(bi1, bi2) << "\n";
    cout << mod(bi1, bi2) << "\n";
    return 0;
}
// Phép so sánh hai số nguyên lớn
int comp(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép cộng hai số nguyên lớn
BigInt add(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép trừ hai số nguyên lớn
BigInt subtract(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép nhân một số nguyên lớn với với số nguyên nhỏ
BigInt multiplyBigIntWithInt(const BigInt &bigInt, int smallInt)
{
    // your code
}
// Phép nhân hai số nguyên lớn
BigInt multiply(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép chia lấy phần nguyên của một số nguyên lớn với với số nguyên nhỏ
BigInt divideBigIntWithInt(const BigInt &bigInt, int smallInt)
{
    // your code
}
// Phép chia lấy phần dư của một số nguyên lớn với với số nguyên nhỏ
BigInt modBigIntWithInt(const BigInt &bigInt, int smallInt)
{
    // your code
}
// Phép chia lấy phần nguyên của hai số nguyên lớn
BigInt divide(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép chia lấy phần dư của hai số nguyên lớn
BigInt mod(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
// Phép chia lấy phần nguyên của hai số nguyên lớn
BigInt divide(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}

// Phép chia lấy phần dư của hai số nguyên lớn
BigInt mod(const BigInt &bi1, const BigInt &bi2)
{
    // your code
}
