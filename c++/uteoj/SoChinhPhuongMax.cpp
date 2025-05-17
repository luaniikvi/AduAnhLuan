#include<iostream>
#include<cmath>
using namespace std;
int _max(int a,int b);
bool isSquareNum(int n);

int main()
{
    int a[1000];int max =-1;
    int n;cin >> n;

    for(int i=0;i<n;i++)
    {
        cin  >> a[i];
    }

    for(int i =0 ; i< n ; i++)
    {
        if(isSquareNum(a[i]))
        {
            max = _max(max, a[i]);
        }
    }
    cout << max;

    return 0;
}


bool isSquareNum(int n)
{
    int i = sqrt(n);
    return (i*i == n);
}

int _max(int a,int b)
{
    return (a > b ? a:b);
}