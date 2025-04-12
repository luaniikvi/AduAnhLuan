#include<iostream>
#include<algorithm>
using namespace std;
int n ,m ,tp0[100], tp1[100], dp[100][2]; 
int main()
{
    cin >> n >> m;
    for(int i=0 ;i<n ;i++) cin >> tp0[i];
    for(int i=0 ;i<n ;i++) cin >> tp1[i];

    dp[0][0] = tp0[0];
    dp[0][1] = tp1[0];
    for(int i=1 ; i < n ; i++)
    {
        dp[i][0] = tp0[i] + min(dp[i-1][0] , m + dp[i-1][1]);
        dp[i][1] = tp1[i] + min(dp[i-1][1] , m + dp[i-1][0]);
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
    return 0;
}