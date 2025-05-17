#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

long long fa(int n)
{
    if(n < 2) return 1;
    return n*fa(n-1);
}

int main()
{
    int n = 50;
    double e = 2.7182;
    double total = 0;
    for(int i= 0; i <= n ; i++)
    {
        total = total + (double)1/fa(i);
        // if(e - total < 0.001)
        // break;
    }
    cout << setprecision(100)<< total << endl;
    cout << fixed << setprecision(2)<< total;
}