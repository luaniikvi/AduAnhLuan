#include<iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int a[100],first_max = -1e6,sec_max = -1e6;
    for(int i= 0 ;i < n ;i++) cin >> a[i];
    for(int i= 0 ;i < n ;i++)
    {
        first_max = max(first_max,a[i]);
    }
    for(int i= 0 ;i < n ;i++)
    {
        if(first_max == a[i]) continue;
        sec_max = max(sec_max , a[i]);
    }

    cout << (sec_max == -1e6 ? -1 : sec_max);
}