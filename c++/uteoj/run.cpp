#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        double r = (double)x, l = 0;
        double mid = (l-r)/2+r;
        while(abs(mid*mid -  x) > 0.1)
        {
            mid = (l-r)/2+r;
            if(mid*mid < x)
                r = mid;
            else if(mid * mid > x)
                l = mid;
            else return floor(mid);
        }
        return floor(mid);
    }
};

int main()
{
    Solution s1;
    cout << s1.mySqrt(8);
    return 0;
}