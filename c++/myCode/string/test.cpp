#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string s = "abcde";
    int k = s.length();
    for(int k=1 ; k<=s.length() ; k++)
    {
        for(int i=0 ; i<s.length() - k + 1; i++)
        {
            cout << s.substr(i,k) << ' ' << k<< endl;
        }
    }
    
    
    return 0;
}