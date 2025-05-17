#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long pow(int base, int _p)
{
    if(_p == 0) return 1LL;
    return 1LL*base*pow(base,_p-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<int> r(n);
    for(auto &i : r) cin >> i;

    sort(r.begin(),r.end(),greater<int>());
    long long int cost = 0;

    for(int i=0 ; i<n ; i++)
    {
        cost += 100*pow(r[i],i+1);
    }
    cout << cost;

    return 0;
}