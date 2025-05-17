class Solution {
    public:
        int mySqrt(int x) {
            int ans = 0;
            int low=0 , high=x , mid = 0;
    
            while(low <= high)
            {
                mid = (low-high)/2+high;
                if(1LL*mid*mid <= x)
                    low = mid + 1,ans = mid;
                else 
                    high = mid - 1;
            }
            return ans;
        }
    };