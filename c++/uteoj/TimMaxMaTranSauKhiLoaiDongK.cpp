#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
#define _MIN LONG_LONG_MIN
#define ll long long
using namespace std;

int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    vector<vector<ll>> matrix(m,vector<ll>(n));
    for(vector<ll> &j : matrix)
    for(ll &i : j ) cin >> i;

    for(int i = 0 ; i< n ; i++)
    {
        matrix[k][i] = _MIN;
    }

    ll Max = _MIN;
    for(vector<ll> &j : matrix)
    {
        for(ll &i : j) Max = max(Max, i);
    }

    cout << Max;

    return 0;
}