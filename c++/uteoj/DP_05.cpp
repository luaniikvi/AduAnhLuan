#include<iostream>
using namespace std;
int n,x[101],f[101],dp[101];

int main()
{
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> x[i];
    for(int i=1 ; i<=n ; i++) cin >> f[i];
    dp[0] = 0;
    for(int i=1 ; i<=n ; i++)
    {
        dp[i] = dp[i-1];
        for(int k=0 ; k<i ; k++)
        {
            dp[i] = max(
                dp[i],
                dp[k] + min(f[i-k],x[i])
            );
        }
    }
    cout <<endl << dp[n];
    return 0;
}