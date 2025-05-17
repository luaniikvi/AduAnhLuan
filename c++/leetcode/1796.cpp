#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int secondHighest(string se) {
            set<int> nums;
            for(char c : se)
                if(isdigit(c)) nums.insert(c-'0');
            int f = 0,s = 0;
            for(auto num : nums)
                f = max(f,num);
            for(auto num : nums)
            {
                if(num == f) continue;
                s = max(s,num);
            }
            return s;
        }
    };