#include<iostream>
using namespace std;
int n,a[101],b[101], dp[101][2];

int main()
{
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    for(int i=1 ; i<=n ; i++) cin >> b[i];

    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for(int i=2 ; i<=n ; i++)
    {
        dp[i][0] = a[i] + max( dp[i-1][0] , dp[i-2][1]);
        dp[i][1] = b[i] + max( dp[i-1][1] , dp[i-2][0]);
    }
    cout << max(dp[n][1], dp[n][0]);
    return 0;
}