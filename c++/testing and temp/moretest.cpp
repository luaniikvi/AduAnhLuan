#include<iostream>
using namespace std;

char mod2(string num)
{
    return (num.back() -'0')%2 +'0';
}

string div2(string num)
{
    string result = "";
    int carry = 0;
    for (char digit : num) {
        int current = (digit - '0') + carry * 10;
        result += (current / 2) + '0';
        carry = current % 2;
    }
    if (result[0] == '0' && result.length() > 1) {
        result = result.substr(1);
    }
    return result;
}

int main()
{
    string n; cin >> n;
    string bi = "";
    while(n!= "0"){
        bi = mod2(n) + bi;
        n = div2(n);
    }
    cout << bi;
}