#include "_lib.h"
class Solution {
    public:
        int climbStairs(int n) {
            vector<int> dp(n+1, 0);
            for(int i=0 ; i<= min(3,n); i ++) dp[i] = i;
            for(int i=4; i<=n ; i++)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
    
        }
    };