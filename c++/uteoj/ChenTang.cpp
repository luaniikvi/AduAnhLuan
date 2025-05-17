#include<iostream>
using namespace std;
int main()
{
    int n ,x;
    cin >> n >> x;
    int a[200];
    for(int i=0;i< n ; i++)
    {
        cin >> a[i];
    }
    a[n] = x;
    n++;

    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for(int i=0 ; i<n ; i++) cout << a[i] << " ";
}