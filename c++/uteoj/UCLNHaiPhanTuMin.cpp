#include<iostream>
#include<climits>
using namespace std;

int UCLN(int a, int b)
{
    if(b == 0) return a;
    return UCLN(b,a%b);
}

int main()
{   
    int n;cin >> n;
    int a[1000];
    for(int i=0 ;i< n ; i++)
    {
        cin >> a[i];
    }

    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
    cout << UCLN(a[0],a[1]);
}