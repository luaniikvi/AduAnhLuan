#include "_lib.h"
class Solution {
    public:
        char to_lower(char c)
        {
            if(c >= 'a') return c;
            else return c + ('a'-'A');
        }
        bool isPalindrome(string str) {
            string s = "";
            for(auto c : str)
                if(isalpha(c)) s+=to_lower(c);
                else if(isdigit(c)) s+= c;
            int i=0 , j = s.length()-1;
            while(i<j)
            {
                if(s[i] != s[j]) return false;
                i++;j--;
            }
            return true;
        }
    };