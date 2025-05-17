#include<iostream>
#define INT_MIN -100000
using namespace std;
int main()
{
    int n;cin >> n;
    int a[1000];int _max = INT_MIN;int secMax = INT_MIN;

    for(int i =0; i<n ; i++)
    {
        cin >> a[i];
        _max = max(_max,a[i]);
    }

    for(int i =0 ; i<n ; i++)
    {
        if(a[i]==_max) continue;
        if(a[i] > secMax) secMax = a[i];
    }
    if(secMax == INT_MIN) cout << "None";
    else cout << secMax;

    return 0;
}