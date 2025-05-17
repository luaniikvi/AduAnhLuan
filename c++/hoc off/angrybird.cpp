#include<iostream>
#include<sstream>
using namespace std;
bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%3 == 0 || n%2 == 0) return false;
    for(int i=5 ; i*i <= n ; i+=6)
    {
        if(n%i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}
int Sum(string num)
{
    if(num.length() == 1) return num[0] -'0';
    else
    {
        int sum = 0;
        stringstream ss;
        for(char c : num) sum+= c-'0';
        ss << sum;
        return Sum(ss.str());
    }
}
int main()
{
    int t;cin >> t;
    int mul = 1;
    int control = 0;
    long long x = 0;
    for(int i = 0 ; i< t ; i++)
    {
        cin >> control;
        if(control == 1) x += mul;
        else if(control == 2 ) x -= mul;
        else mul*=-1;
    }
    cout << x;
}