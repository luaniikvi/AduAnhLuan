#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    vector<ll> tails(n);
    ll len = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (len == 0 || arr[i] > tails[len - 1])
        {
            tails[len] = arr[i];
            len++;
        }
        else
        {
            ll index = lower_bound(tails.begin(), tails.begin() + len, arr[i]) - tails.begin();
            tails[index] = arr[i];
        }
    }

    cout << len << endl;

    return 0;
}