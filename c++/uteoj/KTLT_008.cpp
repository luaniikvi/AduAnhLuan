#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<long ,int> m;
    int Max = 0;
    for(long i = 0 ; i < n ; i++)
    {
        long l , r;
        cin >> l >> r;
        m[l]++;
        m[r+1]--;
    }
}