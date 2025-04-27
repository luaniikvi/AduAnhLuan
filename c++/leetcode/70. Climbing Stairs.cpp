#include "_lib.h"
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        for(int i=0 ; i<= min(3,n); i ++) dp[i] = i; //  base case
        for(int i=4; i<=n ; i++)    dp[i] = dp[i-1] + dp[i-2];
        return dp[n];   
    }
};

class Solution2 {
    public:
    int dp[46]={0};
    int climbStairs(int n) {
        if (n<=2) 
            return n;

        if (dp[n]!=0) 
            return dp[n];
            
        return dp[n]=climbStairs(n-1)+climbStairs(n-2); 
    }
};