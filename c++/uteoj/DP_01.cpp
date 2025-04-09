#include<iostream>
#include<algorithm>
using namespace std;

int l[10000],h[10000],dp[10000],n;

int dps(int i)
{
    if(i < 0) return 0;
    return dp[i]; 
}

int main()
{
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> l[i];
    for(int i=0 ; i<n ; i++) cin >> h[i];

    for(int i=0 ; i < n ; i++)
    {
        dp[i] = dps(i-1);
        dp[i] = max(dp[i], dps(i-1) + l[i]);
        if(i > 0)
        dp[i] = max(dp[i], dps(i-2) + h[i]);
    }
    cout << dps(n-1);
    return 0;
}