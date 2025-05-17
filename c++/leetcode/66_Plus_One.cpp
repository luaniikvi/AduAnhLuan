#include"_lib.h"

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> plus;
            int n = digits.size();
            //reverse(digits.begin(), digits.end());
            digits[n-1]+=1;
            for(int i = n-1 ; i>=0; i--)
            {
                if(digits[i] < 10) plus.push_back(digits[i]);
                else 
                {
                    plus.push_back(0);
                    if(i == 0) plus.push_back(1);
                    else digits[i-1]++;
                }
            }
            reverse(plus.begin(), plus.end());
            return plus;
        }
    };