#include<iostream>
using namespace std;
int n,r,c,s[101],dp[101];
// r -> a // rr 
// c -> b // 4weaks-continuetious
int dps(int i)
{
    if(i < 0) return 0;
    return dp[i];
}

int layB(int i)
{
    return dps(i-4) + 4*c;
}
int main()
{
    cin >> n >> r >> c;
    for(int i=1 ; i<=n ; i++) cin >> s[i];

    for(int i=1 ; i<=n ; i++)
        dp[i] = min( s[i]*r + dps(i-1),
                     dps(i-4) + 4*c  );
    // Cout giá cuối cùng rẻ nhất
    cout << dp[n];
    return 0;
}