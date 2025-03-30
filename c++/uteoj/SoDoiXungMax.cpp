#include<iostream>
using namespace std;
int _max(int a, int b);
bool LaSoDoiXung(int n);

int main()
{
    int a[100];
    int n;
    cin >> n;
    int max =-1;
    for(int i =0 ; i<n;i++)
    {
        cin >> a[i];
        if(LaSoDoiXung(a[i]))
        {
            max = _max(max,a[i]);
        }
    }
    cout << max;
    return 0;
}

int _max(int a, int b)
{
    return (a >b ? a : b);
}

bool LaSoDoiXung(int n)
{
    if(n < 0) return false;
    int ori = n;

    int rev = 0;
    while(n!= 0)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }

    return ori == rev;
}