#include<iostream>
#include<vector>
#include<climits>
#define lli long long int
#define ll long long
using namespace std;

lli maxTich(vector<ll> a);


int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll  &n : a) cin >> n;

    cout << maxTich(a);

    return 0;
}
auto _max(auto a,auto b)
{
    return (a > b ? a : b);
}

lli maxTich(vector<ll> a)
{
    lli Max = LONG_LONG_MIN;
    int size = a.size();
    for(int i= 0 ; i< size - 1 ; i++)
    {
        for(int j= i+1 ; j< size ; j++ )
        {
            Max = _max(Max,a[i]*a[j]);
        }
    }

    return Max;
}