#include<iostream>
#include<algorithm>
// 5 2
// 7 3 3 9 10
// -> 12
using namespace std;
int d[25];
int dp[25][25];

bool valid(int i , int len){
    return (len <= i && len >= i/2);
}

int main()
{
    int n,k; cin >> n >> k;
    for(int i = 0 ; i < n ; i++)    cin >> d[i];

    if(n == 1){
        cout << d[0];
        return 0;
    }
    if(n == 2){
        cout << d[0] + d[1];
        return 0;
    }

    dp[0][0] = d[0];
    dp[1][0] = d[1];
    dp[1][1] = d[0] + d[1];

    int res = 0;
    for(int i = 2; i< n ; i++)
    {
        for(int len = 0 ; len <= min(i,k-1) ; len++)
        {
            dp[i][len] = 0;
            if(!valid(i,len))   continue;

            dp[i][len] = d[i] + max(
                dp[i-1][len-1],
                dp[i-2][len-1]
            );
            res = max(res, dp[i][len]);
        }
    }

    cout << res << endl;
    return 0;   
}