#include<iostream>
using namespace std;

bool isPerf(int n);
int _max(int a, int b);

int main()
{
    int n;
    cin >> n;
    int a[50];
    int max = 0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(isPerf(a[i]))
        {
            max = _max(max ,(int)a[i]);
        }
    }

    cout << max;

    return 0;
}

bool isPerf(int n)
{
    if(n <= 1) return  false;
    int sum =0;
    for(int i= 1; i < n ; i++)
    {
        if(n%i == 0) sum += i;
    }

    return sum == n;
}

int _max(int a, int b)
{
    return (a > b ? a : b);
}