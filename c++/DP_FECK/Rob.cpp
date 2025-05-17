// https://leetcode.com/problems/house-robber/
#include<iostream>
using namespace std;
int d[100],dp[100];

int dps(int i)
{
    if(i< 0) return 0;
    return dp[i];
}
int max(int a,int b){
    return (a > b ? a : b);
}
int main()
{
    int n; cin >> n;
    for(int i=0 ; i<n ; i++) cin >> d[i];

    int res = 0;
    for(int i=0 ; i<n; i++)
    {
        dp[i] = max(dps(i-1), d[i] + dps(i-2));
        //res = max(res, dp[i]);
    }
    cout << dp[n-1];
    return 0;
}