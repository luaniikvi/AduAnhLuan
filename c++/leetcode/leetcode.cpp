#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long rev(long long x);

int main()
{

    long long x = 1534236469;
    long long test = 964632435;
    cout << rev(x);

    return 0;
}

long long rev(long long x)
{
    if(abs(x) < 10) return x;
    //long long dau = (x>0 ? 1 : -1);
    long long rev =0;
    while(x != 0)
    {
        rev = rev*10;
        rev += x%10;
        x/=10;
    }

    return rev;
}