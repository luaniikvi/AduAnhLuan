#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0],last = strs.back();
        string ans = "";

        for(int i=0 ; i< min(first.length(), last.length()) ; i++)
        {
            if(first[i] != last[i])
            {
                return ans;
            }
            ans+=first[i];
        } 
        return ans;
    }
};