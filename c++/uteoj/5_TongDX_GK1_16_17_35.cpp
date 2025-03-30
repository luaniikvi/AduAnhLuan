#include<iostream>
#include<cmath>
using namespace std;    
int main()
{
    int n;
    cin >> n;
    long long int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        int mu = log10(i)+1;
        sum += i*pow(10,mu)+i;
    }
    cout << sum;
}