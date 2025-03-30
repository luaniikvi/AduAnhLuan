#include<iostream>
#include<vector>
using namespace std;
string check(vector<string> s1, int n, vector<string> s2, int m)
{
    if(s1 == s2) return "YES";
    int i=0,j=0;
    while(i < n && j < m)
    {
        if(s1[i] == s2[j]) j++;
        i++;
    }
    if( j == m ) return "YES";
    return "NO";
}
int main()
{
    int n,m; cin >> n >> m;
    vector<string> s1(n);
    vector<string> s2(m);

    for(auto &i : s1) cin >> i;
    for(auto &i : s2) cin >> i;

    cout << check(s1,n,s2,m);

    return 0;
}