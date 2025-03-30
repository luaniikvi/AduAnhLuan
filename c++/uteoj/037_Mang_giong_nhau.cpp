#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1000];
    int b[1000];

    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int j=0 ; j<n ; j++) cin >> b[j];

    for(int j=0 ; j<n ; j++)
    {
        for(int i = 0 ; i < n -1 - j ; i ++)
        {
            if(a[i] > a[i+1]) swap(a[i] , a[i+1]);
            if(b[i] > b[i+1]) swap(b[i] , b[i+1]);
        }
    }

    bool equal = true;
    for(int i=0 ; i< n ; i++)
    {
        if(a[i]!= b[i])
        {
            equal = false;
            break;
        }
    }

    cout << (equal ? "YES" : "NO");

    return 0;
}