#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long n; cin >> n;
    vector<long long> a(n);
    for(auto &num : a) cin >> num;

    sort(a.begin(),a.end());
    long long median = a[n/2];

    long step =0;
    for(auto num : a)
        step+= abs(num - median);

    cout << step;
    return 0;
}