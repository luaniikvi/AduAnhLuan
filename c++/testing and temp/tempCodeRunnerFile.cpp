#include<iostream>
using namespace std;
string DecToBi(int n){
    string bi = "";
    while(n > 0){
        char num = n%2 - '0';
        bi = num + bi;
        n /= 2;
    }
    return bi;
}
string DecToOc(int n){
    string oc = "";
    while(n > 0){
        char num = n%8 - '0';
        oc = num + oc;
        n /= 8;
    }
    return oc;
}
string DecToHex(int n){
    string hex = "";
    while(n > 0){
        int remainder = n % 16;
        char hexDigit;
        if(remainder < 10){
            hexDigit = remainder + '0';
        } else {
            hexDigit = remainder - 10 + 'A';
        }
        hex = hexDigit + hex;
        n /= 16;
    }
    return hex;
}

int main()
{
    int n;cin >> n;
    cout << DecToBi(n) << endl;
    cout << DecToOc(n) << endl;
    cout << DecToHex(n) << endl;
}