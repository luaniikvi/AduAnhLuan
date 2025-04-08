#include<iostream>
// 5 2
// 7 3 3 9 10

using namespace std;
int d[25];
int dp[25][25][2];
int step[] = {0,1};
int _m(int a, int b)
{
    return (a > b ? a : b);
}
int m4(int a, int b, int c , int d)
{
    return _m(_m(_m(a,b),c),d);
}
int main()
{
    int n,k; cin >> n >> k;


    for(int i = 0 ; i < n ; i++)
    {
        cin >> d[i];
    }

    dp[0][0][0] = dp[0][0][1] = d[0];
    dp[1][0][0] = dp[1][0][1] = d[1];

    int last = 0;
    for(int i = 2 ; i < n ; ++i)
    {
        for(int len = i/2 ; len <= i && len < k; len++)
        {
            for(int s : step)
            {
                if(i - len - s > 1) continue;
                dp[i][len][s] = d[i] + max(
                    dp[i-s-1][len-1][0],
                    dp[i-s-1][len-1][1]
                );
                last = max(last,dp[i][len][s]);
            }
        }
    }
    cout << last;
    return 0;   
}
