#include<iostream>
// kho qua
using namespace std;
int n,x[101],f[101],dp[101];

int sum(int start, int end)
{
    int s = 0;
    for(int i = start ; i<= end ; i++)
        s+= min(x[i],f[i-start+1]);
    return s;
}

int main()
{
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> x[i];
    for(int i=1 ; i<=n ; i++) cin >> f[i];

    dp[1] = min(x[1],f[1]);
    for(int i=1 ; i<=n ; i++)
    {
        dp[i] = sum(1,i);
        for(int k = 1 ; k<=i ; k++)
        {
            dp[i] = max(dp[i], 
                dp[k-1] + sum(k+1,i)
            );
        }
    }
    // for(int i=1 ; i<=n ; i++)
    //    cout << dp[i] << ' ';
    cout << dp[n]; 
    return 0;
}