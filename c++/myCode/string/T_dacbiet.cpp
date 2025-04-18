#include<iostream>
using namespace std;

bool isPalindrome(string s)
{
    if(s.length() == 1) return true;
    int l = 0, r = s.length() -1;
    while(l < r) if(s[l++] != s[r--]) return false;
    return true;
}

bool nearPalin(string s)
{
    if(s.length() <= 3 && s.length() != 2) return true;
    if(isPalindrome(s))
    {
        if(s.length()%2 == 0) return false;
        else return true;
    }
    string queu = s;
    string ori = s;
    for(int i= 0 ; i < s.length() ; i++)
    {
        for(char c : queu)
        {
            s[i] = c;
            if(isPalindrome(s)) return true;
        }
        s = ori;
    }
    return false;
}

int c_nearPalin(string s)
{
    int cnt = 0;
    for (int k= 1 ; k <=s.length() ; k++)
    {
        for(int i=0 ; i<s.length() - k + 1; i++)
        {
            if(nearPalin(s.substr(i,k))){ 
                cnt++;
                //cout << s.substr(i,k) << endl;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s = "aabbcc";
    // ??? du ma m git
    cout << c_nearPalin(s);

    return 0;
}