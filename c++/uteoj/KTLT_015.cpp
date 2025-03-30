#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;cin >> n;
    vector<long> a;
    for(long in,i=0 ; i<n; i++)
    {
        cin >> in;
        if(a.empty() || in > a.back())
            a.push_back(in);
        else 
        {
            int pos = *lower_bound(a.begin(),a.end(),in);
            a[pos] = in;
        }

    }
    cout << a.size();

    return 0;
}