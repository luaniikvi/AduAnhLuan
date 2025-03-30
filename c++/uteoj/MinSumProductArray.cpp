#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long n;cin >> n;
    vector<long> a(n);
    vector<long> b(n);

    for(long &num : a) cin >> num;
    for(long &num : b) cin >> num;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());

    long long int total = 0;
    for(long i=0 ; i<n ; i++)
        total += a[i]*b[i];

    cout << total << endl;
    return 0;
}